import java.lang.Math;
import java.io.*;

public class PolarGenerator
{
	boolean	nincsTarolt	= true;
	double	tarolt;
	
	public PolarGenerator()
	{
		nincsTarolt = true;
	}
	
	public double kovetkezo()
	{
		if(nincsTarolt) // le kell futtatnunk az algoritmust
		{
			double u1, u2, v1, v2, w;
			do
			{
				// u1 és u2 a [0.0, 1.0[ tartományban kapnak értéket
				u1 = Math.random();
				u2 = Math.random();
				// v1 és v2 a [-1.0, 1.0[ tartományban kapnak értéket
				v1 = 2 * u1 - 1;
				v2 = 2 * u2 - 1;
				// w a [0.0, 2.0[ tartományban kap értéket - a négyzet elveszi a negatív előjelet, 0 és 1 közötti abszolútértékű számok pedig négyzetre emelve is 0 és 1 között maradnak
				w = v1 * v1 + v2 * v2;
			}
			while(w > 1);
			// ugye ennek a kódnak az eredeti készítője tudja, hogy w lehet 0? Mindössze csillagászati az esélye - mindössze u1-nek és u2-nek is 0.5-nek kell lennie
			double r = Math.sqrt((-2 * Math.log(w)) / w);
			tarolt = r * v2; // eltároljuk az egyik random eredményt
			nincsTarolt = !nincsTarolt; // hamisra állítjuk
			return r * v1; // visszaadjuk a másik random eredményt
		}
		else
		{
			nincsTarolt = !nincsTarolt; // igazra állítjuk
			return tarolt; // visszaadjuk "az egyik" random eredményt
		}
	}
	
	public static void main(String[] args)
	{
		PolarGenerator g = new PolarGenerator();
		for(int i = 0; i < 10; ++ i)
		{
			System.out.println(g.kovetkezo());
		}
	}
}
