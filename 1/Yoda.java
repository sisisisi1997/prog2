import java.io.*;

public class Yoda
{
	public static void main(String[] args)
	{
		try
		{
			System.out.print("Enter a string: ");
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			String str = reader.readLine();
			reader.close();
			if(str.contains("foo"))
			{
				str = null;
			}
			if("bar".equals(str)) // this Yoda condition prevents a NullPointerException when the string contains "foo"
			{
				System.out.println("String equals 'bar'!");
			}
		}
		catch(IOException ex)
		{
			// do nothing, program ended anyways
		}
	}
}
