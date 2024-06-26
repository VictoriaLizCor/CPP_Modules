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
int Fixed::getRawBits(void) const
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
	return;
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
Fixed Fixed::max(Fixed &obj1, Fixed &obj2)
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
Fixed Fixed::max(Fixed const &obj1, Fixed const &obj2)
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
Fixed Fixed::min(Fixed &obj1, Fixed &obj2)
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
Fixed Fixed::min(Fixed const &obj1, Fixed const &obj2)
{
	if (obj1 < obj2)
		return (obj1);
	return (obj2);
}

#if (DEBUG != 0)
float Fixed::MinValue(void) const
{
	float f = 1.0 / (1 << _fractionalBits);
	return (f);
}

static int powerExp2(int n)
{
	int i = 0;
	int res = 1;

	while (i++ < n)
		res *= 2;
	return (res);
}


float Fixed::MaxValue(void) const
{
	float max;
	int intBits = sizeof(int) * 8;
	int power2Exponent = intBits - _fractionalBits;
	int power2Fractional = (1 << _fractionalBits);

	max = ((powerExp2(power2Exponent) >> _fractionalBits) - 1) + ((float)(power2Fractional - 1) / (float)power2Fractional);
	return (max);
}

Fixed::Fixed(double const& number)
{
	setRawBits(static_cast<int>(round(number * ( 1 << _fractionalBits))));
	return ;
}

double Fixed::toDouble(void) const
{
	double d;
	d = static_cast<double>(_intValue) / static_cast<double>(1 << _fractionalBits);
	return (d);
}

/**
 * (sizeof(int) * 8) - _fractionalBits = 
 * 32 - 8 = 24
 * signed integer is 
 * ((2^23) - 1) + 255/256 =
 *  8388607 + 255/256 =
*/

#endif

// 0 10000001 10000000000000000000000