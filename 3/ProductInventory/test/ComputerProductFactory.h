#ifndef COMPUTER_PRODUCT_PART_H
#define COMPUTER_PRODUCT_PART_H

#include "../lib/ProductFactory.h"
#include <string>

class ComputerProductFactory : public ProductFactory
{
	public:
		Product* CreateProduct(char typeCode) const;
};

#endif
