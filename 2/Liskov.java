import helper.StringNumber;

class Liskov
{
	public static void main(String[] args)
	{
		while(true)
		{
			StringNumber num1 = new StringNumber(System.console().readLine());
			StringNumber num2 = new StringNumber(System.console().readLine());
			System.out.println(num1.isGreaterThan(num2));
		}
	}
}