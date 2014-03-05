package accuracy;

import java.util.List;
import signals.Signal;

public class SimpleAccuracyFunction implements AccuracyFunction
{
    @Override
    public double accuracy(List<Signal> actualSignals, Signal expectedSignal)
    {
        int bullish = 0;
        int bearish = 0;
        System.out.print("actual = { ");
        for (Signal actualSignal : actualSignals)
        {
            System.out.print(actualSignal + ", ");
            switch (actualSignal.signalType)
            {
                case UP:
                    bullish++;
                    break;

                case DOWN:
                    bearish++;
                    break;

                default:
                    throw new IllegalArgumentException();
            }
        }

        double accuracy = 0;
        System.out.print("}, expected = " + expectedSignal.signalType);
        switch (expectedSignal.signalType)
        {
            case UP:
                accuracy = ((double) bullish) / (bullish + bearish);
                break;

            case DOWN:
                accuracy = ((double) bearish) / (bullish + bearish);
                break;

            default:
                throw new IllegalArgumentException();
        }

        System.out.println();
        return accuracy;
    }

}
