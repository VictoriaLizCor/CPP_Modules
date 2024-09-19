#include "whatever.hpp"
#include <sstream>
#include <iostream>


static void test (void)
{
	int a = 3;
	int b = 3;

	std::cout << "a = " << ::checkType(a, b, a) << ", b = " << ::checkType(a, b, b) << std::endl;
	::swap( a, b );
	std::cout << "a = " << ::checkType(a, b, a) << ", b = " << ::checkType(a, b, b) << std::endl;
	std::cout << "min( a, b ) = " << ::checkType(a, b, ::min( a, b)) << std::endl;
	std::cout << "max( a, b ) = " << ::checkType(a, b, ::max( a, b)) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << ::checkType(c, d, c) << ", d = " << ::checkType(c, d, d) << std::endl;
	::swap(c, d);
	std::cout << "c = " << ::checkType(c, d, c) << ", d = " << ::checkType(c, d, d) << std::endl;
	std::cout << "min( c, d ) = " << ::checkType(c, d,::min( c, d )) << std::endl;
	std::cout << "max( c, d ) = " << ::checkType(c, d,::max( c, d )) << std::endl;

}

int main(void)
{
	if (DEBUG)
		test();
	else
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return (0);
}