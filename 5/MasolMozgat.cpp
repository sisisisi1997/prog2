#include <iostream>
#include <string>

class Labda
{
	private:
		std::string* szin;
		int* meret;
	public:
		int id;
		std::string getSzin()
		{
			return *szin;
		}
		
		int getMeret()
		{
			return *meret;
		}
		
		Labda(std::string szin, int meret)
		{
			std::cout << "Konstruktor belép" << std::endl;
			this->szin = &szin;
			this->meret = &meret;
			std::cout << "Konstruktor kilép" << std::endl;
		}
		
		Labda(const Labda& masik)
		{
			std::cout << "copy ctor belép" << std::endl;
			szin = new std::string(*(masik.szin));
			meret = new int(*(masik.meret));
			std::cout << "copy ctor kilép" << std::endl;
		}
		
		Labda(Labda&& masik)
		{
			std::cout << "move ctor belép (based on move assign)" << std::endl;
			*this = std::move(masik);
			std::cout << "move ctor kilép" << std::endl; 
		}
		
		~Labda()
		{
			if(meret != nullptr)
				delete meret;
			if(szin != nullptr)
				delete szin;
		}
		
		Labda operator=(const Labda& masik)
		{
			std::cout << "copy assignment belép" << std::endl;
			if(this != &masik)
			{
				if(szin != nullptr)
					delete szin;
				if(meret != nullptr)
					delete meret;
				
				*szin = *(masik.szin);
				*meret = *(masik.meret);
			}
			
			std::cout << "copy assignment kilép" << std::endl;
			return *this;
		}
		
		Labda operator=(Labda&& masik)
		{
			std::cout << "move assignment belép" << std::endl;
			if(this != &masik)
			{
				if(szin != nullptr)
					delete szin;
				if(meret != nullptr)
					delete meret;
				
				szin = masik.szin;
				masik.szin = nullptr;
				meret = masik.meret;
				masik.meret = nullptr;
			}
			
			std::cout << "move assignment kilép" << std::endl;
			return *this;
		}
		
		std::string toString()
		{
			"Labda: " + std::to_string(*meret) + ", " + *szin;
		}
		
		Labda copy()
		{
			std::cout << "copy fv belép" << std::endl;
			Labda val = *(new Labda(this->getSzin(), this->getMeret()));
			std::cout << "copy fv kilép" << std::endl;
			return val;
		}
};

int main()
{
	std::cout << "Eredeti hozzárendelés:" << std::endl;
	Labda l1 = *(new Labda("piros", 30));
	std::cout << "\nlvalue hozzárendelése:" << std::endl;
	Labda l2 = l1; // copy assignment
	std::cout << "\nrvalue hozzárendelése:" << std::endl;
	Labda l3 = l1.copy(); // move assignment
	std::cout << "\ncopy ctor hívása:" << std::endl;
	Labda l4 = *(new Labda(l1)); // copy ctor
	std::cout << "\nmove ctor hívása:" << std::endl;
	Labda l5 = *(new Labda(l1.copy())); // move ctor
}