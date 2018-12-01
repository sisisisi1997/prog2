/****************************************/
/* Benedek Zolt�n-Levendovszky Tiham�r: */
/* Szoftverfejleszt�s C++ nyelven       */
/* c. k�nyv p�ldaprogramjai             */
/* SZAK Kiad� 2007                      */
/****************************************/

#ifndef HARDDISK_H
#define HARDDISK_H

#include "../lib/Product.h"

class HardDisk : public Product
{
	int speedRPM;
protected:
	void printParams(std::ostream& os) const;
	void loadParamsFromStream(std::istream& is);
	void writeParamsToStream(std::ostream& os) const;
public:
	HardDisk();
	HardDisk(std::string name, int initialPrice, time_t dateOfAcquisition,
		int rpm);
	std::string GetType() const { return "HardDisk"; }
	char GetCharCode() const { return CharCode; }
	int GetSpeedRPM() { return speedRPM; }
	static const char CharCode = 'h';
	int GetCurrentPrice() const;
};

#endif /* HARDDISK_H */
