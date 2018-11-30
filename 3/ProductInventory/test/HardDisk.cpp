#include <iostream>
#include <string>

class HardDisk : public Product
{
	public:
		int GetCurrentPrice() const;
		
		std::string GetType() const { return "HardDisk"; }
		char GetCharCode() const { return CharCode; }
	private:
		int speedRPM;
		static const CharCode = 'h';
}

int HardDisk::GetCurrentPrice()
{
	int ageInDays = GetAge();
	if(ageInDays < 30)
	{
		return initialPrice;
	}
	else if(ageInDays < 90)
	{
		return (int)(initialPrice * 0.9);
	}
	else
	{
		return (int)(initialPrice * 0.8);
	}
}