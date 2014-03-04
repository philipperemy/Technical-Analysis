package main;

import indicators.movingaverage.MovingAverage;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import com.tictactec.ta.lib.MAType;
import runner.AbstractRunner;
import runner.StatefulRunner;
import series.TimeSeries;
import series.TimeSeriesGenerator;
import series.TimeSeriesPair;

public class RealApp
{
    static int MAX = 4096;
    
    public static void main(String[] args) throws FileNotFoundException
    {
        TimeSeries in = TimeSeriesGenerator.getRandomTimeSeries(MAX);
        
        List<TimeSeriesPair> tspList = new ArrayList<>();
        tspList.add(new TimeSeriesPair(MovingAverage.ma(in.toArray(), 20, MAType.Sma), MovingAverage.ma(in.toArray(), 50, MAType.Sma)));
        tspList.add(new TimeSeriesPair(MovingAverage.ma(in.toArray(), 50, MAType.Sma), MovingAverage.ma(in.toArray(), 100, MAType.Sma)));
        tspList.add(new TimeSeriesPair(MovingAverage.ma(in.toArray(), 100, MAType.Sma), MovingAverage.ma(in.toArray(), 150, MAType.Sma)));
        
        AbstractRunner task = new StatefulRunner();
        task.loadTimeSeries(tspList);
        task.run();
        
    }
}
