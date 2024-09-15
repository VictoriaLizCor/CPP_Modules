#include "Data.hpp"
#include <iostream>
/**
 * @brief print data of struct data
 * 
 * @param type name of data struct
 */
void Data::print(std::string type) const
{
	printTitle(type, 30, '=');
	std::cout << "Char: " << c << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << f << std::endl;
	std::cout << "Double: " << d << std::endl;
}

/**
 * @brief set function for struct data
 * 
 * @param newC new assigment for char
 * @param newI new assigment for int
 * @param newF new assigment for float
 * @param newD new assigment for double
 */
void Data::setData(char newC, int newI, float newF, double newD)
{
	c = newC;
	i = newI;
	f = newF;
	d = newD;
}

