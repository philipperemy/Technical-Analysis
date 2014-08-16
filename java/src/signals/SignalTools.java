package signals;

import java.util.List;
import series.Interval;
import series.PartitionHelper;

public class SignalTools
{
    public static class TypeStructCounter
    {
        public int upCount   = 0;
        public int downCount = 0;

        public TypeStructCounter(int upCount, int downCount)
        {
            this.upCount = upCount;
            this.downCount = downCount;
        }
    }

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

    public static TypeStructCounter countType(List<Signal> signals)
    {
        int up = 0;
        int down = 0;
        for (Signal signal : signals)
        {
            switch (signal.signalType)
            {
                case UP:
                    up++;
                    break;

                case DOWN:
                    down++;
                    break;

                default:
                    throw new IllegalArgumentException();
            }
        }

        return new TypeStructCounter(up, down);
    }
}
