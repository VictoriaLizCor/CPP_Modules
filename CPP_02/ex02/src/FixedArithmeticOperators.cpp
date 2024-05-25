#include "Fixed.hpp"

/**
 * @brief Overloads the '+' operator for the Fixed class.
 * @param rhs The Fixed object to add to the current object.
 * @return A new Fixed object that is the sum of this object and rhs.
 */
Fixed Fixed::operator+(Fixed const& rhs) const
{
	return (Fixed(toFloat() + rhs.toFloat()));
}

/**
 * @brief Overloads the '+' operator for the Fixed class.
 * @param rhs The Fixed object to add to the current object.
 * @return A new Fixed object that is the sum of this object and rhs.
 */
Fixed Fixed::operator-(Fixed const& rhs) const
{
	return (Fixed(toFloat() - rhs.toFloat()));
}

/**
 * @brief Overloads the '*' operator for the Fixed class.
 * @param rhs The Fixed object to multiply with the current object.
 * @return A new Fixed object that is the product of this object and rhs.
 */
Fixed Fixed::operator*(Fixed const& rhs) const
{
	return (Fixed(toFloat() * rhs.toFloat()));
}

/**
 * @brief Overloads the '/' operator for the Fixed class.
 * @param rhs The Fixed object to divide the current object by.
 * @return A new Fixed object that is the quotient of this object and rhs.
 */
Fixed Fixed::operator/(Fixed const& rhs) const
{
	return (Fixed(toFloat() / rhs.toFloat()));
}

/**
 * @brief Overloads the '/' operator for the Fixed class.
 * @param rhs The Fixed object to divide the current object by.
 * @return A new Fixed object that is the quotient of this object and rhs.
 */
Fixed& Fixed::operator++(void)
{
	_intValue += 1;
	return (*this);
}

/**
 * @brief Overloads the post-increment operator for the Fixed class.
 * @return A copy of the current object before it was incremented.
 */
Fixed Fixed::operator++(int)
{
	Fixed cpy(*this);

	++(*this);
	return (cpy);
}

/**
 * @brief Overloads the pre-decrement operator for the Fixed class.
 * @return A reference to the current object after it has been decremented.
 */
Fixed& Fixed::operator--(void)
{
	_intValue -= 1;
	return (*this);
}

/**
 * @brief Overloads the post-decrement operator for the Fixed class.
 * @return A copy of the current object before it was decremented.
 */

Fixed Fixed::operator--(int)
{
	Fixed cpy(*this);

	--(*this);
	return (cpy);
}