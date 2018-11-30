#include <iostream>

class Szulo
{
	public:
		void toBeOverridden()
		{
			std::cout << "Szulo" << std::endl;
		}
		
		virtual void toBeOverriddenVirtual()
		{
			std::cout << "Szulo virtuális" << std::endl;
		}
};

class Gyerek : public Szulo
{
	public:
		Gyerek() {}
		Gyerek(Szulo& forras) {}
		
		void toBeOverridden()
		{
			std::cout << "Gyerek" << std::endl;
		}
		
		virtual void toBeOverriddenVirtual()
		{
			std::cout << "Gyerek virtuális" << std::endl;
		}
		
		void csakGyerek()
		{
			std::cout << "Ez a metódus csak a gyerekben található meg" << std::endl;
		}
};

int main()
{
	Szulo szulo = Gyerek();
	
	szulo.toBeOverridden();
	szulo.toBeOverriddenVirtual();
	((Gyerek)szulo).toBeOverriddenVirtual();
	((Gyerek)szulo).csakGyerek();
}