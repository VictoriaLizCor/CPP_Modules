#include <Point.hpp>

Point::Point(void): _x(0), _y(0){}

Point::Point(float const& x, float const& y):_x(Fixed(x)), _y(Fixed(y)){}

Point::Point( Point const& src ): _x(src._x), _y(src._y){}

Point::~Point(void){}

Point& Point::operator = (Point const &rhs)
{
	(void)rhs;
	return (*this);
}

float Point::getX(void) const
{
	return (_x.toFloat());
}

float Point::getY(void) const
{
	return (_y.toFloat());
}

float Point::epsilon() const
{
	return (_x.minValue());
}