/****************************************/
/* Benedek Zolt�n-Levendovszky Tiham�r: */
/* Szoftverfejleszt�s C++ nyelven       */
/* c. k�nyv p�ldaprogramjai             */
/* SZAK Kiad� 2007                      */
/****************************************/

#include "ComputerProductFactory.h"
#include "Display.h"
#include "HardDisk.h"
#include "ComputerConfiguration.h"

Product* ComputerProductFactory::CreateProduct(char typeCode) const
{
	switch (typeCode) {
		case 'd':
			return new Display();
		case 'h':
			return new HardDisk();
		case 'c':
			return new ComputerConfiguration();
	}
	return NULL;
}
