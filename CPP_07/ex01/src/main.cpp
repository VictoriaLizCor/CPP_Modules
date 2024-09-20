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
		return ("int");
	if (type == typeid(float).name())
		return ("float");
	if (type == typeid(double).name())
		return ("double");
	if (type == typeid(char).name())
		return ("char");
	if (type == typeid(std::string).name())
		return ("string");
	return (type);
}

int main( void )
{
	// ::runTest<int>();
	// ::runTest<float>();
	// ::runTest<double>();
	::runTest<std::string>();
	printTitle("", 70, '-');
	return (0);
}
