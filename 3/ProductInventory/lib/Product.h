#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include "Date.h"

class Product
{
	protected:
		// Beszerzési ár
		int initialPrice;
		// Beszerzés dátuma
		Date dateOfAcquisition;
		// Név
		std::string name;
		// custom paraméterek kiírása overloadolt metódusban
		virtual void printParams(std::ostream& os) const;
		// custom paraméterek betöltése streamről
		virtual void loadParamsFromStream(std::istream& is);
		// custom paraméterek kiírása streamre
		virtual void writeParamsToStream(std::ostream& os) const;
	public:
		// konstruktor és destruktor
		Product();
		Product(std::string name, int initialPrice, Date dateOfAcquisition);
		virtual ~Product() {};
		// getterek a privát tulajdonságokhoz és számolt tulajdonságokhoz
		// A functionök utáni const; minden getterben pure functionné teszi az adott gettert
		int GetInitialPrice() const;
		std::string GetName() const;
		Date GetDateOfAcquisition() const;
		int GetAge() const;
		virtual int GetCurrentPrice() const;
		// nem overloadolható, alap tulajdonságok kiírása
		void Print(std::ostream& os) const;
		// azonosítók, overloadolandó minden gyerekosztályban
		virtual std::string GetType() const = 0;
		virtual char GetCharCode() const = 0;
		
		//sorba rendezés név szerint CompositeProductban
		bool operator < (const Product& other)const { std::locale loc; return loc(name, other.name); }
		
		// a >> és << operátorok nem tagjai a Product osztálynak, de hozzá fognak férni a privát tagjaihoz
		friend std::istream& operator>>(std::istream& is, Product& product);
		friend std::ostream& operator<<(std::ostream& os, const Product& product);
};

#endif
