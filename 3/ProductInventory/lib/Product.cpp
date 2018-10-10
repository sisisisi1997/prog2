#include "Product.h"

// pl. a stringet felismeri így std:: nélkül mert automatikusan végigkeresi a névteret
using namespace std;

Product::Product()
{}

// copy ctor-ok hívásával állítjuk be a különböző fieldeket
Product::Product(std::string name, int initalPrice, Date acqDate):
	name(name),
	initialPrice(initialPrice),
	dateOfAcquisition(acqDate)
{}

// implementáljuk a gettereket
int Product::GetInitialPrice() const
{
	return initialPrice;
}

string Product::GetName() const
{
	return name;
}

Date Product::GetDateOfAcquisition() const
{
	return dateOfAcquisition;
}

int Product::GetAge() const
{
	return dateOfAcquisition.GetElapsedDays();
}

int Product::GetCurrentPrice() const
{
	return initialPrice;
}

// stream támogatás és kiírás
void Product::Print(ostream& os) const
{
	os << "Type: " << GetType() << ", ";
	os << "Name: " << GetName();
	printParams(os);
}

void Product::printParams(ostream& os) const
{
	os	<< ", " << "InitialPrice: " << initialPrice 
		<< ", " << "DateOfAcquisition: " << dateOfAcquisition
		<< ", " << "Age: " << GetAge()
		<< ", " << "Current price: " << GetCurrentPrice();
}

void Product::loadParamsFromStream(istream& is)
{
	is >> name;
	is >> initialPrice;
	is >> dateOfAcquisition;
}

void Product::writeParamsToStream(std::ostream& os) const
{
	os << ' ' << name << ' ' << initialPrice << ' ' << dateOfAcquisition;
}

// << és >> operátorok
istream& operator>>(istream& is, Product& product) 
{
	product.loadParamsFromStream(is);
	return is;
}

ostream& operator<<(ostream& os, const Product& product) 
{
	os << product.GetCharCode();
	product.writeParamsToStream(os);
	return os;
}