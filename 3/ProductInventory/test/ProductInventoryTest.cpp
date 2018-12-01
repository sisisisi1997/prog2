#include <iostream>
#include <fstream>

#include "../lib/ProductInventory.h"
#include "../lib/ProductFactory.h"
#include "../lib/Date.h"
#include "ComputerProductFactory.h"
#include "Display.h"
#include "HardDisk.h"

using namespace std;

void readInvFromFileTest(ProductInventory& inv);
void writeInvToFileTest(ProductInventory& inv);

int main()
{
	ProductFactory::Init(new ComputerProductFactory());
	
	Date date = Date();
	ProductInventory inv1;
	inv1.AddProduct(new Display("TFT", 30000, date, 13, 12));
	inv1.AddProduct(new HardDisk("WD", 25000, date, 7500));
	inv1.PrintProducts(cout);
	writeInvToFileTest(inv1);
	
	cout << "Press any key to continue...";
	cin.get();
	cout << endl;
	
	ProductInventory inv2;
	readInvFromFileTest(inv2);
	writeInvToFileTest(inv2);
	
	cout << "done";
	cin.get();
}

void readInvFromFileTest(ProductInventory& inv)
{
	ifstream is("data.txt");
	inv.ReadInventory(is);
	cout << "Read products: " << std::endl;
	inv.PrintProducts(cout);
	cout << endl;
}

void writeInvToFileTest(ProductInventory& inv)
{
	ofstream os("data.txt");
	inv.WriteInventory(os);
}