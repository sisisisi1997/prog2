#include "StringNumber.hpp"

#include <stdexcept>
#include <algorithm>

StringNumber::StringNumber() {}

StringNumber::StringNumber(std::string source)
{
	this->initFrom(source);
}

void StringNumber::initFrom(std::string source)
{
	if(&source == nullptr || source.length() == 0)
	{
		throw std::invalid_argument("Source string cannot be empty.");
	}
	
	int start = 0;
	this->sign = true;
	if(source[0] == '+' || source[0] == '-')
	{
		if(source.length() == 1)
		{
			throw std::invalid_argument("Source string needs to contain a number, not just a sign.");
		}
		
		this->sign = source[0] == '+';
		++ start;
	}
	
	std::string helper;
	bool reachedFractional = false;
	for(int i = start; i < source.length(); ++ i)
	{
		if(source[i] == '.' || source[i] == ',')
		{
			if(reachedFractional)
			{
				throw std::invalid_argument("Source string cannot contain more than one dot or comma.");
			}
			else
			{
				this->wholePart = (helper.length() == 0 ? "0" : helper);
				helper = "";
				reachedFractional = true;
			}
		}
		else
		{
			if(source[i] >= '0' && source[i] <= '9')
			{
				helper += source[i];
			}
			else
			{
				throw std::invalid_argument("Source string cannot contain non-numeric characters other than the sign, and one dot or comma.");
			}
		}
	}
	
	if(!reachedFractional)
	{
		this->wholePart = (helper.length() == 0 ? "0" : helper);
		this->fractionalPart = "0";
	}
	else
	{
		this->fractionalPart = (helper.length() == 0 ? "0" : helper);
	}
}

std::string StringNumber::toString()
{
	return (this->sign ? "+" : "-") + this->wholePart + (this->fractionalPart == "0" ? "" : "." + this->fractionalPart);
}

bool StringNumber::isGreaterThan(StringNumber other)
{
	if(this->sign != other.sign)
	{
		return this->sign;
	}
	
	if(this->wholePart.length() == other.wholePart.length())
	{
		for(int i = 0; i < this->wholePart.length(); ++ i)
		{
			if(this->wholePart[i] == other.wholePart[i])
				continue;
			return (this->wholePart[i] > other.wholePart[i]) ^ !this->sign;
		}
		
		int length = std::min(this->fractionalPart.length(), other.fractionalPart.length());
		for(int i = 0; i < length; ++ i)
		{
			if(this->fractionalPart[i] == other.fractionalPart[i])
				continue;
			return (this->fractionalPart[i] > other.fractionalPart[i]) ^ !this->sign;
		}
		
		return (this->fractionalPart.length() > other.fractionalPart.length()) ^ !this->sign;
	}
	else
	{
		return (this->wholePart.length() > other.wholePart.length()) ^ !this->sign;
	}
}

bool StringNumber::isEqualTo(StringNumber other)
{
	return this->sign == other.sign
			&& this->wholePart == other.wholePart
			&& this->fractionalPart == other.fractionalPart;
}

bool StringNumber::isLessThan(StringNumber other)
{
	return !(isGreaterThan(other) || isEqualTo(other));
}