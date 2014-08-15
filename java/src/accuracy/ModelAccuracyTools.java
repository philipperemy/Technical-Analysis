package accuracy;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import evaluator.SignalsEvaluator;
import series.Interval;
import signals.Signal;

public class ModelAccuracyTools
{
    private static AccuracyFunction          f = new SimpleAccuracyFunction();

    private static AggregateAccuracyFunction a = new SimpleAggregateAccuracyFunction();

    public static Double computeAccuracy(Map<Interval, List<Signal>> actualSignalsMap, Map<Interval, Signal> expectedSignalMap)
    {
        return a.aggregate(computeAccuracyList(actualSignalsMap, expectedSignalMap));
    }

    public static List<Double> computeAccuracyList(Map<Interval, List<Signal>> actualSignalsMap, Map<Interval, Signal> expectedSignalMap)
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
        for (Entry<Interval, List<Signal>> entry : actualSignalsMap.entrySet())
        {
            Interval interval = entry.getKey();
            Signal expectedSignals = expectedSignalMap.get(interval);
            List<Signal> actualSignals = entry.getValue();
            System.out.println("________________");
            double accuracy = f.accuracy(actualSignals, expectedSignals);
            System.out.println("acc = " + accuracy);
            System.out.println("I = " + interval);

            if (evaluationMap.get(interval))
            {
                accuracyList.add(accuracy);
            }
            else
            {
                System.out.println("Not taken into account because of evaluation.");
            }
            System.out.println("________________");
        }

        return accuracyList;
    }
}
