#ifndef COMPLEX_STRINGNUMBER_H
#define COMPLEX_STRINGNUMBER_H

#include "StringNumber.hpp"
#include <string>

class ComplexStringNumber : public StringNumber
{
	public:
						ComplexStringNumber(std::string);
		
		std::string		toString();
		
		bool			isGreaterThan(ComplexStringNumber);
		bool			isLessThan(ComplexStringNumber);
		bool			isEqualTo(ComplexStringNumber);
	private:
		bool			isign;
		std::string		iwholePart,
						ifractionalPart;
};

#endif
