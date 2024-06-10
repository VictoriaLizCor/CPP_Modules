#include "Point.hpp"

#if (DEBUG == 0)

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a;
	Point b( 0, 20 );
	Point c( 20, 0 );
	Point p1( 15.0f, 14.999f );
	Point p2( 10, 3 );
	Point p3;

	std::cout << "      b(0,20)                   " << std::endl;
	std::cout << "      | \\            " << std::endl;
	std::cout << "      |  \\           " << std::endl;
	std::cout << "      |   \\            " << std::endl;
	std::cout << "      |    \\   p1    " << std::endl;
	std::cout << "      |     \\            " << std::endl;
	std::cout << "      |  p2  \\          " << std::endl;
	std::cout << "p3    |       \\            " << std::endl;
	std::cout << "a(0,0) -------- c(10,0)" << std::endl;
	std::cout << std::endl;
	std::cout << "Is p inside of abc?" << std::endl;
	std::cout << "p1: " << bsp(a, b, c, p1) << std::endl;
	std::cout << "p2: " << bsp(a, b, c, p2) << std::endl;
	std::cout << "p3: " << bsp(a, b, c, p3) << std::endl;
}
#endif