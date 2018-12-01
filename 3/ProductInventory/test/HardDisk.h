#ifndef HARDDISK_H
#define HARDDISK_H

#include "../lib/Product.h"
#include <string>

class HardDisk : public Product
{
	public:
		HardDisk(std::string name, int price, Date acq, int speed);
		HardDisk();
		
		int GetCurrentPrice() const;
		
		std::string GetType() const { return "HardDisk"; }
		char GetCharCode() const { return CharCode; }
	private:
		int speedRPM;
		static const char CharCode = 'h';
};

#endif
