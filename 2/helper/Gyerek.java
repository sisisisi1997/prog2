package helper;

public class Gyerek extends Szulo
{
	public String toBeOverridden()
	{
		return "Gyerek";
	}
	
	public String csakGyerek()
	{
		return "Ez a metódus nem található meg a szülőben";
	}
}