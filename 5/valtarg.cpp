#include <iostream>
#include <string>

#include "png++/png.hpp"
#include "nlp.hpp"

int main(int argc, char* argv[])
{
	if(argc < 1)
	{
		std::cout << "Adja meg a képfájl nevét!" << std::endl;
		return 1;
	}
	
	std::string path = argv[1];
	
	std::cout << "Bemeneti kép: " << path << std::endl;
	png::image <png::rgb_pixel> image (path);
	int size = image.get_width() * image.get_height();
	std::cout << "Méret: " << image.get_width() << "x" << image.get_height() << std::endl;
	
	std::cout << "Perceptron futtatása" << std::endl;
	Perceptron* p = new Perceptron(3, size, 256, 1);
	std::cout << "Perceptron lefuttatva" << std::endl << "Vörös kép létrehozása" << std::endl;
	
	double* redImage = new double[size];
	
	for(int i = 0; i < image.get_width(); ++ i)
	{
		for(int j = 0; j < image.get_height(); ++ j)
		{
			redImage[i * image.get_width() + j] = image[j][i].red;
		}
	}
	
	std::cout << "Vörös kép létrehozva" << std::endl << "Vörös kép feldolgozása..." << std::endl;
	
	double* feldolgozott = (*p)(redImage);
	
	std::cout << "Vörös kép feldolgozva" << std::endl << "Eredmény létrehozása" << std::endl;
	
	png::image<png::rgb_pixel> img2(image.get_width(), image.get_height());
	
	for(int i = 0; i < image.get_width(); ++ i)
	{
		for(int j = 0; j < image.get_height(); ++ j)
		{
			img2[j][i].red = feldolgozott[i * image.get_width() + j];
		}
	}
	
	img2.write("redsigmoid.png");
	
	std::cout << "Eredmény létrehozva, kiírva" << std::endl;
}