#include <iostream>
#include <string>

#include "png.h"

int main(int argc, char* argv[])
{
	if(argc < 1)
	{
		std::cout << "Adja meg a képfájl nevét!" << std::endl;
		return 1;
	}
	
	std::string path = argv[0];
	
	
}