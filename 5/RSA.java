import java.io.*;
import java.util.Random;
import java.lang.Math;
import java.math.BigInteger;

public class RSA
{
	public BigInteger d, e, m;
	
	public RSA()
	{
		int meretBitekben = 700 * (int)(Math.log(10d) / Math.log(2d));
		BigInteger p = new BigInteger(meretBitekben, 100, new Random());
		BigInteger q = new BigInteger(meretBitekben, 100, new Random());
		m = p.multiply(q);
		BigInteger z = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
		
		do
		{
			do
			{
				d = new BigInteger(meretBitekben, 100, new Random());
			}
			while(d.equals(BigInteger.ONE));
		}
		while(!z.gcd(d).equals(BigInteger.ONE));
		
		e = d.modInverse(z);
	}
}