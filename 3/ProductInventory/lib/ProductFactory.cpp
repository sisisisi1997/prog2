/****************************************/
/* Benedek Zolt�n-Levendovszky Tiham�r: */
/* Szoftverfejleszt�s C++ nyelven       */
/* c. k�nyv p�ldaprogramjai             */
/* SZAK Kiad� 2007                      */
/****************************************/

#include <stdexcept>
#include "ProductFactory.h"

using namespace std;

ProductFactory* ProductFactory::instance = NULL;

void ProductFactory::Init(ProductFactory* pf)
{
	instance = pf;
}

ProductFactory* ProductFactory::GetInstance()
{
	return instance;
}

Product* ProductFactory::ReadAndCreateProduct(istream& is)
{
	if (!is.good())
		return NULL;

	char typeCode;
	is >> typeCode;
	
	// Ha nincs semmi hiba �s f�jlv�ge sem
	if (!is.good())	
	{
		if (is.eof()) return NULL;

		cout << "There was an error reading the product items!" << endl;
		return NULL;
	}

	Product* product = CreateProduct( typeCode );
	if (product == NULL) // Ha p NULL
	{
		cout << "Unknown product type." << endl;
	}
	return product;
}
