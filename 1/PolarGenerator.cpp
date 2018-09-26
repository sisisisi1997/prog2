#include <iostream>
#include <random>
#include <math.h>
#include <cstdlib>
#include <time.h>

using namespace std;

class PolarGenerator
{
	public:
		PolarGenerator();
		double kovetkezo();
		
	private:
		bool	nincsTarolt;
		double	tarolt;
		double	randomDouble();
};

double PolarGenerator::randomDouble()
{
	return (double)rand() / ((double)RAND_MAX + 1); // így egy 0 és 1 közötti random számot kapunk - a + 1 azért van hogy mint a java kódban, [0, 1[ legyen, ne [0, 1]
}

PolarGenerator::PolarGenerator()
{
	tarolt = true;
}

double PolarGenerator::kovetkezo()
{
	if(nincsTarolt) // le kell futtatnunk az algoritmust
	{
		double u1, u2, v1, v2, w;
		do
		{
			// u1 és u2 a [0.0, 1.0[ tartományban kapnak értéket
			u1 = randomDouble();
			u2 = randomDouble();
			// v1 és v2 a [-1.0, 1.0[ tartományban kapnak értéket
			v1 = 2 * u1 - 1;
			v2 = 2 * u2 - 1;
			// w a [0.0, 2.0[ tartományban kap értéket - a négyzet elveszi a negatív előjelet, 0 és 1 közötti abszolútértékű számok pedig négyzetre emelve is 0 és 1 között maradnak
			w = v1 * v1 + v2 * v2;
		}
		while(w > 1);
		// ugye ennek a kódnak az eredeti készítője tudja, hogy w lehet 0? Mindössze csillagászati az esélye - mindössze u1-nek és u2-nek is 0.5-nek kell lennie
		double r = sqrt((-2 * log(w)) / w);
		tarolt = r * v2; // eltároljuk az egyik random eredményt
		nincsTarolt = !nincsTarolt; // hamisra állítjuk
		return r * v1; // visszaadjuk a másik random eredményt
	}
	else
	{
		nincsTarolt = !nincsTarolt; // igazra állítjuk
		return tarolt; // visszaadjuk "az egyik" random eredményt
	}
}

int main()
{
	srand(time(NULL));
	PolarGenerator p;
	for(int i = 0; i < 10; ++ i)
	{
		cout << p.kovetkezo() << endl;
	}
}
