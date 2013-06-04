package main;

import com.tictactec.ta.lib.Core;
import com.tictactec.ta.lib.MInteger;
import com.tictactec.ta.lib.RetCode;

public class TA {
	
	public static TA_Entity MA_SMA(double[] prices, int inTimePeriod) throws TA_Exception
	{
		MInteger begin = new MInteger();
	    MInteger length = new MInteger();
	    double[] out = new double[prices.length];
	      
	     Core c = new Core();
	     RetCode retCode = c.sma(0, prices.length - 1, prices, inTimePeriod, begin, length, out);

	     if (retCode == RetCode.Success)
	    	 return new TA_Entity(begin, length, out);
	     else
	    	 throw new TA_Exception("MA_SMA() error. retCode was not successfull");
	}
	

}
