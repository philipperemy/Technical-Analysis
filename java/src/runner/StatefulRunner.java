package runner;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import series.Interval;
import series.IntervalPartition;
import series.PartitionHelper;
import series.TimeSeries;
import series.TimeSeriesPair;
import signals.Signal;
import signals.SignalFactory;
import signals.SignalHelper;

public class StatefulRunner implements AbstractRunner
{
    @SuppressWarnings("unused")
    private TimeSeries                        priceCurveSeries;

    private List<TimeSeriesPair>              timeSeriesPairs = new ArrayList<>();

    // No need to refine hashCode and equals
    private Map<TimeSeriesPair, List<Signal>> signalMap       = new HashMap<>();

    private IntervalPartition                 smallestPartition;

    @Override
    public void run()
    {
        computeSignals();
        computeSmallestPartition();
        crossSignals();
    }

    @Override
    public void readFile(String path)
    {

    }

    @Override
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

    private void crossSignals()
    {
        for (Signal signal : getSignals())
        {
            System.out.println(signal);
        }

        if (smallestPartition != null)
        {
            for (Interval interval : smallestPartition.intervals())
            {
                System.out.print(interval);
                for (Signal signal : getSignals())
                {
                    if (SignalHelper.signalContainedInInterval(signal, interval))
                    {
                        System.out.print(" {" + signal.signalType + ", r=" + signal.t1.getId() + ", s=" + signal.t2.getId() + "}");
                    }
                }
                
                System.out.println();
            }
        }
    }

}
