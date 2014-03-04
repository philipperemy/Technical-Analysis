package runner;

import java.util.List;
import series.TimeSeriesPair;

public interface AbstractRunner extends Runnable
{
    public void readFile(String path);
    
    public void loadTimeSeries(List<TimeSeriesPair> tsp);
   
}
