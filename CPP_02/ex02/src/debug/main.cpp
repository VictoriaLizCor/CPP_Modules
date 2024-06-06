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

float power2(int n)
{
	int i = 0;
	float res = 1.0f;

	while (i++ < n)
		res *= 2;
	return (res);
}

void floatPoint(float number, int expBits, int fractionBits)
{
	// Step 1: Check if the number is negative
	int sign = (number < 0) ? 1 : 0;
	if (sign)
		number = -number;
	// Step 2: Convert the number to scientific notation in base 2
	int exponent = 0;
	if (DEBUG == 2)
		std::cout << exponent << " number: " << number << std::endl;
	while (number >= 2.0f)
	{
		number /= 2.0f;
		exponent++;
		if (DEBUG == 2)
			std::cout << "\t\t" << exponent << " number: " << number << std::endl;
		if (exponent == 255)
			break;
	}
	// in case of negative exponent
	while (number < 1.0f)
	{
		number *= 2.0f;
		exponent--;
		if (DEBUG == 2)
			std::cout << "\t\t"<< exponent << " number: " << number << std::endl;
		if (exponent == 255)
			break;
	}
	// Step 3: Add 127 to the real exponent value and convert it to binary
	std::bitset<32> exponentBits(exponent + power2(expBits - 1) - 1);
	// Step 4: Get the mantissa
	number -= 1.0f; // remove the leading 1
	std::bitset<32> mantissaBits;
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
	if (exponent == 255)
	{
		exponentBits = std::bitset<32> (exponent);
		mantissaBits.set();
	}
	// Step 5: Combine the sign, exponent and mantissa to print
	std::cout << "sign|exponen|franction : \t" << sign << " ";
	for (int i = expBits - 1; i >= 0; --i)
		std::cout << exponentBits[i];
	std::cout << " ";
	for (int i = fractionBits - 1; i >= 0; --i)
		std::cout << mantissaBits[i];
	std::cout << std::endl;
	// Print the number in the desired format
	std::cout << "Representation :\t\t(-1)^" << sign << " * 2^" << exponent << " * 1.";
	for (int i = fractionBits - 1; i >= 0; --i)
		std::cout << mantissaBits[i];
	std::cout << std::endl;
	std::cout << "------------------------------------------------"<< std::endl;
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

/**
 *  Smalles representable 1.401298464e-45/.
 * The minimum representable value is then `1 / (2^_fractionalBits)`.
 *  This is the smallest positive number that can be
 * represented, corresponding to a `_intValue` of `1`.
*/

static void getData(float number, Fixed const& f)
{
	std::cout.precision(10);
	std::cout << "Number (float):\t\t" << number << std::endl;
	std::cout << "\nFractional Bits:\t" << f.getFractionalBits() << std::endl;
	std::cout << "Int  Value:\t\t" << f.toInt() << std::endl;
	std::cout << "Float Value:\t\t" << f.toFloat() << std::endl;
	// std::cout << "Max Value:\t\t" << f.MaxValue() << std::endl;
	// std::cout << "Min Value:\t\t" << f.MinValue() << std::endl;
	std::cout << "------------------------"<< std::endl;
	std::cout << "RawDecimal Value:\t" << iBinary(f.getRawBits()).to_ulong() << std::endl;
	std::cout << "RawBinary Value:\t" << iBinary(f.getRawBits()) << std::endl;
	std::cout << "fBinary :\t\t" << fBinary(number) << std::endl;
	floatPoint(number, 8, 23);
	std::cout << "------------------------------------------------"<< std::endl;
}


int main(void)
{
	std::cout << std::fixed;
	std::cout.precision(15);
	if (DEBUG == 4)
	{
		std::cout.precision(8);
		int i = 1;
		// float f = 8388608.0f;
		int f = 0;
		Fixed a(f);
		{
			// int intNumber = 8388607;
			float num = 8388607.9960937500;
			std::cout << "Float point: "<< num << " : "<< std::endl;
			floatPoint(num, 8, 23);
			// std::cout << "Int Value: "<< intNumber << " : " << iBinary(intNumber) << std::endl;
			// intNumber >>= 8;
			// std::cout << "Int Value: "<< intNumber << " : " << iBinary(intNumber) << std::endl;
			// intNumber <<= 8;
			// std::cout << "Int Value: "<< intNumber << " : " << iBinary(intNumber) << std::endl;
			
		}
		std::cout << "Max Value:\t\t" << a.MaxValue() << std::endl;
		// while (i < 10)
		// {
		// 	std::cout << i << " f: " << a << " " << " i: " << a.getRawBits()
		// 	<< " " << iBinary(a.getRawBits())<< std::endl;
		// 	a++;
		// 	i++;
		// }
		// f = power2(23);
		// a = f;
		// i = 0;
		// while (i < 1000)
		// {
		// 	std::cout << i << " f: " << a << " " << " i: " << a.getRawBits()
		// 	<< " " << iBinary(a.getRawBits())<< std::endl;
		// 	a--;
		// 	i++;
		// }
		// std::cout << i << " f: " << a << " " << " i: " << a.getRawBits()
		// << " " << iBinary(a.getRawBits())<< std::endl;
		return (0);
	}
	if (DEBUG < 3)
	{
		{
			float f =  std::numeric_limits<float>::epsilon();
			std::cout << "float Decimal Value    :\t" << f << std::endl;
			floatPoint(f, 8, 23);
		}
		{
			float f = std::numeric_limits<float>::max();
			std::cout << "float Decimal Value    :\t" << f << std::endl;
			floatPoint(f, 8, 23);
		}
		{
			float f = -45.4;
			std::cout << "float Decimal Value    :\t" << f << std::endl;
			floatPoint(f, 8, 23);
		}
		{
			float f = (float)INT_MAX;
			std::cout << "float Decimal Value    :\t" << f << std::endl;
			floatPoint(f, 8, 23);
		}
		{
			float f = 0.0/0.0; //NAN
			std::cout << "float Decimal Value    :\t" << f << std::endl;
			floatPoint(f, 8, 23);
		}
		{
			float f = -std::numeric_limits<float>::infinity();
			std::cout << "float Decimal Value    :\t" << f << std::endl;
			floatPoint(f, 8, 23);
		}
		{
			float f = 8388607.992187500000000;
			Fixed a(f);
			std::cout << "float Decimal Value    :\t" << f << std::endl;
			getData(f, a);
			
		}
		std::cout << "------------------------"<< std::endl;
	}
	else
 	{
		std::cout << "===================================" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << "\ta         " << a << std::endl;
		std::cout << "\tb         " << b << std::endl;
		std::cout << "\t++a       " << ++a << std::endl;
		std::cout << "\tfixed point number	is " << a.getRawBits() << std::endl;
		std::cout << "\tfloat representation  is " << a << std::endl;
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
		{
			float f = 0.00390625;
			Fixed min( f );
			getData(f, min);
		}
		{
			float f = 0.99609375;
			Fixed min( f );
			getData(f, min);
		}
		{
			int i = -1;
			Fixed min( i );
			std::cout << "min (float):\t\t" << i << std::endl;
			getData(i, min);
		}
		{
			float i = 0.99609375;
			Fixed min( i );
			std::cout << "min (float):\t\t" << i << std::endl;
			getData(i, min);
		}

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

		foo = foo / 4.2f;
		std::cout << "foo = foo / 4.2;" << std::endl;
		getData(foo.toFloat(), foo);

		std::cout << "PRECISION LOST" << std::endl;
		std::cout << std::endl;

		foo = foo * 4.2f;
		std::cout << "foo = foo / 4.2;" << std::endl;
		getData(foo.toFloat(), foo);

		std::cout << "foo.max( Fixed( 5.01f ), Fixed( 5.49f ).toInt() );"
					<< std::endl;
		std::cout << " max is " << foo.max( Fixed( 5.01f ), Fixed( 5.49f ).toInt() )
					<< std::endl;
		std::cout << "foo.min( Fixed( 6 ), Fixed( 66 ).toInt() );"
					<< std::endl;
		std::cout << " min is " << foo.min( 6, 66 ) << std::endl;
		std::cout << std::endl;

		Fixed i( 3.2f );
		Fixed j( 42.1f );

		std::cout << "foo.max( Fixed( 42f ), Fixed( -42 ) );" << std::endl;
		std::cout << " max is " << foo.max( i, j ) << std::endl;
	}
	return 0;
}
#endif
