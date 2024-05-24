/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:49:47 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/24 15:34:41 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <iostream>
#include <bitset>
#include <iomanip>

#if (DEBUG == 0)
int main(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return (0);
}
#else
static std::bitset<32> iBinary(int num)
{
	std::bitset<32> binary(num);
	return (binary);
}

/**
 * `reinterpret_cast<int*>(&num)` is used to get a pointer to the float `num` as
 * an integer pointer. Then, `std::bitset<32>` is used to create a binary
 * representation of the integer. This binary representation is then printed to
 * the console.
*/
static std::bitset<32> fBinary(float num)
{
	int* intPtr = reinterpret_cast<int*>(&num);
	std::bitset<32> bits(*intPtr);
	return (bits);
}

static void moveBits(int num, int bits)
{
	int i = -1;

	while (i++ < bits)
	{
		std::cout << "Movie right >>\t"<< num << "\t| " << iBinary(num) << "\n";
		num >>= 1;
	}
}

/*
 * In most modern computer systems, a `float` in C++ is represented using 32
 * bits. This is based on the IEEE 754 standard for floating-point arithmetic.
 * 
 * - 1 bit for the sign of the number (0 for positive, 1 for negative)
 * - 8 bits for the exponent
 * - 23 bits for the fraction (also known as the `mantissa` or the significand)
 * 
 * This allows `float` to represent a wide range of values, with a trade-off
 * between range and precision. If you need more precision, you can use a `double`,
 * which uses 64 bits.
 *
*/
int main(void)
{
	{
		std::cout.precision(9);
		{
			Fixed a = Fixed( 1234.4321f );
			std::cout << "Raw a is ->" << a.getRawBits() << std::endl;
			std::cout << "Int a is ->" << a.toInt() << std::endl;
		}
		{
			float f = 1234.4321f;
			int i;

			std::cout << "Binary of f  " << f << "\t| "<< fBinary(f) << std::endl;
			i = static_cast<int> (roundf(f * (1 << 8)));
			std::cout << "\nf * (1 << 8) =\t" << static_cast<float> (f * (1 << 8)) << std::endl;
			std::cout << "roundf (f * (1 << 8)) =\t" << roundf(f * (1 << 8)) << std::endl;
			std::cout << "------------------------"<< std::endl;
			std::cout << "\ni = " << i << std::endl;
			moveBits(i, 8);
			std::cout << "------------------------"<< std::endl;
		}
	}
}
#endif
/*
  512 | 256 | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 0
  
*/
