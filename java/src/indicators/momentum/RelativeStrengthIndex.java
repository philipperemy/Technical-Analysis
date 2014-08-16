package indicators.momentum;

import series.TimeSeries;
import utils.TAException;
import com.tictactec.ta.lib.Core;
import com.tictactec.ta.lib.MInteger;
import com.tictactec.ta.lib.RetCode;

public class RelativeStrengthIndex
{
    public static TimeSeries rsi(final double[] input, int period)
    {
        TimeSeries result = new TimeSeries();
        double[] out = new double[input.length];
        MInteger begin = new MInteger();
        MInteger length = new MInteger();

        Core c = new Core();

        RetCode retCode = RetCode.BadParam;
        retCode = c.rsi(0, input.length - 1, input, period, begin, length, out);

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
            result.setId("RSI-" + period);
            return result;
        }

        throw new TAException();

    }
}
