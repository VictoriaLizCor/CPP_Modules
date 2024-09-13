#include "Data.hpp"
#include <iostream>

void Data::print(std::string type) const
{
	printTitle(type, 30, '=');
	std::cout << "Char: " << c << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << f << std::endl;
	std::cout << "Double: " << d << std::endl;
}

void Data::setData(char newC, int newI, float newF, double newD)
{
	c = newC;
	i = newI;
	f = newF;
	d = newD;
}