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
        this.time_AxisX = time_AxisX;
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
    public Type signalType;

    /**
     * This is the time point where the signal appears
     */
    public int  time_AxisX;
}
