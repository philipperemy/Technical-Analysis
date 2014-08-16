package accuracy;

import java.util.List;

public class SimpleAggregateAccuracyFunction
{
    public double aggregate(List<Double> accuracyList)
    {
        double sum = 0;
        for (double accuracy : accuracyList)
        {
            sum += accuracy;
        }
        return (double) sum / accuracyList.size();
    }

}
