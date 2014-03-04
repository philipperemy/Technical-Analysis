package main;

import indicators.movingaverage.MovingAverage;
import java.io.FileNotFoundException;
import java.util.ArrayList;
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

public class App
{
    static List<Signal> _signals = new ArrayList<>();
    static int MAX = 512;

    public static void main(String[] args) throws FileNotFoundException
    {
        TimeSeries in = TimeSeriesGenerator.getRandomTimeSeries(MAX);

        List<IntervalPartition> partitionList = new ArrayList<>();
        partitionList.add(getP1(in));
        partitionList.add(getP2(in));

        IntervalPartition partition = PartitionHelper.getSmallestPartition(partitionList);
        partition.checkValidity_ThrowException();
        System.out.println(partition);
        
        for(Signal signal : _signals)
        {
            System.out.println(signal);
        }

        for (Interval interval : partition.intervals())
        {
            System.out.print(interval);
            for (Signal signal : _signals)
            {
                if (SignalHelper.signalContainedInInterval(signal, interval))
                {
                    System.out.print(" " + signal.signalType);
                }
            }
            System.out.println();
        }
    }

    public static IntervalPartition getP2(TimeSeries in)
    {
        TimeSeries sma1 = MovingAverage.ma(in.toArray(), 4, MAType.Sma);
        TimeSeries sma2 = MovingAverage.ma(in.toArray(), 8, MAType.Sma);

        List<Signal> signals = SignalFactory.processTimeSeries_E(sma1, sma2);
        _signals.addAll(signals);

        IntervalPartition partition = PartitionHelper.getPartition(signals);
        System.out.println(partition.toString());
        partition.checkValidity_ThrowException();

        for (int i = 0; i < MAX; i++)
        {
            // System.out.println("[ t=" + i + ", in=" + in.get(i) + ", sma1=" + sma1.get(i) + ", sma2= " + sma2.get(i) + " ]");
            // System.out.println(i + "," + in.get(i) + "," + sma1.get(i) + "," + sma2.get(i));
        }

        return partition;
    }

    public static IntervalPartition getP1(TimeSeries in)
    {
        TimeSeries sma1 = MovingAverage.ma(in.toArray(), 2, MAType.Sma);
        TimeSeries sma2 = MovingAverage.ma(in.toArray(), 3, MAType.Sma);

        List<Signal> signals = SignalFactory.processTimeSeries_E(sma1, sma2);
        _signals.addAll(signals);

        IntervalPartition partition = PartitionHelper.getPartition(signals);
        System.out.println(partition.toString());
        partition.checkValidity_ThrowException();

        for (int i = 0; i < MAX; i++)
        {
            System.out.println("[ t=" + i + ", in=" + in.get(i) + ", sma1=" + sma1.get(i) + ", sma2= " + sma2.get(i) + " ]");
            // System.out.println(i + "," + in.get(i) + "," + sma1.get(i) + "," + sma2.get(i));
        }

        return partition;
    }
}
