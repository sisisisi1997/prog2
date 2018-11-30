import java.io.*;

import helper.Szulo;
import helper.Gyerek;

class SZGYmain
{
	public static void main(String[] args)
	{
		// először helyezzünk bele egy szülő típusú változóba egy gyerek típusú példányt - ekkor a gyerek implementációja fut le
		Szulo peldany = new Gyerek();
		System.out.println(peldany.toBeOverridden());
		
		// fordítási hiba: a Szulo típusnak nincs ilyen metódusa
		//System.out.println(peldany.csakGyerek());
		
		// castoljuk a típust gyerekre, akkor lefut, viszont már nem Szulo típusú, így ez érthető
		System.out.println(((Gyerek)peldany).csakGyerek());
	}
}