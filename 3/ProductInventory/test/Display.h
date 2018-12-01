/****************************************/
/* Benedek Zolt�n-Levendovszky Tiham�r: */
/* Szoftverfejleszt�s C++ nyelven       */
/* c. k�nyv p�ldaprogramjai             */
/* SZAK Kiad� 2007                      */
/****************************************/

#ifndef DISPLAY_H
#define DISPLAY_H

#include "../lib/Product.h"

class Display :	public Product
{
	int inchWidth;
	int inchHeight;
protected:
	void printParams(std::ostream& os) const;
	void loadParamsFromStream(std::istream& is);
	void writeParamsToStream(std::ostream& os) const;
public:
	Display();
	Display(std::string name, int initialPrice, time_t dateOfAcquisition,
		int inchWidth, int inchHeight);
	std::string GetType() const { return "Display"; }
	char GetCharCode() const { return CharCode; }
	int GetInchWidth() { return inchWidth; }
	int GetInchHeight() { return inchHeight; }

	static const char CharCode = 'd';
};

#endif /* DISPLAY_H */
