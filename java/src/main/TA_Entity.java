package main;

import com.tictactec.ta.lib.MInteger;

public class TA_Entity {
	
	private MInteger begin;
	private MInteger length;
	private double[] prices;
	
	public TA_Entity(MInteger begin, MInteger length, double[] prices)
	{
		this.begin = begin;
		this.length = length;
		this.prices = prices;
	}
	
	public int getBegin() { return begin.value; }
	public int getLength() { return length.value; }
	public double[] getPrices() { return prices; }
	
	public double get(int id) throws TA_Exception { 
		if(id >= begin.value && id <= (begin.value+length.value))
			return prices[id]; 
		else
			throw new TA_Exception("Invalid id : " + id);
	}
	
}
