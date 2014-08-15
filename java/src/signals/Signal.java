package signals;

import series.TimeSeries;

public class Signal
{
    public Signal()
    {
    }

    public Signal(TimeSeries t1, TimeSeries t2, Type type, int time_AxisX)
    {
        this.t1 = t1;
        this.t2 = t2;
        this.signalType = type;
        this.time_start = time_AxisX;
    }

    /**
     * This is the reference
     */
    public TimeSeries t1;

    /**
     * This is the confronted curve
     */
    public TimeSeries t2;

    public enum Type
    {
        UP, DOWN
    }

    /**
     * If t1 rises above t2, then type = UP
     * If t1 drops below t2, type = DOWN
     */
    //TODO: can be computed with ts1 and ts2 and time_start
    public Type signalType;

    /**
     * This is the time point where the signal appears
     */
    public int  time_start;

    /**
     * This is the end of the signal (i.e. where an opposite signal occurs).
     */
    public int  time_end = NO_END;
    
    public static final int NO_END = 0;

    @Override
    public String toString()
    {
        return "Signal [" + (t1 != null ? "t1=" + t1 + ", " : "") + (t2 != null ? "t2=" + t2 + ", " : "") + (signalType != null ? "signalType=" + signalType + ", " : "") + "time_start=" + time_start + ", time_end=" + (time_end == 0 ? "NO_END" : time_end) + "]";
    }

}
