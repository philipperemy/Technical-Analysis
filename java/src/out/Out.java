package out;

import java.util.LinkedHashMap;

public class Out extends LinkedHashMap<Integer, Double>
{

    private static final long serialVersionUID = 1L;

    @Override
    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append("[ ");
        for (Double entry : values())
        {
            sb.append(entry.doubleValue() + ", ");
        }
        sb.append(" ]");
        return sb.toString();
    }

}
