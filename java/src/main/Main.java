package main;

import generator.TimeSeriesGenerator;
import indicators.movingaverage.MovingAverage;
import java.io.FileNotFoundException;
import out.Out;
import com.tictactec.ta.lib.MAType;

public class Main
{

    public static void main(String[] args) throws FileNotFoundException
    {

        double[] in = TimeSeriesGenerator.getRandomTimeSeries(1024);
        Out sma1 = MovingAverage.ma(in, 10, MAType.Sma);
        for (int i = 0; i < sma1.size(); i++)
        {
            System.out.println(in[i] + ", " + sma1.get(i));
        }

    }
}
