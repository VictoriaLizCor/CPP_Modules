/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:38 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/24 16:39:02 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void):_number(0)
{
	println(sColor("Default constructor called", FGRAY, 0));
	return ;
}

/**
* @brief Constructor that initializes the Fixed object from an integer.
 * 
* @param number The integer to initialize the Fixed object with. The integer
* is shifted left by _fractionalBits places to create the fixed-point
* representation.
 * 
* This constructor also prints a message indicating that it was called. 
 * The bitwise left shift operator. When applied to an integer, it shifts the binary
 * representation of that integer to the left by a specified number of places.
 * This is equivalent to multiplying the number by 2 raised to the power of the
 * number of places shifted.
 */
Fixed::Fixed(int const& number): _number(number << _fractionalBits)
{
	println(sColor("Int constructor called", FGRAY, 0));
	return ;
}

/**
 * @brief Constructor that initializes the Fixed object from a float.
 * 
 * @param number The float to initialize the Fixed object with. The float
 * is multiplied by 2 raised to the power of _fractionalBits, rounded to
 * the nearest integer, and then stored as a fixed-point number.
 * 
 * This constructor also prints a message indicating that it was called.
 */
Fixed::Fixed(float const& number)
{
	setRawBits(static_cast<int>(roundf(number * ( 1 << _fractionalBits))));
	println(sColor("Float constructor called", FGRAY, 0));
	return ;
}

Fixed::~Fixed(void)
{
	println(sColor("Destructor called", FGRAY, 0));
	return ;
}

/**
 * @brief Overloaded assignment operator for the Fixed class.
 *
 * This operator is called when an existing Fixed object is assigned the values
 * of another Fixed object. It prints a message to indicate that the assignment
 * operator has been called and then checks if the source object is not the same
 * as the target object. If they are different, it copies the values from the
 * source object.
 *
 * @param rhs The Fixed object to assign from.
 * Where rhs stands for 'right hand side'
 * @return A reference to the current object.
 */
Fixed& Fixed::operator=(Fixed const& rhs)
{
	println(sColor("Copy assigment operator called", FGRAY, 0));
	if (this != &rhs)
		_number = rhs.getRawBits();
	return (*this);
}

/**
 * @brief Copy constructor for the Fixed class.
 * 
 * This constructor is called when a new object is created as a copy of an 
 * existing Fixed object. It prints a message to indicate that the copy 
 * constructor has been called and then uses the assignment operator to copy 
 * the values from the source object.
 * 
 * @param source The Fixed object to copy from.
 */
Fixed:: Fixed(Fixed const& source)
{
	println(sColor("Copy constructor called", FGRAY, 0));
	*this = source;
}

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
	return (_number);
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
	_number = raw;
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
	f = static_cast<float>(_number) / static_cast<float>(1 << _fractionalBits);
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
		return ((_number >> _fractionalBits) + 1);
	return (static_cast<int>(f));
}

/**
 * @brief 
 * 
 * The `friend` keyword is not specific to any version of C++, it has been part
 * of the language since the beginning. It is used to grant a non-member function
 * or another class access to the private and protected members of the class
 * where it's declared.
 * 
 * In the context of overloading the `<<` operator for a custom class, the
 * `friend` keyword is used because the `<<` operator is a binary operator that
 * is usually implemented as a non-member function. This is because the
 * left-hand operand of the `<<` operator is an `std::ostream` object, not an
 * object of your custom class.
 *
 * However, this non-member function still needs to access the private data of
 * custom class to do its job. By declaring this function as a `friend` of custom
 * class, it's granting the necessary access.

*/
std::ostream& operator << (std::ostream & os, Fixed const& source)
{
	os << source.toFloat();
	return (os);
}


/**
 * NOTES:
 * In fixed-point representation, a number is represented as an integer and a
 * fractional part. The number of fractional units that make up `1` in the
 * fixed-point representation refers to how many fractional units are equivalent
 * to `1` in this representation.
 * 
 * For example, if `_fractionalBits` is `8`, then `1 << _fractionalBits` equals
 * `256`. This means that `1` in the fixed-point representation is equivalent to
 * `256` fractional units. 
 * 
 * So, if you have a fixed-point number represented as `256` (in the integer part),
 * it is equivalent to `1` in the normal decimal system. If the fixed-point number
 * is `512`, it is equivalent to `2` in the decimal system, and so on.
 * 
 * This is useful when you want to convert between floating-point numbers and
 * fixed-point numbers. By multiplying a floating-point number by the number of
 * fractional units that make up `1`, you can convert the floating-point number to
 * a fixed-point number. Conversely, by dividing a fixed-point number by the number
 * of fractional units that make up `1`, you can convert the fixed-point number to
 * a floating-point number.
 * 
*/