#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>

#include "../lib/Product.h"
#include "../lib/Date.h"

class Display : public Product
{
	private:
		int inchWidth;
		int inchHeight;
		
	protected:
		void printParams(std::ostream& os) const;
	public:
		Display(std::string name, int price, Date acq, int width, int height);
		Display();
		
		void writeParamsToStream(std::ostream& os) const;
		void loadParamsFromStream(std::istream& is) const;
		
		std::string GetType() { return "monitor"; }
		char GetCharCode() { return 'd'; }
};

#endif
