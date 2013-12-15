package indicators.movingaverage;

import out.Out;
import com.tictactec.ta.lib.Core;
import com.tictactec.ta.lib.MAType;
import com.tictactec.ta.lib.MInteger;
import com.tictactec.ta.lib.RetCode;
import exception.TAException;

public class MovingAverage
{

    public static Out ma(final double[] input, int period, MAType maType)
    {
        Out result = new Out();
        double[] out = new double[input.length];
        MInteger begin = new MInteger();
        MInteger length = new MInteger();

        Core c = new Core();

        RetCode retCode = RetCode.BadParam;
        switch (maType)
        {
            case Sma:
                retCode = c.sma(0, input.length - 1, input, period, begin, length, out);
                break;

            case Ema:
                retCode = c.ema(0, input.length - 1, input, period, begin, length, out);
            case Wma:
                retCode = c.wma(0, input.length - 1, input, period, begin, length, out);
            default:
                throw new TAException();
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
