package main;

import indicators.movingaverage.MovingAverage;
import java.io.FileNotFoundException;
import java.util.List;
import series.Interval;
import series.IntervalPartition;
import series.PartitionHelper;
import series.TimeSeries;
import series.TimeSeriesGenerator;
import signals.Signal;
import signals.SignalFactory;
import signals.SignalHelper;
import com.tictactec.ta.lib.MAType;

public class AppDebug
{
    static int MAX = 512;

    public static void main(String[] args) throws FileNotFoundException, InterruptedException
    {
        TimeSeries in = TimeSeriesGenerator.getRandomTimeSeries(MAX);

        TimeSeries sma1 = MovingAverage.ma(in.toArray(), 2, MAType.Sma);
        TimeSeries sma2 = MovingAverage.ma(in.toArray(), 3, MAType.Sma);

        List<Signal> signals = SignalFactory.processTimeSeries_E(sma1, sma2);

        IntervalPartition partition = PartitionHelper.getPartition(signals);
        System.out.println(partition.toString());
        partition.checkValidity_ThrowException();

        for (int i = 0; i < MAX; i++)
        {
            System.out.println("[ t=" + i + ", in=" + in.get(i) + ", sma1=" + sma1.get(i) + ", sma2= " + sma2.get(i) + " ]");
        }

        partition.checkValidity_ThrowException();

        for (Signal signal : signals)
        {
            System.out.println(signal.toString());
        }

        // Sometimes UP followed by a UP. Fixed this case later.
        /**
         * Do something for this.
         */
        for (Interval interval : partition.intervals())
        {
            System.out.print(interval);
            for (Signal signal : signals)
            {
                if (SignalHelper.signalContainedInInterval(signal, interval))
                {
                    System.out.print(" " + signal.signalType);
                }
            }
            System.out.println();
        }

        System.out.println(signals.size());
    }

}
