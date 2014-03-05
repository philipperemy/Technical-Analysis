package main;

import java.io.IOException;
import series.TimeSeries;
import series.TimeSeriesGenerator;

public class GenerateApp
{
    public static void main(String[] args) throws IOException
    {
        TimeSeries timeSeries = TimeSeriesGenerator.getRandomTimeSeries(100000);
        TimeSeriesGenerator.write("files/sequences.txt", timeSeries);
    }
}
