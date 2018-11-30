import java.io.*;
import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;

public class RSAToro
{
	public static void main(String[] args)
	{
		RSA kulcspar = new RSA();
		System.out.print("Adja meg a szöveget (csak angol kisbetűk és space): ");
		String szoveg = System.console().readLine();
		
		System.out.println("titkosít...");
		BigInteger[] titkos = Kodol(kulcspar, szoveg);
		System.out.print("Szöveg dekódolva: ");
		System.out.println(Dekodol(kulcspar, titkos));
		
		System.out.print("Szöveg törve: ");
		System.out.println(Feltor(titkos));
	}
	
	private static String Feltor(BigInteger[] titkos)
	{
		// gyakoriság sorrendjében
		char[] betuk = { ' ', 'e', 't', 'a', 'o', 'i', 'n', 's', 'h', 'r', 'w', 'd', 'l', 'y', 'k', 'c', 'u', 'm', 'f', 'g', 'p', 'b', 'v', 'j', 'x', 'q', 'z' };
		
		HashMap<BigInteger, Integer> gyakorisag = new HashMap<>();
		
		for(BigInteger betu : titkos)
		{
			if(gyakorisag.containsKey(betu))
			{
				gyakorisag.put(betu, gyakorisag.get(betu) + 1);
			}
			else
			{
				gyakorisag.put(betu, 1);
			}
		}
		
		Set<Map.Entry<BigInteger, Integer>> pairs = gyakorisag.entrySet();
		ArrayList<Map.Entry<BigInteger, Integer>> pairsArray = new ArrayList<Map.Entry<BigInteger, Integer>>(pairs.size());
		int i = 0;
		for(Map.Entry<BigInteger, Integer> pair : pairs)
		{
			pairsArray.add(pair);
		}
		
		Collections.sort(pairsArray, new Comparator<Map.Entry<BigInteger, Integer>>()
		{
			public int compare(Map.Entry<BigInteger, Integer> a, Map.Entry<BigInteger, Integer> b)
			{
				return b.getValue() - a.getValue();
			}
		});
		HashMap<BigInteger, Character> betukrendben = new HashMap<>();
		
		for(i = 0; i < pairsArray.size(); ++ i)
		{
			betukrendben.put(pairsArray.get(i).getKey(), betuk[i]);
		}
		
		String eredmeny = "";
		for(i = 0; i < titkos.length; ++ i)
		{
			eredmeny += betukrendben.get(titkos[i]);
		}
		
		return eredmeny;
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
}