package series;

/**
 * All intervals are [tmin, tmax[ mainly because of partitions
 * The type of the interva is the type of tmin
 */
public class Interval implements Comparable<Interval>
{
    public int tmin;
    public int tmax;

    public Interval()
    {

    }

    @Override
    public String toString()
    {
        return "[" + tmin + ", " + tmax + "[";
    }

    public Interval(int tmin, int tmax)
    {
        this.tmin = tmin;
        this.tmax = tmax;
    }

    public boolean contains(int t)
    {
        return (t >= tmin) && (t < tmax);
    }

    @Override
    public int compareTo(Interval i)
    {
        return tmin - i.tmin;
    }
}
