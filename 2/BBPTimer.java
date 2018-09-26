import java.io.*;
import java.lang.System; // a nanoTime()-hoz kell, hogy tudjuk mérni a futási időt

class BBPTimer
{
	public static void main(String[] args)
	{
		long first = measure(1000000);
		long second = measure(10000000);
		long third = meausre(100000000);
	}
	
	public static long measure(int digits)
	{
		long startTime = System.nanoTime();
		
		// TODO: run the BBP algorithm here for the given number of digits
		// we are not interested in the results, just the runtime
		
		return System.nanoTime() - startTime;
	}
}