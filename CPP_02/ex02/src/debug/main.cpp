#include "Fixed.hpp"
#if (DEBUG == 1)
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

void ExponentMantissa(float number, int expBits, int fractionBits)
{
	std::cout << std::endl;
	// Step 1: Check if the number is negative
	int sign = (number < 0) ? 1 : 0;
	if (sign) number = -number;
	// Step 2: Convert the number to scientific notation in base 2
	int exponent = 0;
	std::cout << exponent << " number: " << number << std::endl;
	while (number >= 2.0f)
	{
		number /= 2.0f;
		exponent++;
		// std::cout << exponent << " number: " << number << std::endl;
	}
	// in case of negative exponent
	while (number < 1.0f)
	{
		number *= 2.0f;
		exponent--;
		// std::cout << exponent << " number: " << number << std::endl;
	}
	// Step 3: Add 127 to the real exponent value and convert it to binary
	std::bitset<32> exponentBits(exponent + power2(expBits - 1) - 1);
	// Step 4: Get the mantissa
	number -= 1.0f; // remove the leading 1
	std::bitset<32> mantissaBits;
	for (int i = fractionBits - 1; i >= 0; i--) {
		number *= 2.0f;
		int integralPart = (int)number;
		if (integralPart == 1) {
			number -= 1.0f;
			mantissaBits.set(i);
		}
	}
	// Step 5: Combine the sign, exponent and mantissa
	std::cout << "ExponentMantissa : \t" << sign << " ";
	for (int i = expBits - 1; i >= 0; --i)
		std::cout << exponentBits[i];
	std::cout << " ";
	for (int i = fractionBits - 1; i >= 0; --i)
		std::cout << mantissaBits[i];
	std::cout << std::endl;
// Print the number in the desired format
    std::cout << "Representation:\t(-1)^" << sign << " * 2^" << exponent << " * 1.";
	for (int i = fractionBits - 1; i >= 0; --i)
		std::cout << mantissaBits[i];
    std::cout << std::endl;
}

void floatBitsConversion(float number) {
	// Assuming that float is 4 bytes
	if(sizeof(float) != 4)
	{
		std::cout << "Unsupported float size for IEEE 754 representation" << std::endl;
		return;
	}

	// Cast float to unsigned int
	unsigned int binary = *(unsigned int*)&number;

	// Print sign bit
	std::cout << "\nsign|exponen|franction :\t" <<((binary >> 31) ? "1 " : "0 ");
	
	// Check for infinity
	if (number == std::numeric_limits<float>::infinity() || number == -std::numeric_limits<float>::infinity())
	{
		std::cout << " 11111111 00000000000000000000000\n";
		return;
	}
	// Print exponent bits
	std::bitset<8> exponentBits((binary >> 23) & 0xFF);
	std::cout << exponentBits << " ";

	// Print fraction bits
	std::bitset<23> fractionBits(binary & 0x7FFFFF);
	std::cout << fractionBits << std::endl;
	std::cout << "Binary			 : "<< (binary) << "\t" << iBinary(binary) << std::endl;
	std::cout << "23 right Bits shift: "<< (binary >> 23) << "\t" << iBinary(binary >> 23) << std::endl;
	std::cout << "Exponent		   : " << (0xFF) << "\t" << iBinary(0xFF) << std::endl;
	std::cout << "And operation	  : " << ((binary >> 23) & 255) << "\t" << iBinary((binary >> 23) & 0xFF) << std::endl;
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
	std::cout << "Max Value:\t\t" << f.MaxValue() << std::endl;
	std::cout << "Min Value:\t\t" << f.MinValue() << std::endl;
	std::cout << "------------------------"<< std::endl;
	std::cout << "RawDecimal Value:\t" << iBinary(f.getRawBits()).to_ulong() << std::endl;
	std::cout << "RawBinary Value:\t" << iBinary(f.getRawBits()) << std::endl;
	std::cout << "fBinary :\t\t" << fBinary(number) << std::endl;
	floatBitsConversion(number);
	std::cout << "------------------------------------------------"<< std::endl;
}



int main(void)
{
	std::cout << std::fixed;
	std::cout.precision(15);
	{
		// {
		// 	std::cout << std::endl;
		// 	std::cout << "INTMAX	   \t\t" << INT_MAX << std::endl;
		// 	std::cout << "INTMAX iBINARY\t\t" << iBinary(INT_MAX) << std::endl;
		// 	std::cout << "------------------------"<< std::endl;
		// 	std::cout << "INTMIN	   \t\t" << INT_MIN << std::endl;
		// 	std::cout << "INTMIN iBINARY\t\t" << iBinary(INT_MIN) << std::endl;
		// 	std::cout << "------------------------"<< std::endl;
		// }
		// float f = 0.00390625;
		// {
		// 	Fixed min( f );
		// 	getData(f, min);
		// }
		// f = 0.99609375;
		// {
		// 	Fixed min( f );
		// 	getData(f, min);
		// }
		// {
		// 	int i = -1;
		// 	Fixed min( i );
		// 	std::cout << "min (float):\t\t" << i << std::endl;
		// 	getData(i, min);
		// }
		// {
		// 	float i = 0.99609375;
		// 	Fixed min( i );
		// 	std::cout << "min (float):\t\t" << i << std::endl;
		// 	getData(i, min);
		// }
		{
			float f =  std::numeric_limits<float>::epsilon();
			std::cout << "float Decimal Value :\t" << f << std::endl;
			ExponentMantissa(f, 8, 23);
			floatBitsConversion(f);
			std::cout << "------------------------"<< std::endl;
		}
		{
			float f = std::numeric_limits<float>::max();
			std::cout << "float Decimal Value :\t" << f << std::endl;
			ExponentMantissa(f, 8, 23);
			floatBitsConversion(f);
			std::cout << "------------------------"<< std::endl;
		}
		{
			float f = -45.4;
			std::cout << "float Decimal Value :\t" << f << std::endl;
			ExponentMantissa(f, 8, 23);
			floatBitsConversion(f);
			std::cout << "------------------------"<< std::endl;
		}
		{
			float f = (float)INT_MAX - 1;
			std::cout << "float Decimal Value :\t" << f << std::endl;
			ExponentMantissa(f, 8, 23);
			floatBitsConversion(f);
			std::cout << "------------------------"<< std::endl;
		}
		// {
		// 	float f = 0.0/0.0; //NAN
		// 	std::cout << "float Decimal Value :\t" << f << std::endl;
		// 	floatBitsConversion(f);
		// 	std::cout << "------------------------"<< std::endl;
		// }
		// {
		// 	float f = NAN;
		// 	std::cout << "float Decimal Value :\t" << f << std::endl;
		// 	floatBitsConversion(f);
		// 	std::cout << "------------------------"<< std::endl;
		// }
		// {
		// 	float f = -std::numeric_limits<float>::infinity();
		// 	std::cout << "float Decimal Value :\t" << f << std::endl;
		// 	floatBitsConversion(f);
		// 	std::cout << "------------------------"<< std::endl;
		// }
		// f = -2;
		// std::cout << "float Decimal Value :\t" << f << std::endl;
		// std::cout << "f binary: " << fBinary(f) << std::endl;
		// floatBitsConversion(f);
		// std::cout << "(2^19): " << power2(23) << std::endl;
		// std::cout << (1/(power2(23))) << std::endl;
		// std::cout << "------------------------"<< std::endl;
	}
/* 	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << "a		 " << a << std::endl;
		std::cout << "b		 " << b << std::endl;
		std::cout << "++a	   " << ++a << std::endl;
		std::cout << " fixed point number	is " << a.getRawBits() << std::endl;
		std::cout << " float representation  is " << a << std::endl;
		std::cout << "a		 " << a << std::endl;
		std::cout << "a++	   " << a++ << std::endl;
		std::cout << "a		 " << a << std::endl;
		std::cout << "b		 " << b << std::endl;
		std::cout << "max(a, b) " << Fixed::max( a, b ) << std::endl;
		std::cout << "==================" << std::endl;
		std::cout << "--a	   " << --a << std::endl;
		std::cout << "b		 " << b << std::endl;
		std::cout << "b <  a	" <<  (b < a) << std::endl;
		std::cout << "b >  a	" <<  (b > a) << std::endl;
		std::cout << "b == a	" <<  (b == a) << std::endl;
		std::cout << "b <= a	" <<  (b <= a) << std::endl;
		std::cout << "b >= a	" <<  (b >= a) << std::endl;
		std::cout << "b != a	" <<  (b != a) << std::endl;
		std::cout << "==================" << std::endl;
		Fixed foo;
		std::cout << std::endl;
		std::cout << "foo;" << std::endl;
		std::cout << " fixed point number	is " << foo.getRawBits() << std::endl;
		std::cout << " float representation  is " << foo << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		foo++;
		std::cout << "foo++;" << std::endl;
		std::cout << " fixed point number	is " << foo.getRawBits() << std::endl;
		std::cout << " float representation  is " << foo << std::endl;
		std::cout << std::endl;
		{
			Fixed foo( .5f );
			std::cout << std::endl;
			std::cout << "foo;" << std::endl;
			std::cout << " fixed point number	is " << foo.getRawBits() << std::endl;
			std::cout << " float representation  is " << foo << std::endl;
			std::cout << std::endl;
		}
		foo++;
		std::cout << "foo++;" << std::endl;
		std::cout << " fixed point number	is " << foo.getRawBits() << std::endl;
		std::cout << " float representation  is " << foo << std::endl;
		std::cout << std::endl;

		foo.setRawBits( foo.getRawBits() - 1 );
		std::cout << "foo.setRawBits( foo.getRawBits() - 1 );" << std::endl;
		std::cout << " fixed point number	is " << foo.getRawBits() << std::endl;
		std::cout << " float representation  is " << foo << std::endl;
		std::cout << std::endl;

		foo = foo * 2;
		std::cout << "foo = foo * 2;" << std::endl;
		std::cout << " fixed point number	is " << foo.getRawBits() << std::endl;
		std::cout << " float representation  is " << foo << std::endl;
		std::cout << std::endl;

		foo = foo / 2;
		std::cout << "foo = foo / 2;" << std::endl;
		std::cout << " fixed point number	is " << foo.getRawBits() << std::endl;
		std::cout << " float representation  is " << foo << std::endl;
		std::cout << std::endl;

		foo = foo / 4.2f;
		std::cout << "foo = foo / 4.2;" << std::endl;
		std::cout << " fixed point number	is " << foo.getRawBits() << std::endl;
		std::cout << " float representation  is " << foo << std::endl;
		std::cout << std::endl;

		std::cout << "PRECISION LOST" << std::endl;
		std::cout << std::endl;

		foo = foo * 4.2f;
		std::cout << "foo = foo / 4.2;" << std::endl;
		std::cout << " fixed point number	is " << foo.getRawBits() << std::endl;
		std::cout << " float representation  is " << foo << std::endl;
		std::cout << std::endl;

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
	 */
	return 0;
}
#endif
