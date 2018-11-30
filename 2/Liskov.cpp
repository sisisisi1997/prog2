#include <iostream>
#include "StringNumber.hpp"
#include "ComplexStringNumber.hpp"

int main()
{
	ComplexStringNumber num1 = ComplexStringNumber("-12.36+1.2i");
	ComplexStringNumber num2 = ComplexStringNumber("+3-11.1i");
	std::cout << num1.toString() << std::endl;
	std::cout << num2.toString() << std::endl;
	
	std::cout << num1.isGreaterThan(num2) << std::endl;
}