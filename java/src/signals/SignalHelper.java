package signals;
import series.Interval;

public class SignalHelper
{
    public static boolean signalContainedInInterval(Signal signal, Interval interval)
    {
        return interval.contains(signal.time_AxisX);
    }
}
