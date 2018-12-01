/****************************************/
/* Benedek Zolt�n-Levendovszky Tiham�r: */
/* Szoftverfejleszt�s C++ nyelven       */
/* c. k�nyv p�ldaprogramjai             */
/* SZAK Kiad� 2007                      */
/****************************************/

// File: CompositeProduct.h
#ifndef COMPOSITEPRODUCT_H
#define COMPOSITEPRODUCT_H

#include <vector>
#include <iostream>


#include "Product.h"

class CompositeProduct :
	public Product
{
	std::vector<Product*> parts;
protected:
	void printParams(std::ostream& os) const;
	void loadParamsFromStream(std::istream& is);
	void writeParamsToStream(std::ostream& os) const;
public:
	CompositeProduct();
	~CompositeProduct();
	void AddPart(Product* product);
	void SortProduct();
};
#endif /* COMPOSITEPRODUCT_H */
