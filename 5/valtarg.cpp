#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 1)
	{
		cout << "Adja meg a képfájl nevét!" << endl;
		return 1;
	}
	
	string path = argv[0];
	
	/*
	 * TODO: libpng linkelése, hogy be tudja olvasni a képet amit feldolgozunk majd
	 /
}