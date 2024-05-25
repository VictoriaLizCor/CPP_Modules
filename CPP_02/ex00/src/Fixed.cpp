/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:38 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/25 11:20:27 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int _bits = 8;

Fixed::Fixed(void):_intValue(0)
{
	println(sColor("Default constructor called", FGRAY, 0));
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
	std::cout << sColor(std::string(__func__), FWHITE, 0)
	<< sColor(" member function called", FGRAY, 0) << std::endl;
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
	std::cout << sColor(std::string(__func__), FWHITE, 0)
	<< sColor(" member function called", FGRAY, 0) << std::endl;
	_intValue = raw;
	return ;
}
