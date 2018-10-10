/****************************************/
/* Benedek Zolt�n-Levendovszky Tiham�r: */
/* Szoftverfejleszt�s C++ nyelven       */
/* c. k�nyv p�ldaprogramjai             */
/* SZAK Kiad� 2007                      */
/****************************************/

// File: ProductInventory.h
#ifndef PRODUCTINVENTORY_H
#define PRODUCTINVENTORY_H

#include <vector>
#include <iostream>
#include "Product.h"

class ProductInventory
{
	void emptyProducts();
protected:
	std::vector<Product*> products;
public:
	virtual ~ProductInventory();
	void ReadInventory(std::istream& is);
	void WriteInventory(std::ostream& os) const;
	void PrintProducts(std::ostream& os) const;
	void AddProduct(Product* product);
};

#endif /* PRODUCTINVENTORY_H */
