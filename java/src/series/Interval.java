package series;

/**
 * All intervals are [tmin, tmax[ mainly because of partitions
 * The type of the interva is the type of tmin
 */
public class Interval implements Comparable<Interval>
{
    @Override
    public int hashCode()
    {
        final int prime = 3113;
        int result = 1;
        result = prime * result + tmax;
        result = prime * result + tmin;
        return result;
    }

    @Override
    public boolean equals(Object obj)
    {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Interval other = (Interval) obj;
        if (tmax != other.tmax)
            return false;
        if (tmin != other.tmin)
            return false;
        return true;
    }

    public int tmin;
    public int tmax;

    public Interval()
    {

    }

    // A priori pas besoin de hashCode et equals parce qu'on regarde directement les adresses memoires.

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
