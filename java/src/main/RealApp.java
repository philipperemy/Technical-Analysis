package main;

import indicators.movingaverage.MovingAverage;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
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

    public static void main(String[] args) throws IOException
    {

        TimeSeries in = readFile("files/sequences.txt");

        if (in == null)
        {
            throw new RuntimeException("Cannot read from file.");
        }

        List<TimeSeriesPair> tspList = new ArrayList<>();
        tspList.add(new TimeSeriesPair(MovingAverage.ma(in.toArray(), 20, MAType.Sma), MovingAverage.ma(in.toArray(), 50, MAType.Sma)));
        tspList.add(new TimeSeriesPair(MovingAverage.ma(in.toArray(), 20, MAType.Sma), MovingAverage.ma(in.toArray(), 100, MAType.Sma)));
        // tspList.add(new TimeSeriesPair(MovingAverage.ma(in.toArray(), 100, MAType.Sma), MovingAverage.ma(in.toArray(), 150, MAType.Sma)));
        StatefulRunner task = new StatefulRunner();
        task.setExpected(in);
        task.loadTimeSeries(tspList);
        task.run();
    }

    public static TimeSeries readFile(String filename)
    {
        TimeSeries priceCurveSeries = new TimeSeries();
        try
        {
            BufferedReader br = new BufferedReader(new FileReader(filename));
            String line = br.readLine();
            int i = 0;
            while (line != null)
            {
                priceCurveSeries.put(i++, Double.parseDouble(line));
                line = br.readLine();
            }
            br.close();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        return priceCurveSeries;
    }
}
