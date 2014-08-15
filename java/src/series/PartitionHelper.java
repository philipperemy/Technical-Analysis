package series;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;
import signals.Signal;

public class PartitionHelper
{
    public static final int INFINITY = -1;

    public static IntervalPartition getPartition(List<Signal> signals)
    {
        if (signals.size() <= 1)
        {
            throw new RuntimeException("too few signals to make a partition");
        }

        IntervalPartition partition = new IntervalPartition();

        Signal s1 = signals.get(0);
        for (int i = 1; i < signals.size(); i++)
        {
            Signal s2 = signals.get(i);
            Interval interval = new Interval(s1.time_start, s2.time_start);
            partition.add(interval);
            s1 = s2;
        }

        // last interval
        if (s1.time_end == 0)
        {
            // -1 represents +infinity
            partition.add(new Interval(s1.time_start, INFINITY));
        }

        return partition;
    }

    public static IntervalPartition getSmallestPartition(IntervalPartition... intervalPartitions)
    {
        return getSmallestPartition(Arrays.asList(intervalPartitions));
    }

    public static IntervalPartition getSmallestPartition(List<IntervalPartition> partitions)
    {
        IntervalPartition retPartition = new IntervalPartition();
        Set<Integer> limitPoints = new TreeSet<>();
        for (IntervalPartition partition : partitions)
        {
            limitPoints.addAll(partition.getLimitPoints());
        }

        boolean containsInfinity = limitPoints.contains(INFINITY);
        if (containsInfinity)
        {
            limitPoints.remove(INFINITY);
        }

        List<Integer> list = new ArrayList<Integer>(limitPoints);
        for (int i = 1; i < list.size(); i++)
        {
            retPartition.add(new Interval(list.get(i - 1), list.get(i)));
        }
        
        if(containsInfinity)
        {
            retPartition.add(new Interval(list.get(list.size()-1), INFINITY));
        }

        return retPartition;
    }

}
