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
        return "[" + referenceTS.getId() + "-" + secondaryTS.getId() + "]";
    }

    public String print()
    {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < referenceTS.size(); i++)
        {
            sb.append("i= " + i + ", " + referenceTS.get(i) + ", " + secondaryTS.get(i));
            sb.append(System.getProperty("line.separator"));
        }

        return sb.toString();
    }

    public TimeSeriesPair(TimeSeries refTS, TimeSeries secondaryTS)
    {
        this.referenceTS = refTS;
        this.secondaryTS = secondaryTS;
    }
}
