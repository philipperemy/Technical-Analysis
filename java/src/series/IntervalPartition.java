package series;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class IntervalPartition
{
    private List<Interval> intervals = new ArrayList<>();

    public void add(Interval interval)
    {
        intervals.add(interval);
        Collections.sort(intervals);
    }

    public List<Interval> intervals()
    {
        return intervals;
    }

    public int size()
    {
        return intervals.size();
    }

    Set<Integer> getLimitPoints()
    {
        Set<Integer> limitPoints = new HashSet<>();
        for (Interval interval : intervals)
        {
            limitPoints.add(interval.tmin);
            limitPoints.add(interval.tmax);
        }
        return limitPoints;
    }

    @Override
    public String toString()
    {
        StringBuilder sBuilder = new StringBuilder();
        for (Interval interval : intervals)
        {
            sBuilder.append(interval.toString());
            sBuilder.append(System.getProperty("line.separator"));
        }
        return sBuilder.toString();
    }

    public void checkValidity_ThrowException()
    {
        for (int t = intervals.get(0).tmin; t < intervals.get(intervals.size() - 1).tmax; t++)
        {
            boolean contained = false;
            for (Interval i : intervals)
            {
                if (i.contains(t))
                {
                    if (contained)
                    {
                        throw new RuntimeException("Crossovers on intervals within the partition.");
                    }
                    else
                    {
                        contained = true;
                    }
                }
            }

            if (!contained)
            {
                throw new RuntimeException("Partition is not complete. t=" + t);
            }
        }
    }

}
