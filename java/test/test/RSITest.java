package test;

import java.util.List;
import indicators.momentum.RelativeStrengthIndex;
import org.junit.Test;
import parser.CSVParser;
import runner.Runner;
import series.TimeSeries;
import series.TimeSeriesPair;

public class RSITest
{
    @Test
    public void rsi_test()
    {
        double[] in = new double[1000];

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
        TimeSeries RSI_7 = RelativeStrengthIndex.rsi(in, 7);
        TimeSeries RSI_14 = RelativeStrengthIndex.rsi(in, 14);

        Runner runner = new Runner();
        TimeSeriesPair tsp1 = new TimeSeriesPair(RSI_7, RSI_14);
        runner.loadTimeSeries(new TimeSeries(in), tsp1);
        runner.run();
    }

    @Test
    public void test_real_world()
    {
        CSVParser csvParser = new CSVParser("files/Cotations20130605.txt");
        List<String> closePrices = csvParser.values();

        double[] in = new double[closePrices.size()];
        int count = 0;
        for (String closePrice : closePrices)
        {
            in[count++] = Double.parseDouble(closePrice);
        }
        TimeSeries RSI_7 = RelativeStrengthIndex.rsi(in, 7);
        TimeSeries RSI_14 = RelativeStrengthIndex.rsi(in, 14);

        Runner runner = new Runner();
        TimeSeriesPair tsp1 = new TimeSeriesPair(RSI_7, RSI_14);
        runner.loadTimeSeries(new TimeSeries(in), tsp1);
        runner.run();
    }

    @Test
    public void test_real_world_2()
    {
        CSVParser csvParser = new CSVParser("files/Cotations20130605.txt");
        List<String> closePrices = csvParser.values();

        double[] in = new double[closePrices.size()];
        int count = 0;
        for (String closePrice : closePrices)
        {
            in[count++] = Double.parseDouble(closePrice);
        }
        TimeSeries RSI_7 = RelativeStrengthIndex.rsi(in, 7);
        TimeSeries RSI_14 = RelativeStrengthIndex.rsi(in, 14);

        Runner runner = new Runner();
        TimeSeriesPair tsp1 = new TimeSeriesPair(RSI_7, RSI_14);
        runner.loadTimeSeries(new TimeSeries(in), tsp1);
        runner.run();
    }
}
