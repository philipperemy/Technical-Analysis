package parser;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class CSVParser
{
    String               filename;
    private List<String> closePrices = new ArrayList<>();

    public CSVParser(String filename)
    {
        try
        {
            this.filename = filename;
            BufferedReader reader = new BufferedReader(new FileReader(this.filename));

            String line;
            while ((line = reader.readLine()) != null)
            {
                String[] lineAr = line.split(";");
                closePrices.add(lineAr[5]);
            }

            reader.close();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }

    public List<String> values()
    {
        return closePrices;
    }

}
