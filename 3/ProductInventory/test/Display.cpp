#include <iostream>
#include "Display.h"

void Display::printParams(std::ostream& os) const
{
	Product::printParams(os);
	os << ", " << "InchWidth: " << inchWidth;
	os << ", " << "InchHeight: " << inchHeight;
}

void Display::writeParamsToStream(std::ostream& os) const
{
	Product::writeParamsToStream(os);
	os << ' ' << inchWidth << ' ' << inchHeight;
}

void Display::loadParamsFromStream(std::istream& is) const
{
	Product::loadParamsFromStream(is);
	is >> inchWidth; is >> inchHeight;
}

Display::Display(std::string name, int price, Date acq, int width, int height)
	: inchWidth(width),
	inchHeight(height)
{
	this->name = name;
	this->initialPrice = price;
	this->dateOfAcquisition = acq;
}