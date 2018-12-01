#include "ComputerProductFactory.h"

#include "HardDisk.h"
#include "Display.h"

Product* ComputerProductFactory::CreateProduct(char typeCode) const
{
	switch(typeCode)
	{
		case 'h':
			return new HardDisk();
		case 'd':
			return new Display();
	}
	return NULL;
}

