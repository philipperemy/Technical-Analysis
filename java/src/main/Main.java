package main;

/*public class Main {

	public static void main(String[] args) {
		
		double[] closePrices = new double[200];
		for(int i=0; i<200; i++)
			closePrices[i] = (double) 2*i;
		
		try {
		
			TA_Entity mma30Prices = TA.MA_SMA(closePrices, 5);
			
			System.out.println("begin = " + mma30Prices.getBegin());
			System.out.println("length = " + mma30Prices.getLength());
			
			for(int i=0; i<mma30Prices.getLength(); i++) {
				System.out.println(mma30Prices.get(mma30Prices.getBegin()+i));
			}
		
		} catch (TA_Exception e) {}
		
	}

}*/

import com.tictactec.ta.lib.Core;
import com.tictactec.ta.lib.MInteger;
import com.tictactec.ta.lib.RetCode;

public class Main {
  /**
   * The total number of periods to generate data for.
   */
  public static final int TOTAL_PERIODS = 100;

  /**
    * The number of periods to average together.
    */
  public static final int PERIODS_AVERAGE = 30;

    public static void main(String[] args) {
      double[] closePrice = new double[TOTAL_PERIODS];
      double[] out = new double[TOTAL_PERIODS];
      MInteger begin = new MInteger();
      MInteger length = new MInteger();

      for (int i = 0; i < closePrice.length; i++) {
        closePrice[i] = (double) i;
      }

      Core c = new Core();
      RetCode retCode = c.sma(0, closePrice.length - 1, closePrice, PERIODS_AVERAGE, begin, length, out);

      if (retCode == RetCode.Success) {
        System.out.println("Output Begin:" + begin.value);
        System.out.println("Output Begin:" + length.value);

        for (int i = begin.value; i < begin.value+length.value; i++) {
          StringBuilder line = new StringBuilder();
          line.append("Period #");
          line.append(i+1);
          line.append(" close= ");
          line.append(closePrice[i]);
          line.append(" mov avg=");
          line.append(out[i]);
          System.out.println(line.toString());
      }
    }
    else {
      System.out.println("Error");
    }
  }
}
