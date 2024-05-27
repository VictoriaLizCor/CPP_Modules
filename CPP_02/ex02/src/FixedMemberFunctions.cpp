#include "Fixed.hpp"

/**
 * @brief Retrieves the raw value of the fixed point number.
 *
 * This function returns the raw integer value of the fixed point number
 * represented by this instance of the Fixed class. It also prints a message
 * indicating that the function was called.
 * @return The raw integer value of the fixed point number.
 * *`const`: This keyword means that the function does not modify any member
 * variables of the `Fixed` class. It's a promise that calling this function will
 * 
 */
int	Fixed::getRawBits(void) const
{
	return (_intValue);
}

/**
 * @brief Sets the raw value of the fixed point number.
 *
 * This function sets the raw integer value of the fixed point number
 * represented by this instance of the Fixed class. It also prints a message
 * indicating that the function was called.
 *
 * @param raw The raw integer value to set the fixed point number to.
 * `const`declaration can be (int const | const int) but for string is
 * always use const std::string
 * 
 */
void Fixed::setRawBits(int const raw)
{
	_intValue = raw;
	return ;
}

/**
 * @brief Converts the fixed point number to a floating point number.
 * 
 * This function divides the fixed point number by the number of fractional bits
 * shifted to the left by 1, effectively converting the fixed point number to a 
 * floating point number.
 * 
 * @return float The converted floating point number.
 * `1 << _fractionalBits`: This is a bitwise left shift operation. It shifts
 * the binary representation of `1` to the left by `_fractionalBits` places.
 * This is equivalent to calculating `2^_fractionalBits`. The result of this
 * operation is the number of fractional units that make up `1` in the
 * fixed-point representation.
*/
float Fixed::toFloat(void) const
{
	float f;
	f = static_cast<float>(_intValue) / static_cast<float>(1 << _fractionalBits);
	return (f);
}

/**
 * @brief Converts the fixed point number to an integer by shifting the bits.
 * 
 * This function shifts the bits of the number to the right by the number of 
 * fractional bits, effectively converting the fixed point number to an integer.
 * 
 * @return int The converted integer.
 */
int Fixed::toInt(void) const
{
	float f = toFloat();
	float res = f - static_cast<int>(f);

	if (res > 0.5f)
		return ((_intValue >> _fractionalBits) + 1);
	return (static_cast<int>(f));
}

/**
 * @brief Returns the maximum of two Fixed objects.
 * 
 * @param obj1 The first Fixed object.
 * @param obj2 The second Fixed object.
 * @return Fixed The maximum of obj1 and obj2.
 */
Fixed Fixed::max(Fixed& obj1, Fixed& obj2)
{
	if (obj1 > obj2)
		return (obj1);
	return (obj2);
}


/**
 * @brief Returns the maximum of two const Fixed objects.
 * 
 * @param obj1 The first const Fixed object.
 * @param obj2 The second const Fixed object.
 * @return Fixed The maximum of obj1 and obj2.
 */
Fixed Fixed::max(Fixed const& obj1, Fixed const& obj2)
{
	if (obj1 > obj2)
		return (obj1);
	return (obj2);
}

/**
 * @brief Returns the minimum of two Fixed objects.
 * 
 * @param obj1 The first Fixed object.
 * @param obj2 The second Fixed object.
 * @return Fixed The minimum of obj1 and obj2.
 */
Fixed Fixed::min(Fixed& obj1, Fixed& obj2)
{
	if (obj1 < obj2)
		return (obj1);
	return (obj2);
}

/**
 * @brief Returns the minimum of two const Fixed objects.
 * 
 * @param obj1 The first const Fixed object.
 * @param obj2 The second const Fixed object.
 * @return Fixed The minimum of obj1 and obj2.
 */
Fixed Fixed::min(Fixed const& obj1, Fixed const& obj2)
{
	if (obj1 < obj2)
		return (obj1);
	return (obj2);
}

#if (DEBUG == 1)
float	Fixed::MinValue(void) const
{
	float f = 1.0 / (1 << _fractionalBits);
	return (f);
}

int Fixed::getFractionalBits(void) const
{
	return (_fractionalBits);
}

float	Fixed::MaxValue(void) const
{
	float f = (1 << (32 - _fractionalBits - 1)) - 1 + MinValue() * 255;
	return (f);
}
#endif