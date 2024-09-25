#include "iter.hpp"
#include <iostream>

void initSeed()
{
	static bool seeded = false;
	
	if (!seeded)
	{
		srand(static_cast<unsigned int>(time(0)));
		seeded = true;
	}
}

std::string getType(std::string type)
{
	if (type == typeid(int).name())
		return (getColorStr(FLGREEN, "int"));
	if (type == typeid(float).name())
		return (getColorStr(FLBLUE, "float"));
	if (type == typeid(double).name())
		return (getColorStr(FLCYAN, "double"));
	if (type == typeid(char).name())
		return (getColorStr(FLMAGENTA, "char"));
	if (type == typeid(std::string).name())
		return (getColorStr(FLYELLOW, "string"));
	return (type);
}

int main( void )
{
	::runTest<int>();
	::runTest<float>();
	::runTest<double>();
	::runTest<char>();
	::runTest<std::string>();
	return (0);
}
