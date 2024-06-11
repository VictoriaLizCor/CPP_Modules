#include "Point.hpp"

std::string pointInLine(Point const& p1, Point const& p2, Point const& p);
bool bsp(Point const a, Point const b, Point const c, Point const point);

/**
 * @brief Checks if a point is on the edges of a triangle.
 *
 * This function checks if a given point lies on any of the edges of a triangle
 * defined by three points. It prints the results to the standard output.
 *
 * @param a First point of the triangle.
 * @param b Second point of the triangle.
 * @param c Third point of the triangle.
 * @param p Point to check.
 */
void checkOnLines(Point const& a, Point const& b, Point const& c, Point const& p)
{
	std::cout << "\nIs p(" << p.getX() << " , " << p.getY() << ") on edge?" << std::endl;
	std::cout << "line ab: " << pointInLine(a, b, p) << std::endl;
	std::cout << "line bc: " << pointInLine(b, c, p) << std::endl;
	std::cout << "line ac: " << pointInLine(a, c, p) << std::endl;
}

int main(void)
{
	Point a;
	Point b( 0, 20 );
	Point c( 15, 0 );
	Point p1( 20.0f, 0);
	Point p2( 10, 3 );
	Point p3;

	std::cout << "       b(" << b.getX() << ", " << b.getY() << ")                   " << std::endl;
	std::cout << "       * *            " << std::endl;
	std::cout << "       *  *           " << std::endl;
	std::cout << "       *   *            " << std::endl;
	std::cout << "       *    *   p1(" << p1.getX() << ", " << p1.getY() << ")    " << std::endl;
	std::cout << "       *     *            " << std::endl;
	std::cout << "       *  p2  *          " << std::endl;
	std::cout << "p3     *(" << p2.getX() << ", " << p2.getY() << ")*            " << std::endl;
	std::cout << "a(" << a.getX() << ", " << a.getY() << ") ******** "
	<< "c( " << c.getX() << " , " << c.getY() << ")" << std::endl;
	std::cout << std::endl;
	std::cout << std::fixed;
	std::cout.precision(5);
	checkOnLines(a, b, c, p1);
	checkOnLines(a, b, c, p2);
	checkOnLines(a, b, c, p3);
	std::cout << "\nIs p inside of abc?" << std::endl;
	std::cout << "p1: " << bsp(a, b, c, p1) << std::endl;
	std::cout << "p2: " << bsp(a, b, c, p2) << std::endl;
	std::cout << "p3: " << bsp(a, b, c, p3) << std::endl;
	if (DEBUG == 1)
	{
		Point p4( 10, 6.666);

		std::cout << std::fixed;
		std::cout.precision(10);
		checkOnLines(a, b, c, p4);
		std::cout << "\nIs p inside of abc?" << std::endl;
		std::cout << "p1: " << bsp(a, b, c, p4) << std::endl;
	}
	return (0);
}
