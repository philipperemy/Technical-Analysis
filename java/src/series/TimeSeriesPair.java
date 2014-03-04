package series;

public class TimeSeriesPair
{
    public TimeSeries referenceTS;
    public TimeSeries secondaryTS;

    public TimeSeriesPair()
    {

    }

    @Override
    public String toString()
    {
        StringBuilder sBuilder = new StringBuilder();
        for (int i = 0; i < referenceTS.size(); i++)
        {
            sBuilder.append("i=" + i + ", " + referenceTS.get(i) + ", " + secondaryTS.get(i));
            sBuilder.append(System.getProperty("line.separator"));
        }

        return sBuilder.toString();
    }

    public TimeSeriesPair(TimeSeries refTS, TimeSeries secondaryTS)
    {
        this.referenceTS = refTS;
        this.secondaryTS = secondaryTS;
    }
}
