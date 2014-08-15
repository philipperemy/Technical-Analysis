package evaluator;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import series.Interval;
import signals.Signal;
import signals.SignalTools;
import signals.SignalTools.TypeStructCounter;

public class SignalsEvaluator
{
    public static Map<Interval, Boolean> evaluate(Map<Interval, List<Signal>> actualSignalsMap)
    {
        Map<Interval, Boolean> evaluationMap = new HashMap<>();
        for (Entry<Interval, List<Signal>> entry : actualSignalsMap.entrySet())
        {
            List<Signal> signals = entry.getValue();
            evaluationMap.put(entry.getKey(), evaluate(signals));
        }
        return evaluationMap;
    }

    private static boolean evaluate(List<Signal> signals)
    {
        TypeStructCounter typeStructCounter = SignalTools.countType(signals);
        int signalCount = signals.size();
        return typeStructCounter.upCount == signalCount || typeStructCounter.downCount == signalCount;
    }
}
