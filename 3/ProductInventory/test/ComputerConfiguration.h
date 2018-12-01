/****************************************/
/* Benedek Zolt�n-Levendovszky Tiham�r: */
/* Szoftverfejleszt�s C++ nyelven       */
/* c. k�nyv p�ldaprogramjai             */
/* SZAK Kiad� 2007                      */
/****************************************/

#ifndef COMPUTERCONFIGURATION_H
#define COMPUTERCONFIGURATION_H

#include "../lib/CompositeProduct.h"

class ComputerConfiguration :	public CompositeProduct
{
public:
	std::string GetType() const { return "ComputerConfiguration"; }
	char GetCharCode() const { return CharCode; }

	static const char CharCode = 'c';
};

#endif /* COMPUTERCONFIGURATION_H */
