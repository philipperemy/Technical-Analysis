package signals;

import java.util.ArrayList;
import java.util.List;
import series.TimeSeries;
import signals.Signal.Type;

public class SignalFactory
{
    public static List<Signal> processTimeSeries_E(TimeSeries ts1, TimeSeries ts2)
    {
        List<Signal> signals = processTimeSeries(ts1, ts2);

        // Do not take the last one.
        for (int i = 0; i < signals.size() - 1; i++)
        {
            signals.get(i).time_end = signals.get(i + 1).time_start;
        }

        return signals;
    }

    public static List<Signal> processTimeSeries(TimeSeries ts1, TimeSeries ts2)
    {
        // TODO: check bounds. This is a first attempt.
        List<Signal> signals = new ArrayList<>();
        for (int i = 1; i < ts1.size(); i++)
        {
            if ((ts1.get(i) > ts2.get(i)) && (ts1.get(i - 1) < ts2.get(i - 1)))
            {
                signals.add(new Signal(ts1, ts2, Type.UP, i));
            }

            if ((ts1.get(i) < ts2.get(i)) && (ts1.get(i - 1) > ts2.get(i - 1)))
            {
                signals.add(new Signal(ts1, ts2, Type.DOWN, i));
            }
        }
        return signals;
    }
}
