package accuracy;

import java.util.List;
import signals.Signal;

public interface AccuracyFunction
{
    public double accuracy(List<Signal> actualSignals, Signal expectedSignal);
}
