#include <iostream>
#include "boost/filesystem.hpp"

using namespace std;
using namespace boost::filesystem;

int main(int argc, char* argv[])
{
	if(argc < 1)
	{
		cout << "Adja meg a JDK forrásainak mappáját!\nHasználat: JDKClasses \"/path/to/JDK/source/\"" << std::endl;
	}
	
	
}