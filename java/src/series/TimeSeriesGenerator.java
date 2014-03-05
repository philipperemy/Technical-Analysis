package series;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import java.util.Random;

public class TimeSeriesGenerator
{
    static Random random = new Random();

    public static TimeSeries getRandomTimeSeries(final int length)
    {
        double[] out = new double[length];
        out[0] = 100000;
        for (int i = 1; i < length; i++)
        {
            double addQty = 20 * random.nextDouble();
            if(random.nextBoolean())
            {
                out[i] = out[i - 1] + addQty;             
            }
            else
            {
                out[i] = out[i - 1] - addQty;
            }
        }

        return new TimeSeries(out);
    }

    public static void write(String path, TimeSeries ts) throws IOException
    {
        PrintWriter pw = new PrintWriter(path);
        for (int i = 0; i < ts.size(); i++)
        {
            pw.println(ts.get(i));
        }
        pw.close();
    }
}
