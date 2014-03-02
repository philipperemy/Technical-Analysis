package indicators.movingaverage;

import series.TimeSeries;
import utils.TAException;
import com.tictactec.ta.lib.Core;
import com.tictactec.ta.lib.MAType;
import com.tictactec.ta.lib.MInteger;
import com.tictactec.ta.lib.RetCode;

public class MovingAverage
{
    public static TimeSeries ma(final double[] input, int period, MAType maType)
    {
        TimeSeries result = new TimeSeries();
        double[] out = new double[input.length];
        MInteger begin = new MInteger();
        MInteger length = new MInteger();

        Core c = new Core();

        RetCode retCode = RetCode.BadParam;
        switch (maType)
        {
            case Sma:
            {
                retCode = c.sma(0, input.length - 1, input, period, begin, length, out);
                break;
            }
            case Ema:
            {
                retCode = c.ema(0, input.length - 1, input, period, begin, length, out);
                break;
            }
            case Wma:
            {
                retCode = c.wma(0, input.length - 1, input, period, begin, length, out);
                break;
            }
            default:
            {
                throw new IllegalArgumentException();
            }
        }

        for (int i = 0; i < input.length; i++)
        {
            if (i < begin.value)
            {
                result.put(i, 0.0);
            }
            else
            {
                result.put(i, out[i - begin.value]);
            }
        }

        if (retCode == RetCode.Success)
        {
            return result;
        }
        else
        {
            throw new TAException();
        }
    }

}
