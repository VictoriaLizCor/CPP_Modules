/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:38 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/23 12:47:34 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int _bits = 8;

Fixed::Fixed(void):_number(0)
{
	println(sColor("Default constructor called", FGRAY, 0));
	return ;
}

Fixed::~Fixed(void)
{
	println(sColor("Destructor called", FGRAY, 0));
	return ;
}

// rhs = right hand side
Fixed& Fixed::operator=(Fixed const& rhs)
{
	println(sColor("Copy assigment operator called", FGRAY, 0));
	if (this != &rhs)
		_number = rhs.getRawBits();
	return (*this);
}

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
	std::cout << sColor(std::string(__func__), FWHITE, 0)
	<< sColor(" member function called", FGRAY, 0) << std::endl;
	_number = raw;
	return ;
}
