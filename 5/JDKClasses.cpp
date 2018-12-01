#include <iostream>
#include "boost/filesystem.hpp"
#include "boost/range/iterator_range.hpp"

using namespace std;
using namespace boost::filesystem;

void traverse(path p)
{
	if(is_directory(p))
	{
		for(auto& entry : boost::make_iterator_range(directory_iterator(p), {}))
		{
			traverse(path(entry));
		}
	}
	else if(is_regular_file(p) && extension(p) == ".java")
	{
		if(p.has_stem())
		{
			cout << p.stem() << endl;
		}
		else
		{
			cout << p.filename() << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	if(argc < 1)
	{
		cout << "Adja meg a JDK forrásainak mappáját!\nHasználat: JDKClasses \"/path/to/JDK/source/\"" << std::endl;
	}
	
	path p {argv[1]};
	traverse(p);
	
}