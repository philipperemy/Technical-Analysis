package accuracy;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import series.Interval;
import signals.Signal;
import evaluator.SignalsEvaluator;

public class ModelAccuracyTools
{
    private static SimpleAccuracyFunction          f = new SimpleAccuracyFunction();

    private static SimpleAggregateAccuracyFunction a = new SimpleAggregateAccuracyFunction();

    public static Double computeAccuracy(Map<Interval, List<Signal>> actualSignalsMap, Map<Interval, Signal> expectedSignalMap, Map<Interval, Double> expectedPL)
    {
        return a.aggregate(computeAccuracyList(actualSignalsMap, expectedSignalMap, expectedPL));
    }

    public static List<Double> computeAccuracyList(Map<Interval, List<Signal>> actualSignalsMap, Map<Interval, Signal> expectedSignalMap, Map<Interval, Double> expectedPL)
    {
        if (actualSignalsMap.size() != expectedSignalMap.size())
        {
            throw new RuntimeException("Cannot compute. Sizes are different.");
        }

        if (!actualSignalsMap.keySet().containsAll(expectedSignalMap.keySet()))
        {
            throw new RuntimeException("Intervals are not the same!");
        }

        Map<Interval, Boolean> evaluationMap = SignalsEvaluator.evaluate(actualSignalsMap);

        List<Double> accuracyList = new ArrayList<>();
        double accountBalance = 0;
        for (Entry<Interval, List<Signal>> entry : actualSignalsMap.entrySet())
        {
            Interval interval = entry.getKey();
            Signal expectedSignals = expectedSignalMap.get(interval);
            List<Signal> actualSignals = entry.getValue();
            System.out.println("________________");
            double accuracy = f.accuracy(actualSignals, expectedSignals);

            System.out.println("acc = " + accuracy);
            System.out.println("I = " + interval);
            System.out.println("account balance = " + doubleToString(accountBalance));

            if (evaluationMap.get(interval))
            {
                accuracyList.add(accuracy);

                if (accuracy == 1)
                {
                    accountBalance += expectedPL.get(interval);
                }
                else if (accuracy == 0)
                {
                    accountBalance -= expectedPL.get(interval);
                }
                else
                {
                    throw new RuntimeException("Invalid accuracy value");
                }
            }
            else
            {
                System.out.println("Not taken into account because of evaluation.");
            }
            System.out.println("________________");
        }

        System.out.println("account balance TOTAL = " + doubleToString(accountBalance));

        return accuracyList;
    }

    public static String doubleToString(double d)
    {
        return String.valueOf(d);
    }
}
