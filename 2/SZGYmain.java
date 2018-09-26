import java.io.*;

import helper.Szulo;
import helper.Gyerek;

class SZGYmain
{
	public static void main(String[] args)
	{
		Szulo peldany = new Gyerek();
		System.out.println(peldany.toBeOverridden());
	}
}