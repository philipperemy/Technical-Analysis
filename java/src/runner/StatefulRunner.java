package runner;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import series.Interval;
import series.IntervalPartition;
import series.PartitionHelper;
import series.TimeSeries;
import series.TimeSeriesPair;
import signals.Signal;
import signals.Signal.Type;
import signals.SignalFactory;
import signals.SignalHelper;
import accuracy.AccuracyFunction;
import accuracy.AggregateAccuracyFunction;
import accuracy.SimpleAccuracyFunction;
import accuracy.SimpleAggregateAccuracyFunction;

public class StatefulRunner implements Runnable
{
    private TimeSeries                        priceCurveSeries;

    private List<TimeSeriesPair>              timeSeriesPairs = new ArrayList<>();

    private Map<TimeSeriesPair, List<Signal>> signalMap       = new LinkedHashMap<>();

    private IntervalPartition                 smallestPartition;

    private AccuracyFunction                  f               = new SimpleAccuracyFunction();
    private AggregateAccuracyFunction         a               = new SimpleAggregateAccuracyFunction();

    public void setExpected(TimeSeries timeSeries)
    {
        priceCurveSeries = timeSeries;
    }

    @Override
    public void run()
    {
        System.out.println("Compute signals...");
        computeSignals();
        System.out.println("Compute smallest partition...");
        computeSmallestPartition();
        System.out.println("Cross signals...");
        Map<Interval, List<Signal>> actualSignalsMap = crossSignals();
        
        System.out.println("Expected signals retrieval...");
        Map<Interval, Signal> expectedSignalMap = getExpectedSignalMap(actualSignalsMap.keySet());

        System.out.println("Compute accuracy of the model...");
        List<Double> accuracyList = computeAccuracy(actualSignalsMap, expectedSignalMap);
        System.out.println("model accuracy : " + a.aggregate(accuracyList));
    }

    private Map<Interval, Signal> getExpectedSignalMap(Set<Interval> intervals)
    {
        Map<Interval, Signal> expectedSignalMap = new LinkedHashMap<>();
        for (Interval interval : intervals)
        {
            Double openPrice = priceCurveSeries.get(interval.tmin);
            Double closePrice = priceCurveSeries.get(interval.tmax);

            if (openPrice == null || closePrice == null)
            {
                throw new RuntimeException("Out of range.");
            }

            Signal signal = new Signal();
            if (closePrice > openPrice)
            {
                signal.signalType = Type.UP;
            }
            else
            {
                signal.signalType = Type.DOWN;
            }

            expectedSignalMap.put(interval, signal);
        }
        return expectedSignalMap;
    }

    public void setErrorFunction(AccuracyFunction f)
    {
        this.f = f;
    }

    private List<Double> computeAccuracy(Map<Interval, List<Signal>> actualSignalsMap, Map<Interval, Signal> expectedSignalMap)
    {
        if (actualSignalsMap.size() != expectedSignalMap.size())
        {
            throw new RuntimeException("Cannot compute. Size are different");
        }

        if (!actualSignalsMap.keySet().containsAll(expectedSignalMap.keySet()))
        {
            throw new RuntimeException("Intervals are not the same!");
        }

        List<Double> accuracyList = new ArrayList<>();
        for (Entry<Interval, List<Signal>> entry : actualSignalsMap.entrySet())
        {
            Interval interval = entry.getKey();
            Signal expectedSignals = expectedSignalMap.get(interval);
            List<Signal> actualSignals = entry.getValue();
            System.out.println("________________");
            double accuracy = f.accuracy(actualSignals, expectedSignals);
            System.out.println("acc = " + accuracy);
            System.out.println("I = " + interval);
            System.out.println("________________");
            accuracyList.add(accuracy);
        }

        if (accuracyList.size() != actualSignalsMap.size())
        {
            throw new RuntimeException("Error happened during accuracy computation");
        }

        return accuracyList;
    }

    public void loadTimeSeries(List<TimeSeriesPair> tspList)
    {
        for (TimeSeriesPair tsp : tspList)
        {
            System.out.println(tsp);
        }
        timeSeriesPairs.addAll(tspList);
    }

    private void computeSignals()
    {
        for (TimeSeriesPair tsp : timeSeriesPairs)
        {
            List<Signal> signals = SignalFactory.processTimeSeries_E(tsp);
            signalMap.put(tsp, signals);
        }
    }

    private List<Signal> getSignals()
    {
        List<Signal> signals = new ArrayList<>();
        for (List<Signal> list : signalMap.values())
        {
            signals.addAll(list);
        }
        return signals;
    }

    private void computeSmallestPartition()
    {
        List<IntervalPartition> partitions = new ArrayList<>();
        for (List<Signal> signals : signalMap.values())
        {
            IntervalPartition partition = PartitionHelper.getPartition(signals);
            partition.checkValidity_ThrowException();
            partitions.add(partition);
        }

        smallestPartition = PartitionHelper.getSmallestPartition(partitions);
    }

    private Map<Interval, List<Signal>> crossSignals()
    {
        Map<Interval, List<Signal>> crossSignalsMap = new LinkedHashMap<>();
        /*
         * for (Signal signal : getSignals())
         * {
         * System.out.println(signal);
         * }
         */

        if (smallestPartition != null)
        {
            for (Interval interval : smallestPartition.intervals())
            {
                // System.out.print(interval);
                for (Signal signal : getSignals())
                {
                    if (SignalHelper.signalContainedInInterval(signal, interval))
                    {
                        List<Signal> signals = crossSignalsMap.get(interval);
                        if (signals == null)
                        {
                            crossSignalsMap.put(interval, new ArrayList<Signal>());
                        }

                        crossSignalsMap.get(interval).add(signal);

                        // System.out.print(" {" + signal.signalType + ", r=" + signal.t1.getId() + ", s=" + signal.t2.getId() + "}");
                    }
                }
                // System.out.println();
            }
        }

        return crossSignalsMap;
    }

}
