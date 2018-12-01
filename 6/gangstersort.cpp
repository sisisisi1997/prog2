#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

class Coordinate
{
	public:
		Coordinate(int x, int y)
		{
			this->X = x;
			this->Y = y;
		}
		
		int X, Y;
};

int main()
{
	Coordinate cop = Coordinate(17, 25);
	std::vector<Coordinate> gangsters;
	
	gangsters.push_back(Coordinate(1, 5));
	gangsters.push_back(Coordinate(12, 10));
	gangsters.push_back(Coordinate(35, 7));
	gangsters.push_back(Coordinate(15, 23));
	gangsters.push_back(Coordinate(0, 0));
	gangsters.push_back(Coordinate(40, 43));
	gangsters.push_back(Coordinate(2, 5));
	gangsters.push_back(Coordinate(13, 42));
	
	std::sort(gangsters.begin(), gangsters.end(), [cop](Coordinate a, Coordinate b)
	{
		return sqrt(pow(abs(cop.X - b.X), 2) + pow(abs(cop.Y - b.Y), 2)) > sqrt(pow(abs(a.X - cop.X), 2) + pow(abs(a.Y - cop.Y), 2));
	});
	
	std::cout << "Legközelebbi gengszter: [" << gangsters.at(0).X << ", " << gangsters.at(0).Y << "]" << std::endl;
}