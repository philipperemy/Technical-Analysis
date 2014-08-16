package test;

import indicators.movingaverage.MovingAverage;
import org.junit.Test;
import runner.Runner;
import series.TimeSeries;
import series.TimeSeriesPair;
import com.tictactec.ta.lib.MAType;

public class TALibLoadTest
{

    @Test
    public void load_test()
    {
        double[] in = new double[100000];

        int c = 1;
        boolean upTrend = true;
        for (int i = 0; i < in.length; i++)
        {
            in[i] = c;

            if (c == 10)
            {
                upTrend = false;
            }

            if (c == 1)
            {
                upTrend = true;
            }

            if (upTrend)
            {
                c++;
            }
            else
            {
                c--;
            }

        }

        TimeSeries SMA_2 = MovingAverage.ma(in, 2, MAType.Sma);
        TimeSeries SMA_4 = MovingAverage.ma(in, 4, MAType.Sma);
        TimeSeries SMA_6 = MovingAverage.ma(in, 6, MAType.Sma);
        TimeSeries SMA_8 = MovingAverage.ma(in, 8, MAType.Sma);

        Runner runner = new Runner();
        TimeSeriesPair tsp1 = new TimeSeriesPair(SMA_2, SMA_4);
        TimeSeriesPair tsp2 = new TimeSeriesPair(SMA_6, SMA_8);
        runner.loadTimeSeries(new TimeSeries(in), tsp1, tsp2);
        runner.run();

    }
}
