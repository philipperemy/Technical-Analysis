package signals;

import series.Interval;

public class SignalHelper
{
    public static boolean signalContainedInInterval(Signal signal, Interval interval)
    {
        return (signal.time_start <= interval.tmin) && (interval.tmax <= signal.time_end) && signal.time_end != 0; // 0 = UNDEFINED
    }
}
