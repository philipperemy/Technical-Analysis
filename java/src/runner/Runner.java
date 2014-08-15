package runner;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import accuracy.ModelAccuracyTools;
import series.Interval;
import series.IntervalPartition;
import series.PartitionHelper;
import series.TimeSeries;
import series.TimeSeriesPair;
import signals.Signal;
import signals.SignalFactory;
import signals.SignalTools;

public class Runner implements Runnable
{
    public TimeSeries                  priceCurveSeries;
    public List<TimeSeriesPair>        timeSeriesPairs = new ArrayList<>();
    public List<Signal>                signals         = new ArrayList<>();
    public IntervalPartition           intervalPartition;
    public Map<Interval, List<Signal>> crossSignalsMap = new LinkedHashMap<>();

    @Override
    public void run()
    {
        System.out.println("Compute signals...");
        computeSignals();
        System.out.println("Compute smallest partition...");
        computeSmallestPartition();
        System.out.println("Cross signals...");
        crossSignals();
        System.out.println("Compute accuracy...");
        System.out.println("OVERALL ACCURACY : " + computeAccuracy());
    }

    private double computeAccuracy()
    {
        return ModelAccuracyTools.computeAccuracy(crossSignalsMap, getExpectedSignalMap());
    }

    private Map<Interval, Signal> getExpectedSignalMap()
    {
        Map<Interval, Signal> expectedSignalMap = new LinkedHashMap<>();
        for (Interval interval : intervalPartition.intervals())
        {
            Double openPrice = priceCurveSeries.get(interval.tmin);
            Double closePrice = (interval.tmax == PartitionHelper.INFINITY ? priceCurveSeries.get(priceCurveSeries.size() - 1) : priceCurveSeries.get(interval.tmax));

            if (openPrice == null || closePrice == null)
            {
                throw new RuntimeException("Out of range.");
            }

            Signal signal = new Signal();
            if (closePrice > openPrice)
            {
                signal.signalType = Signal.Type.UP;
            }
            else
            {
                signal.signalType = Signal.Type.DOWN;
            }

            expectedSignalMap.put(interval, signal);
        }
        return expectedSignalMap;
    }

    public void loadTimeSeries(TimeSeries tsSeries, TimeSeriesPair... pairs)
    {
        priceCurveSeries = tsSeries;
        for (TimeSeriesPair tsp : pairs)
        {
            timeSeriesPairs.add(tsp);
        }
    }

    private void computeSignals()
    {
        for (TimeSeriesPair tsp : timeSeriesPairs)
        {
            List<Signal> signals = SignalFactory.processTimeSeries(tsp);
            System.out.println(tsp + " " + signals);
            this.signals.addAll(signals);
        }
    }

    private void computeSmallestPartition()
    {
        intervalPartition = PartitionHelper.getSmallestPartition(PartitionHelper.getPartition(signals));
    }

    private void crossSignals()
    {
        // interval 1
        for (Interval i : intervalPartition.intervals())
        {
            for (Signal signal : signals)
            {
                if (SignalTools.signalContainedInInterval(signal, i))
                {
                    List<Signal> signals = crossSignalsMap.get(i);
                    if (signals == null)
                    {
                        crossSignalsMap.put(i, new ArrayList<Signal>());
                    }

                    crossSignalsMap.get(i).add(signal);
                }
            }
        }
    }

    public void printCrossedSignals()
    {
        for (Entry<Interval, List<Signal>> entry : crossSignalsMap.entrySet())
        {
            System.out.println(entry.getKey());
            for (Signal signal : entry.getValue())
            {
                System.out.println("-> " + signal);
            }
            System.out.println();
        }
    }
}
