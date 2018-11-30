#ifndef STRINGNUMBER_H
#define STRINGNUMBER_H

#include <string>

class StringNumber
{
	public:
								StringNumber(std::string);
		
		virtual std::string		toString(void);
		virtual bool			isGreaterThan(StringNumber);
		virtual bool			isEqualTo(StringNumber);
		virtual bool			isLessThan(StringNumber);
	protected:
								StringNumber(void);
		
		bool					sign;
		std::string				wholePart,
								fractionalPart;
		
		void					initFrom(std::string);
};

#endif
