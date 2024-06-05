/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:38 by lilizarr          #+#    #+#             */
/*   Updated: 2024/06/05 15:49:42 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void):_intValue(0)
{
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
Fixed::Fixed(int const& number): _intValue(number << _fractionalBits)
{
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
	return ;
}

Fixed::~Fixed(void)
{
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
	if (this != &rhs)
		_intValue = rhs.getRawBits();
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
Fixed:: Fixed(Fixed const& src)
{
	*this = src;
}

/**
 * @brief Overload the << operator for output streams.
 * @param os The output stream.
 * @param source The Fixed object to output.
 * @return The output stream.
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
std::ostream& operator << (std::ostream & os, Fixed const& src)
{
	os << src.toFloat();
	return (os);
}
