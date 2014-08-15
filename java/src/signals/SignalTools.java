package signals;

import series.Interval;
import series.PartitionHelper;

public class SignalTools
{
    public static boolean signalContainedInInterval(Signal signal, Interval interval)
    {
        if (signal.time_end == Signal.NO_END)
        {
            return signal.time_start <= interval.tmin;
        }
        else if (interval.tmax != PartitionHelper.INFINITY)
        {
            return (signal.time_start <= interval.tmin) && (interval.tmax <= signal.time_end);
        }
        else
        {
            return false;
        }
    }
}
