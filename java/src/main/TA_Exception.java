package main;

public class TA_Exception extends Exception {

	private static final long serialVersionUID = 1L;
	
	public TA_Exception(String error) {
		System.out.println(error);
		System.exit(0);
	}

}
