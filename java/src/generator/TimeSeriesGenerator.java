package generator;

public class TimeSeriesGenerator
{

    public static double[] getRandomTimeSeries(final int length)
    {
        final double[] out = new double[length];
        double high = 1000;
        double close = high - Math.random();
        double low = close - Math.random();
        double open = (high - low) * Math.random() + low;

        double oldOpen;
        int count = 0;

        for (int i = 0; i < length; i++)
        {

            high = open + Math.random();
            close = high - Math.random();
            low = close - Math.random();
            oldOpen = open;
            open = (high - low) * Math.random() + low;

            if (low > oldOpen)
            {
                low = oldOpen;
            }

            out[count++] = close;
        }

        return out;
    }

}
