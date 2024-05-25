/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:42 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/25 13:13:26 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#  define FIXED_HPP
# include <iostream>
# include <sstream>
# include <string>
# include <cmath>

# ifndef DEBUG
#  define DEBUG 0
# endif

/**
 * @class Fixed
 * @brief This class represents a fixed point number.
 */
class Fixed
{
	private:
		int					_intValue;
		static const int	_fractionalBits;
	public:
		// Constructors && destructors
		Fixed(void);
		Fixed(int const& number);
		Fixed(float const& number);
		//Copy assignment operator
		Fixed&	operator=(Fixed const& rhs);
		// Copy constructor
		Fixed(Fixed const& src);
		~Fixed(void);
		// Boolean operators
		bool operator>(Fixed const& rhs) const;
		bool operator<(Fixed const& rhs) const;
		bool operator>=(Fixed const& rhs) const;
		bool operator<=(Fixed const& rhs) const;
		bool operator==(Fixed const& rhs) const;
		bool operator!=(Fixed const& rhs) const;
		// Aritmethic operators
		Fixed operator+(Fixed const& rhs) const;
		Fixed operator-(Fixed const& rhs) const;
		Fixed operator*(Fixed const& rhs) const;
		Fixed operator/(Fixed const& rhs) const;
		// (post/pre)-Increment/decrement operators
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);
		// Member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed max(Fixed& obj1, Fixed& obj2);
		static Fixed max(Fixed const& obj1, Fixed const& obj2);
		static Fixed min(Fixed& obj1, Fixed& obj2);
		static Fixed min(Fixed const& obj1, Fixed const& obj2);
		// Overload of the insertion («) operator
		friend std::ostream& operator << (std::ostream & os, Fixed const& src);
};
#endif
/**
 * NOTES: Fixed-points
 * 
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
 * NOTES: Static member functions in a class have several uses
 * 
 * 1. **Utility Functions**: They can be used as utility functions that are related
 *    to the class but don't operate on an instance of the class. For example, in
 *    your code, `Fixed::max` and `Fixed::min` are utility functions that operate
 *    on `Fixed` objects but don't need to modify or access any specific `Fixed`
 *    object's data.
 * 
 * 2. **Factory Methods**: They can be used as factory methods, which create and
 *    return instances of the class. Factory methods can provide more flexibility
 *    than constructors in creating objects.
 * 
 * 3. **Singleton Pattern**: In the Singleton design pattern, a static member
 *    function is used to get the single instance of the class.
 * 
 * 4. **Access to Static Data Members**: They can be used to access and manipulate
 *    static data members of the class. Static data members are shared by all
 *    instances of the class, and static member functions are often used to control
 *    access to them.
 * 
 * Static member functions can't access non-static data members or non-static
 * member functions directly. They can only access static data members and other
 * static member functions of the class.
*/