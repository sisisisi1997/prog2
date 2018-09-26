import java.io.*;
import java.lang.Math;
import java.text.DecimalFormat;

public class BBP
{
	public static void main(String[] args)
	{
		System.out.print("Starting digit of pi: ");
		int start = Integer.parseInt(System.console().readLine());
		System.out.print("Number of digits required: ");
		int count = Integer.parseInt(System.console().readLine());
		System.out.print("Result: ");
		System.out.println(ComputePiDigits(start, count));
	}
	
	private static String ComputePiDigits(int d, int count)
	{
		StringBuffer resultString = new StringBuffer();
		
		while(count > 0)
		{
			double result = 0.0;
			result = 4.0 * S(d, 1) - 2.0 * S(d, 4) - S(d, 5) - S(d, 6);
			result -= Math.floor(result);
			
			String[] digits = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
			
			int tmpCount = 4; // 4 digits are always correct with java types on a 64 bit machine, S(d, j) counting to d + 16
			while(result != 0.0 && tmpCount > 0 && count > 0)
			{
				result *= 16.0;
				resultString.append(digits[(int)Math.floor(result)]);
				result = result - Math.floor(result);
				
				++ d;
				-- count;
				-- tmpCount;
			}
		}
		
		return resultString.toString();
	}
	
	private static double S(int d, int j)
	{
		double piSum = 0.0;
		for(int k = 0; k <= d; ++ k) // necessary to sum the "rougher" part
		{
			piSum += Power16ModK(d - k, 8 * k + j) / (double)(8 * k + j);
		}
		for(int k = d + 1; k - d < 16; ++ k) // a computation this fine is enough to make 4 correct digits
		{
			piSum += Math.pow(16, d - k) / (double)(8 * k + j);
		}
		return piSum - Math.floor(piSum);
	}
	
	private static long Power16ModK(int power, int modulo)
	{
		// Binary algorithm for exponentiation modulo k from bbp-alg.pdf, page 3
		int t = 1; long r = 1;
		while(t <= power / 2) // if we compare to 'power', we get double of what we want
		{
			t *= 2;
		}
		
		while(t >= 1)
		{
			if(power >= t)
			{
				r = (16 * r) % modulo;
				power = power - t;
			}
			
			t /= 2;
			
			if(t >= 1)
			{
				r = (r * r) % modulo;
			}
		}
		
		return r;
	}
}