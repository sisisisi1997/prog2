import helper.StringNumber;
import helper.ComplexStringNumber;

class Liskov
{
	public static void main(String[] args)
	{
		ComplexStringNumber csn1 = new ComplexStringNumber("-3.14+5.36i");
		ComplexStringNumber csn2 = new ComplexStringNumber("-3+.19i");
		
		System.out.println(csn1.toString());
		System.out.println(csn2.toString());
		System.out.println(csn1.isGreaterThan(csn2));
	}
}