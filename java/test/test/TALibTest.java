package test;

import indicators.movingaverage.MovingAverage;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import org.junit.Assert;
import org.junit.Test;
import com.tictactec.ta.lib.MAType;
import runner.Runner;
import series.Interval;
import series.IntervalPartition;
import series.PartitionHelper;
import series.TimeSeries;
import series.TimeSeriesPair;
import signals.Signal;
import signals.SignalFactory;
import signals.SignalTools;

public class TALibTest
{
    static double[]   in    = new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    static TimeSeries SMA_2 = MovingAverage.ma(in, 2, MAType.Sma);
    static TimeSeries SMA_4 = MovingAverage.ma(in, 4, MAType.Sma);
    static TimeSeries SMA_6 = MovingAverage.ma(in, 6, MAType.Sma);
    static TimeSeries SMA_8 = MovingAverage.ma(in, 8, MAType.Sma);

    @Test
    public void interval_test()
    {
        Interval interval = new Interval();
        Assert.assertEquals(0, interval.tmin);
        Assert.assertEquals(0, interval.tmax);

        Interval interval2 = new Interval(0, 2);
        Interval interval3 = new Interval(0, 3);

        Assert.assertTrue(interval2.compareTo(interval3) == 0);

        Assert.assertTrue(interval2.contains(0));
        Assert.assertTrue(interval2.contains(1));
        Assert.assertFalse(interval2.contains(2));
    }
    
    @Test
    public void smoke_test_1()
    {
        List<Signal> signals = new ArrayList<>();

        List<Signal> signals_2_4 = SignalFactory.processTimeSeries(SMA_2, SMA_4);
        List<Signal> signals_6_8 = SignalFactory.processTimeSeries(SMA_6, SMA_8);

        signals.addAll(signals_2_4);
        signals.addAll(signals_6_8);

        IntervalPartition partition_2_4 = PartitionHelper.getPartition(signals_2_4);
        IntervalPartition partition_6_8 = PartitionHelper.getPartition(signals_6_8);

        partition_2_4.checkValidity_ThrowException();
        partition_6_8.checkValidity_ThrowException();

        IntervalPartition partition_2_4_6_8 = PartitionHelper.getSmallestPartition(partition_2_4, partition_6_8);

        partition_2_4_6_8.checkValidity_ThrowException();

        List<Interval> intervals = partition_2_4_6_8.intervals();
        assertSmokeTest(intervals, signals);
    }

    @Test
    public void smoke_test_2()
    {
        Runner runner = new Runner();
        TimeSeriesPair tsp1 = new TimeSeriesPair(SMA_2, SMA_4);
        TimeSeriesPair tsp2 = new TimeSeriesPair(SMA_6, SMA_8);
        runner.loadTimeSeries(tsp1, tsp2);
        runner.run();

        List<Interval> intervals = runner.intervalPartition.intervals();
        List<Signal> signals = runner.signals;

        assertSmokeTest(intervals, signals);
        
        Map<Interval, List<Signal>> crossedSignals = runner.crossSignalsMap;
        Assert.assertEquals(4, crossedSignals.size());
        runner.printCrossedSignals();
    }

    private void assertSmokeTest(List<Interval> intervals, List<Signal> signals)
    {
        Assert.assertEquals(4, intervals.size());

        // interval 1
        {
            Interval i = intervals.get(0);
            Assert.assertEquals(11, i.tmin);
            Assert.assertEquals(14, i.tmax);
            List<Signal> matchingSignals = new ArrayList<>();
            for (Signal signal : signals)
            {
                if (SignalTools.signalContainedInInterval(signal, i))
                {
                    matchingSignals.add(signal);
                }
            }
            Assert.assertEquals(1, matchingSignals.size());
            Signal s1 = matchingSignals.get(0);
            Assert.assertTrue(Signal.Type.DOWN == s1.signalType);
        }

        // interval 2
        {
            Interval i = intervals.get(1);
            Assert.assertEquals(14, i.tmin);
            Assert.assertEquals(20, i.tmax);
            List<Signal> matchingSignals = new ArrayList<>();
            for (Signal signal : signals)
            {
                if (SignalTools.signalContainedInInterval(signal, i))
                {
                    matchingSignals.add(signal);
                }
            }
            Assert.assertEquals(2, matchingSignals.size());
            Signal s1 = matchingSignals.get(0);
            Signal s2 = matchingSignals.get(0);
            Assert.assertTrue(Signal.Type.DOWN == s1.signalType);
            Assert.assertTrue(Signal.Type.DOWN == s2.signalType);
        }

        // interval 3
        {
            Interval i = intervals.get(2);
            Assert.assertEquals(20, i.tmin);
            Assert.assertEquals(23, i.tmax);
            List<Signal> matchingSignals = new ArrayList<>();
            for (Signal signal : signals)
            {
                if (SignalTools.signalContainedInInterval(signal, i))
                {
                    matchingSignals.add(signal);
                }
            }
            Assert.assertEquals(2, matchingSignals.size());
            Signal s1 = matchingSignals.get(0);
            Signal s2 = matchingSignals.get(1);
            Assert.assertTrue(Signal.Type.UP == s1.signalType);
            Assert.assertTrue(Signal.Type.DOWN == s2.signalType);
        }

        // interval 4
        {
            Interval i = intervals.get(3);
            Assert.assertEquals(23, i.tmin);
            Assert.assertEquals(-1, i.tmax);
            List<Signal> matchingSignals = new ArrayList<>();
            for (Signal signal : signals)
            {
                if (SignalTools.signalContainedInInterval(signal, i))
                {
                    matchingSignals.add(signal);
                }
            }
            Assert.assertEquals(2, matchingSignals.size());
            Signal s1 = matchingSignals.get(0);
            Signal s2 = matchingSignals.get(0);
            Assert.assertTrue(Signal.Type.UP == s1.signalType);
            Assert.assertTrue(Signal.Type.UP == s2.signalType);
        }
    }

}
