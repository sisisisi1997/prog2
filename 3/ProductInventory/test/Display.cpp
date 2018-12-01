/****************************************/
/* Benedek Zolt�n-Levendovszky Tiham�r: */
/* Szoftverfejleszt�s C++ nyelven       */
/* c. k�nyv p�ldaprogramjai             */
/* SZAK Kiad� 2007                      */
/****************************************/

#include "Display.h"

//const char* Product::type = "Display";

Display::Display()
{
}

Display::Display(std::string name, int initialPrice, time_t dateOfAcquisition,
				 int inchWidth, int inchHeight):
 Product(name, initialPrice, dateOfAcquisition),
 inchWidth(inchWidth), inchHeight(inchHeight)
{
}

void Display::printParams(std::ostream& os) const
{
	Product::printParams(os);
	os << ", " << "InchWidth: " << inchWidth;
	os << ", " << "InchHeight: " << inchHeight;
}

void Display::loadParamsFromStream(std::istream& is)
{
	Product::loadParamsFromStream(is);
	is >> inchWidth >> inchHeight;
}

void Display::writeParamsToStream(std::ostream& os) const
{
	Product::writeParamsToStream(os);
	os << ' ' << inchWidth << ' ' << inchHeight;
}