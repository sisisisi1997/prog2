class Gagyi
{
	public static void main(String[] args)
	{
		Integer x = 127;
		Integer y = 127;
		
		while(x >= y && x <= y && x != y)
		{
			System.out.println("Ide sosem lép be a cache-elés miatt, ami 127-ig tart, és az értékünk 127.");
		}
		
		// ez végtelen ciklus lesz, mert az IntegerCache.high 127, itt nem fog egyezni a memóriacím
		Integer x2 = 128;
		Integer y2 = 128;
		
		while(x2 >= y2 && x2 <= y2 && x2 != y2)
		{
			System.out.println("Ha a következő sor nem \"break;\" lenne, ez egy végtelen ciklus lenne 128-as értéknél.");
			break;
		}
	}
}