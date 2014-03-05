package main;

import indicators.movingaverage.MovingAverage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import runner.StatefulRunner;
import series.TimeSeries;
import series.TimeSeriesPair;
import com.tictactec.ta.lib.MAType;

public class RealApp
{
    static int MAX = 4096;

    // TimeSeries timeSeries = TimeSeriesGenerator.getRandomTimeSeries(10000000);
    // TimeSeriesGenerator.write("files/sequences.txt", timeSeries);

    public static void main(String[] args) throws IOException
    {

        TimeSeries in = readFile("files/sequences.txt");
        List<TimeSeriesPair> tspList = new ArrayList<>();
        tspList.add(new TimeSeriesPair(MovingAverage.ma(in.toArray(), 20, MAType.Sma), MovingAverage.ma(in.toArray(), 50, MAType.Sma)));
        tspList.add(new TimeSeriesPair(MovingAverage.ma(in.toArray(), 20, MAType.Sma), MovingAverage.ma(in.toArray(), 100, MAType.Sma)));
        // tspList.add(new TimeSeriesPair(MovingAverage.ma(in.toArray(), 100, MAType.Sma), MovingAverage.ma(in.toArray(), 150, MAType.Sma)));
        StatefulRunner task = new StatefulRunner();
        task.setExpected(in);
        task.loadTimeSeries(tspList);
        task.run();
    }

    public static TimeSeries readFile(String path)
    {
        TimeSeries priceCurveSeries = new TimeSeries();
        try
        {
            Scanner scanner = new Scanner(new File(path));
            int i = 0;
            while (scanner.hasNextDouble())
            {
                priceCurveSeries.put(i++, (double) scanner.nextDouble());
            }

            scanner.close();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }

        return priceCurveSeries;
    }
}
