package series;

import java.util.List;
import signals.Signal;

public class PartitionHelper
{
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
            Interval interval = new Interval(s1.time_AxisX, s2.time_AxisX);
            partition.add(interval);
            s1 = s2;
        }

        return partition;
    }

    public static IntervalPartition getSmallestPartition(List<IntervalPartition> partitions)
    {
        // TODO check if the start have to be 0.
        IntervalPartition retPartition = new IntervalPartition();
        int tmax = 0;
        for (IntervalPartition partition : partitions)
        {
            for (int i : partition.getLimitPoints())
            {
                if (i > tmax)
                {
                    tmax = i;
                }
            }
        }

        int t1 = 0;
        for (int t = 0; t < tmax; t++)
        {
            //For a current t, if a partition has a limit point here, there is another interval to build.
            Integer t2 = null;
            for (IntervalPartition partition : partitions)
            {
                if(partition.getLimitPoints().contains(t))
                {
                    t2 = t;
                    break;
                }
            }

            if (t2 != null)
            {
                retPartition.add(new Interval(t1, t2));
                
                t1 = t2;
                t2 = null;
            }
        }

        return retPartition;
    }
}
