/****************************************/
/* Benedek Zolt�n-Levendovszky Tiham�r: */
/* Szoftverfejleszt�s C++ nyelven       */
/* c. k�nyv p�ldaprogramjai             */
/* SZAK Kiad� 2007                      */
/****************************************/

// File: ProductFactory.h
#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H

#include <iostream>
#include "Product.h"

class ProductFactory
{
	static ProductFactory* instance;
	//ProductFactory() {}
public:
	virtual ~ProductFactory() {}
	virtual Product* CreateProduct(char typeCode) const = 0;
	static ProductFactory* GetInstance();
	static void Init(ProductFactory* pf);
	Product* ReadAndCreateProduct(std::istream& is); 
};

#endif /* PRODUCTFACTORY_H */
