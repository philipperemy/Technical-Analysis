package accuracy;

import java.util.List;

public interface AggregateAccuracyFunction
{
    public double aggregate(List<Double> accuracyList);
}
