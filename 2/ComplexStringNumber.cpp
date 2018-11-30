#include "ComplexStringNumber.hpp"

#include <stdexcept>

ComplexStringNumber::ComplexStringNumber(std::string source)
{
	std::string realPart;
	int plusminuscount = 0;
	for(int i = 0; i < source.length(); ++ i)
	{
		if(source[i] == '+' || source[i] == '-')
		{
			++ plusminuscount;
			if(plusminuscount == 2)
			{
				this->initFrom(realPart);
				break;
			}
		}
		
		realPart += source[i];
	}
	
	source = source.substr(realPart.length());
	
	if(&source == nullptr || source.length() == 0)
	{
		throw std::invalid_argument("Source string imaginary part cannot be empty.");
	}
	
	if(source[source.length() - 1] != 'i')
	{
		throw std::invalid_argument("Source string must end in 'i'.");
	}
	
	source = source.substr(0, source.length() - 1);
	
	if(&source == nullptr || source.length() == 0)
	{
		throw std::invalid_argument("Source string imaginary part cannot be empty.");
	}
	
	int start = 0;
	this->isign = true;
	if(source[0] == '+' || source[0] == '-')
	{
		if(source.length() == 1)
		{
			throw std::invalid_argument("Source string needs to contain a number, not just a sign.");
		}
		
		this->isign = source[0] == '+';
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
				this->iwholePart = (helper.length() == 0 ? "0" : helper);
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
		this->iwholePart = (helper.length() == 0 ? "0" : helper);
		this->ifractionalPart = "0";
	}
	else
	{
		this->ifractionalPart = (helper.length() == 0 ? "0" : helper);
	}
}

std::string ComplexStringNumber::toString()
{
	return StringNumber::toString()
		+ (this->isign ? "+" : "-")
		+ this->iwholePart
		+ (this->ifractionalPart.length() == 0 ? "" : "." + this->ifractionalPart)
		+ "i";
}

bool ComplexStringNumber::isGreaterThan(ComplexStringNumber other)
{
	throw std::runtime_error("complex numbers don't have this property");
}

bool ComplexStringNumber::isLessThan(ComplexStringNumber other)
{
	throw std::runtime_error("complex numbers don't have this property");
}

bool ComplexStringNumber::isEqualTo(ComplexStringNumber other)
{
	return StringNumber::isEqualTo(other)
			&& this->isign == other.isign
			&& this->iwholePart == other.iwholePart
			&& this->ifractionalPart == other.ifractionalPart;
}