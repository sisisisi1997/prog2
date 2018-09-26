import java.io.*;
import java.lang.System; // a nanoTime()-hoz kell, hogy tudjuk mérni a futási időt

class BBPTimer
{
	public static void main(String[] args)
	{
		System.out.print("Java, 10^4 számjegy: ");
		System.out.println(measure(10000));
		//long second = measure(10000000);
		//long third = meausre(100000000);
	}
	
	public static long measure(int digits)
	{
		long startTime = System.nanoTime();
		
		BBP.ComputePiDigits(0, digits);
		
		return System.nanoTime() - startTime;
	}
}