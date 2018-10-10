#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H

#include <iostream>
#include "Product.h"

class ProductFactory
{
	static ProductFactory* instance;
	public:
		virtual ~ProductFactory() {}
		virtual Product* CreateProduct(char typeCode) const = 0;
		static ProductFactory* GetInstance();
		static void Init(ProductFactory* pf);
		Product* ReadAndCreateProduct(std::istream& is); 
};

#endif
