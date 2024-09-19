#include "iter.hpp"
#include <iostream>

std::string getType(std::string type)
{
	if (type == "i")
		return ("int");
	if (type == "f")
		return ("float");
	if (type == typeid(std::string).name())
		return ("string");
	return ("");
}

int main( void )
{
	::runTest<int>();
	::runTest<std::string>();
	return (0);
}
