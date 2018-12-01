/****************************************/
/* Benedek Zolt�n-Levendovszky Tiham�r: */
/* Szoftverfejleszt�s C++ nyelven       */
/* c. k�nyv p�ldaprogramjai             */
/* SZAK Kiad� 2007                      */
/****************************************/

#include <fstream>
#include <locale>
#include "../lib/ProductInventory.h"
#include "../lib/ProductFactory.h"
#include "ComputerProductFactory.h"
#include "../lib/Date.h"

using namespace std;

void ReadInvFromFileTest(ProductInventory& inv);
void WriteInvToFileTest(ProductInventory& inv);

int main(int argc, char* argv[])
{
	try
	{
	
		ProductInventory inv;
		ProductFactory::Init(new ComputerProductFactory());

		

		ReadInvFromFileTest(inv);
		WriteInvToFileTest(inv);
		cout << endl;

		//V�runk billenty� le�t�sre
		cin.get();

		return 0;
	}
	catch(const std::exception& e)
	{
		cerr << "There was an error: " << endl;
		cerr << e.what() << endl;
	}
	catch(...)
	{
		cout << "Unexpected error occured." << endl;
	}
}

void ReadInvFromFileTest(ProductInventory& inv) 
{
	ifstream fs("../TestData/computerproducts.txt");
	if (!fs)
	{
		cerr << "Error opening file." << endl;
		return;
	}
	inv.ReadInventory(fs);
	cout << "The content of computerproducts.txt is:" << endl;
	inv.PrintProducts(cout);
	cout << endl;
}

void WriteInvToFileTest(ProductInventory& inv) 
{
	ofstream fs("../TestData/computerproducts_out.txt");
	if (!fs)
	{
		cerr << "Error opening file." << endl;
		return;
	}
	inv.WriteInventory(fs);
	cout << "The content of the inventory has been " 
		"written to computerproducts_out.txt." << endl;
}
