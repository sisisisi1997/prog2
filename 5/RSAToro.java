import java.io.*;
import java.math.BigInteger;
import java.nio.charset.StandardCharsets;

public class RSAToro
{
	public static void main(String[] args)
	{
		RSA kulcspar = new RSA();
		String szoveg = "Hello, world!";
		BigInteger[] titkos = Kodol(kulcspar, szoveg);
		System.out.print("Szöveg dekódolva: ");
		System.out.println(Dekodol(kulcspar, titkos));
	}
	
	private static BigInteger[] Kodol(RSA kulcspar, String szoveg)
	{
		byte[] buffer = szoveg.getBytes(StandardCharsets.UTF_8);
		BigInteger[] titkos = new BigInteger[buffer.length];
		for(int i = 0; i < titkos.length; ++ i)
		{
			titkos[i] = new BigInteger(new byte[] { buffer[i] })
				.modPow(kulcspar.e, kulcspar.m);
		}
		return titkos;
	}
	
	private static String Dekodol(RSA kulcspar, BigInteger[] titkos)
	{
		byte[] buffer = new byte[titkos.length];
		for(int i = 0; i < titkos.length; ++ i)
		{
			buffer[i] = titkos[i].modPow(kulcspar.d, kulcspar.m).byteValue();
		}
		return new String(buffer);
	}
	
	private static String Feltor(BigInteger[] titkos)
	{
		return null;
	}
}