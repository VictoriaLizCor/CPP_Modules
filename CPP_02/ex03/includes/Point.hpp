#ifndef POINT_HPP
# define POINT_HPP
#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point(void);
		Point(float const& x, float const& y);
		Point(Point const& rhs);
		virtual ~Point(void);
		Point& operator = (Point const& rhs);
		float getX(void) const;
		float getY(void) const;
		float epsilon(void) const;

};

#endif