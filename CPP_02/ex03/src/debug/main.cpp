#include "Fixed.hpp"

#if (DEBUG != 0)
# include <iostream>
# include <bitset>
# include <iomanip>
# include "stringUtils.hpp"
# include <cfloat>
# include <climits>
# include <cmath>
# include <limits>

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

static std::bitset<64> fBinary(double num)
{
	long long* longPtr = reinterpret_cast<long long*>(&num);
	std::bitset<64> bits(*longPtr);
	return (bits);
}


float power2(int n)
{
	int i = 0;
	float res = 1.0f;

	while (i++ < n)
		res *= 2;
	return (res);
}

void floatPoint(double number, int expBits, int fractionBits)
{
	int flagInfinite = 0;
	int exponent = 0;
	int bias = power2(expBits - 1) - 1;
	int expLimit = power2(expBits) - 1;
	// Step 1: Check if the number is negative
	int sign = (number < 0) ? 1 : 0;
	if (sign)
		number = -number;
	if (std::isinf(number))
		flagInfinite = 1;
	// Step 2: Convert the number to scientific notation in base 2
	if (expBits == 8)
		std::cout << "fNumber                : " << number << " : " << fBinary(static_cast<float>(number)) << std::endl;
	else if (expBits == 11)
		std::cout << "dNumber                : " << number << " : " << fBinary(static_cast<double>(number)) << std::endl;
	else
		std::cout << "iNumber                : " << number << " : " << iBinary(static_cast<int>(number)) << std::endl;
	while (number >= 2.0f)
	{
		number /= 2.0f;
		exponent++;
		if (DEBUG == 3 && flagInfinite == 0)
			std::cout << "\t\t" << exponent << " number: " << number << std::endl;
		if (exponent == expLimit)
			break;
	}
	// in case of negative exponent
	while (number < 1.0f)
	{
		number *= 2.0f;
		exponent--;
		if (DEBUG == 3 && flagInfinite == 0)
			std::cout << "\t\t"<< exponent << " number: " << number << std::endl;
		if (exponent == expLimit)
			break;
	}
	// Step 3: Add 127 to the real exponent value and convert it to binary
	std::bitset<64> exponentBits(exponent + power2(expBits - 1) - 1);
	std::cout << "Exponent bias in b^10  : " << ((exponentBits.to_ulong()) & 0xFF) 
	<< " - " << bias
	<< " = " << (int)(((exponentBits.to_ulong()) & expLimit) - bias) << std::endl;
	// Step 4: Get the mantissa
	number -= 1.0f; // remove the leading 1
	std::bitset<64> mantissaBits;
	for (int i = fractionBits - 1; i >= 0; i--)
	{
		number *= 2.0f;
		int integralPart = (int)number;
		if (integralPart == 1)
		{
			number -= 1.0f;
			mantissaBits.set(i);
		}
	}
	if (exponent == bias)
	{
		exponentBits = std::bitset<64> (exponent);
		mantissaBits.set();
	}
	// Step 5: Combine the sign, exponent and mantissa to print
	std::cout << "sign|exponen|franction : " << sign << " "
	<< exponentBits.to_string().substr(64 - expBits) << " "
	<< mantissaBits.to_string().substr(64 - fractionBits) << std::endl;

	// Print the number in the desired format
	std::cout << "Representation         :(-1)^" << sign << " * 2^" << exponent << " * 1."
	<< mantissaBits.to_string().substr(64 - fractionBits) << std::endl;
	std::cout << "------------------------------------------------"<< std::endl;
}

/**
 *  Smalles representable 1.401298464e-45/.
 * The minimum representable value is then `1 / (2^_fractionalBits)`.
 *  This is the smallest positive number that can be
 * represented, corresponding to a `_intValue` of `1`.
*/

static void getData(float number, Fixed const& f)
{
	std::cout.precision(10);
	std::cout << "Number (float)         : " << number << std::endl;
	std::cout << "toInt                  : " << f.toInt() << std::endl;
	std::cout << "toFloat                : " << f.toFloat() << std::endl;
	std::cout << "------------------------"<< std::endl;
	std::cout << "Raw                    : " << iBinary(f.getRawBits()).to_ulong() << " : " << iBinary(f.getRawBits()) << std::endl;
	floatPoint(number, 8, 23);
}

int main(void)
{
	std::cout << std::fixed;
	std::cout.precision(12);
	if (DEBUG == 4)
	{
		{
			std::cout << "Epsilon " ;
			floatPoint( std::numeric_limits<float>::epsilon(), 8, 23);
			floatPoint(((power2(23) - 1) * std::numeric_limits<float>::epsilon()), 8, 23);
			floatPoint( power2(23), 8, 23);
			floatPoint(16777214.01, 8, 23);
			floatPoint(power2(23) - 1, 8, 23);
		}
		{
			Fixed a;
			
			std::cout << "Max Value:\t\t" << a.MaxValue() << std::endl;
			std::cout << "Min Value:\t\t" << a.MinValue() << std::endl;
			a.setRawBits(power2(24) - 10);
			int i = 1;
			while (i < 20)
			{
				std::cout << i << " f: " << a << " raw: " << a.getRawBits()
				<< " " << iBinary(a.getRawBits())<< std::endl;
				a++;
				i++;
			}
			
		}
	}
	else if (DEBUG >= 2)
	{

		floatPoint(std::numeric_limits<float>::epsilon(), 8, 23);
		floatPoint(std::numeric_limits<float>::max(), 8, 23);
		floatPoint(-45.4, 8, 23);
		floatPoint((float)INT_MAX, 8, 23);
		floatPoint(0.0/0.0, 8, 23);
		floatPoint(-std::numeric_limits<float>::infinity(), 8, 23);
	}
	else if (DEBUG == 1)
 	{
		Fixed foo( .5f );
		std::cout << std::endl;
		std::cout << "foo;" << std::endl;
		getData(foo.toFloat(), foo);

		foo++;
		std::cout << "foo++;" << std::endl;
		getData(foo.toFloat(), foo);

		foo.setRawBits( foo.getRawBits() - 1 );
		std::cout << "foo.setRawBits( foo.getRawBits() - 1 );" << std::endl;
		getData(foo.toFloat(), foo);

		foo = foo * 2;
		std::cout << "foo = foo * 2;" << std::endl;
		getData(foo.toFloat(), foo);

		foo = foo / 2;
		std::cout << "foo = foo / 2;" << std::endl;
		getData(foo.toFloat(), foo);

		std::cout << "foo = foo / 4.2;" << std::endl;
		std::cout << "foo = " << foo << " / " << (4.2) << std::endl;
		foo = foo / 4.2f;
		getData(foo.toFloat(), foo);

		std::cout << "foo = foo / 4.2;" << std::endl;
		std::cout << "foo = " << foo << " / " << (4.2) << " = "<< "0.027901785714" << std::endl;
		foo = foo / 4.2f;
		getData(foo.toFloat(), foo); // .027901785714

		std::cout << "PRECISION LOST" << std::endl;
		std::cout << std::endl;

		foo = foo * 4.2f;
		std::cout << "foo = foo * 4.2;" << std::endl;
		std::cout << "foo = " << foo << " * " << (4.2) << " = "<< "0.492187500000" << std::endl;
		foo = foo * 4.2f; // .492187500000
		getData(foo.toFloat(), foo);
		
		std::cout << "Max( Fixed( 5.01f ), Fixed( 5.49f )) : "
		<< foo.max( Fixed( 5.01f ), Fixed( 5.49f )) << std::endl;

		std::cout << "foo.min( Fixed( 6 ), Fixed( 66 ) ) : "
		<< foo.min( Fixed( 6 ), Fixed( 66 )) << std::endl;

		std::cout << "foo.max( Fixed( 3.2f ), Fixed( -42.1f) ) : "
		<< foo.max( Fixed( 3.2f ), Fixed( -42.1f) ) << std::endl;

		float f = 4.4899999999f;
		std::cout << "float : " << f << std::endl;
		std::cout << "===================================" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << "\ta         " << a << std::endl;
		std::cout << "\tb         " << b << std::endl;
		std::cout << "\t++a       " << ++a << std::endl;
		std::cout << "\tRaw:      " << a.getRawBits() << std::endl;
		std::cout << "\tfloat:    " << a << std::endl;
		std::cout << "\ta         " << a << std::endl;
		std::cout << "\ta++       " << a++ << std::endl;
		std::cout << "\ta         " << a << std::endl;
		std::cout << "\tb         " << b << std::endl;
		std::cout << "\tmax(a, b) " << Fixed::max( a, b ) << std::endl;
		std::cout << "===================================" << std::endl;
		std::cout << "\t--a       " << --a << std::endl;
		std::cout << "\tb         " << b << std::endl;
		std::cout << "\tb <  a    " <<  (b < a) << std::endl;
		std::cout << "\tb >  a    " <<  (b > a) << std::endl;
		std::cout << "\tb == a    " <<  (b == a) << std::endl;
		std::cout << "\tb <= a    " <<  (b <= a) << std::endl;
		std::cout << "\tb >= a    " <<  (b >= a) << std::endl;
		std::cout << "\tb != a    " <<  (b != a) << std::endl;
		std::cout << "===================================\n" << std::endl;
	}
	return 0;
}
#endif
