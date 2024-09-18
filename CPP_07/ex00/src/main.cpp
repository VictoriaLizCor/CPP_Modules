#include "whatever.hpp"
#include <sstream>
#include <iostream>




int main(void)
{
	int a, ax;
	int b, bx;
	a = ax = 3;
	b = bx = 1;

	std::cout << "a = " << ::checkType(ax, bx, a) << ", b = " << ::checkType(ax, bx, b) << std::endl;
	::swap( a, b );
	std::cout << "a = " << ::checkType(ax, bx, a) << ", b = " << ::checkType(ax, bx, b) << std::endl;
	std::cout << "min( a, b ) = " << ::checkType(ax, bx,::min( a, b)) << std::endl;
	std::cout << "max( a, b ) = " << ::checkType(ax, bx, ::max( a, b)) << std::endl;
	std::string c, cx;
	std::string d, dx;
	c = cx = "chaine1";
	d = dx = "chaine2";
	::swap(c, d);
	std::cout << "c = " << ::checkType(cx, dx, c) << ", d = " << ::checkType(cx, dx, d) << std::endl;
	std::cout << "min( c, d ) = " << ::checkType(cx, dx,::min( c, d )) << std::endl;
	std::cout << "max( c, d ) = " << ::checkType(cx, dx,::max( c, d )) << std::endl;

	return (0);
}