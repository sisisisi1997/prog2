package helper;

public class Gyerek extends Szulo // valamilyen oknál fogva ezt nem találja pedig ugyanabban a package-ben vannak
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