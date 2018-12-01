/****************************************/
/* Benedek Zolt�n-Levendovszky Tiham�r: */
/* Szoftverfejleszt�s C++ nyelven       */
/* c. k�nyv p�ldaprogramjai             */
/* SZAK Kiad� 2007                      */
/****************************************/

#ifndef COMPUTERPRODUCTFACTORY_H
#define COMPUTERPRODUCTFACTORY_H

#include "../lib/ProductFactory.h"

class ComputerProductFactory: public ProductFactory
{
public:
	Product* CreateProduct(char typeCode) const;
};

#endif /* COMPUTERPRODUCTFACTORY_H */
