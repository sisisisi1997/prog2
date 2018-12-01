#include <iostream>
#include <string>

#include "HardDisk.h"

int HardDisk::GetCurrentPrice() const
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

HardDisk::HardDisk(string name, int price, Date acq, int speed)
	: name(name),
	initialPrice(price),
	dateOfAcquisition(acq),
	speedRMP(speed)
{
	
}