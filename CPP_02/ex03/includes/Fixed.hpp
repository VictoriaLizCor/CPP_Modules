/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:42 by lilizarr          #+#    #+#             */
/*   Updated: 2024/06/10 16:26:01 by lilizarr         ###   ########.fr       */
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
		float	maxValue(void) const;
		float	minValue(void) const;
		double 	toDouble(void) const;
		Fixed(double const& number);
};
#endif
/**
 * NOTES: Fixed-points
 * (-1)*ŝign * 1.mantissa * 2^(exponent - bias(=127))
 * Max number depends on the number of bits used to represent the number.
 * (sizeof(int) * 8) - _fractionalBits = 32 - 8 = 24 Max. value with 24 bit
 * signed integer is ((2^23) - 1) + 255/256 = 8388607 + 255/256 =
 * 8388607.99609375 In fixed-point representation, a number is represented as an
 * integer and a fractional part. The number of fractional units that make up
 * `1` in the fixed-point representation refers to how many fractional units are
 * equivalent to `1` in this representation.
 *
 * For example, if `_fractionalBits` is `8`, then `1 << _fractionalBits` equals
 * `256`. This means that `1` in the fixed-point representation is equivalent to
 * `256` fractional units. 
 *
 * So, if you have a fixed-point number represented as `256` (in the integer
 * part), it is equivalent to `1` in the normal decimal system. If the
 * fixed-point number is `512`, it is equivalent to `2` in the decimal system,
 * and so on.
 *
 * This is useful when you want to convert between floating-point numbers and
 * fixed-point numbers. By multiplying a floating-point number by the number of
 * fractional units that make up `1`, you can convert the floating-point number
 * to a fixed-point number. Conversely, by dividing a fixed-point number by the
 * number of fractional units that make up `1`, you can convert the fixed-point
 * number to a floating-point number.
 *
 * The `float` type in C++ is typically implemented using IEEE 754
 * single-precision floating-point format, which uses 23 bits for the fraction
 * (also known as the significand or mantissa), 8 bits for the exponent, and 1
 * bit for the sign. This allows it to represent very small values like
 * `FLT_MIN`.
 *
 * However, a fixed-point number with 23 fractional bits can only represent
 * values down to 1 / 2^23 (approximately 1.1920929e-7) with a precision of 1 /
 * 2^23. This is much larger than `FLT_MIN`, so when you try to convert
 * `FLT_MIN` to a fixed-point number, it gets rounded down to zero.
 *
 *
 * NOTES: Static member functions in a class have several uses
 *
 * 1. **Utility Functions**: They can be used as utility functions that are
 *    related to the class but don't operate on an instance of the class. For
 *    example, in your code, `Fixed::max` and `Fixed::min` are utility functions
 *    that operate on `Fixed` objects but don't need to modify or access any
 *    specific `Fixed` object's data.
 *
 * 2. **Factory Methods**: They can be used as factory methods, which create and
 *    return instances of the class. Factory methods can provide more
 *    flexibility than constructors in creating objects.
 *
 * 3. **Singleton Pattern**: In the Singleton design pattern, a static member
 *    function is used to get the single instance of the class.
 *
 * 4. **Access to Static Data Members**: They can be used to access and
 *    manipulate static data members of the class. Static data members are
 *    shared by all instances of the class, and static member functions are
 *    often used to control access to them.
 *
 * Static member functions can't access non-static data members or non-static
 * member functions directly. They can only access static data members and other
 * static member functions of the class.
 *
 * NOTES: FLOAT POINT REPRESENTATION 
 * V = (-1)^S * 2^E * 1.M
 * V = (-1)^0 * 2^4 * 1.10110011001100110011010
 *  M = 1*2^0 + 0*2^-1 + 1*2^-2 + 1*2^-3 + 0*2^-4 +
 * 0*2^-5 + 1*2^-6 + 1*2^-7 + 0*2^-8 + 0*2^-9 + 1*2^-10 + 1*2^-11 + 0*2^-12 +
 * 0*2^-13 + 1*2^-14 + 1*2^-15 + 0*2^-16 + 0*2^-17 + 1*2^-18 + 0*2^-19 + 1*2^-20
 * + 0*2^-21 + 1*2^-22
 * 128 - 127 = 1
 * 127 - 127 = 0
 * 126 - 127 = -1 
 * 104 - 127 = -23
 * V = (-1)^0 * ( * 2^-23)
 * The exponents are biased by half of their possible value. 
 * It means you subtract this bias from the stored exponent to get 
 * the actual exponent. If the stored exponent is less than the bias, 
 * it's actually a negative exponent. 
 * Use"excess-127" notation,that is, 8-bit stored exponents can range 
 * from -127 to 127, stored as 0 to 254. The value 2127 is roughly 
 * equivalent to 1038, which is the actual limit of single-precision.
 * Positive infinity binary: 01111111100000000000000000000000
 * Negative infinity binary: 11111111100000000000000000000000
 * 
 * The float value you're looking at is represented in IEEE 754 floating-point
 *   standard. This standard represents floating-point numbers in binary format
 *   with three components: the sign bit, the exponent, and the fraction (also
 *   known as the mantissa).
 * 
 * In your case, the float value
 * `340282346638528859811704183484516925440.000000000000000` is represented as
 * `(1.999999880790710 * 2^127)`. 
 * 
 * The binary representation is `0 11111110 11111111111111111111111`, where:
 * 
 * - `0` is the sign bit, indicating a positive number.
 * - `11111110` is the exponent, which is 254 in decimal. However, the exponent is
 *   stored as an "excess-127" value, meaning that 127 is subtracted from the
 *   actual exponent to get the stored exponent. So, the actual exponent is `254 -
 *   127 = 127`.
 * - `11111111111111111111111` is the fraction (mantissa). This represents the
 *   number `1.999999880790710` in binary. The leading 1 (for numbers not close to
 *   zero) is not stored, and the fraction represents the part after the decimal
 *   point.
 * 
 * So, to get the exponent bytes `11111110`, you need to add 127 to your actual
 * exponent (in this case, 127), which gives you 254, and then convert that to
 * binary, which gives you `11111110`.
*/
