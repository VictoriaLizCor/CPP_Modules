#include "Fixed.hpp"
#if (DEBUG == 1)
#include <iostream>
#include <bitset>
#include <iomanip>
# include "stringUtils.hpp"
#include <cfloat>
#include <climits>
#include <cmath>
#include <limits>

void floatToBinary(float number)
{
    // Get the sign bit
    int sign = number < 0 ? 1 : 0;
    number = std::abs(number);

    // Separate the number into integer and fractional parts
    int integerPart = static_cast<int>(number);
    float fractionalPart = number - integerPart;

    // Convert the integer part to binary
    int integerBinary = 0;
    int base = 1;
    while (integerPart > 0) {
        integerBinary += (integerPart % 2) * base;
        integerPart /= 2;
        base *= 10;
    }

    // Convert the fractional part to binary
    int fractionalBinary = 0;
    base = 10;
    while (fractionalPart > 0.0) {
        fractionalPart *= 2;
        if (fractionalPart >= 1.0) {
            fractionalBinary += (int(fractionalPart) % 2) * base;
            fractionalPart -= 1.0;
        }
        base *= 10;
    }

    // Calculate the exponent
     int exponent = std::floor(std::log(number) / std::log(2)) + 127;

    // Convert the exponent to binary
    int exponentBinary = 0;
    base = 1;
    while (exponent > 0) {
        exponentBinary += (exponent % 2) * base;
        exponent /= 2;
        base *= 10;
    }

    // Print the 32-bit representation
    std::cout << "32-bit representation: " << sign << " " << exponentBinary << " " << integerBinary << fractionalBinary << std::endl;
}

float power2(int n)
{
	int i = 0;
	float res = 1.0f;

	while (i++ < n)
		res *= 2;
	return (res);
}

void floatFractionToBinary(float fraction)
{
	std::bitset<23> binary;
	int index = 22;

	while (fraction > 0.0f && index >= 0)
	{
		std::cout << (index + 1) << ": ";
		if (fraction >= 1/(power2(index + 1)))
		{
			binary.set(index);
			fraction -= 1/(power2(index + 1));
			std::cout << fraction << "\t" << binary[index] << std::endl;
		}
		else
			std::cout << fraction << "\t" << binary[index] << std::endl;
		index--;
	}
	std::cout << "Mantissa Binary :\t\t" << binary<< std::endl;
}

void getMantissaAndExponent(float n)
{
	int exponent = 0;
	float mantissa = n;
	if (n == std::numeric_limits<float>::infinity())
	{
		std::cout << "Mantissa and Exponent :\t\t(1 * 2^128)\n";
		return;
	}
	else if (n == -std::numeric_limits<float>::infinity())
	{
		std::cout << "Mantissa and Exponent :\t\t(-1 * 2^128)\n";
		return;
	}
	else if (std::isnan(n))
	{
		std::cout << "Mantissa and Exponent :\t\t(NaN)\n";
		return;
	}
	if (mantissa < 0 )
		mantissa = -mantissa;
	while (mantissa >= 2.0)
	{
		mantissa /= 2.0;
		exponent++;
	}
	std::cout << "Mantissa and Exponent :\t\t(" << mantissa << " * 2^" << exponent << ")\n";
	floatFractionToBinary(mantissa);
}

std::bitset<23> getMantissaBinary(int n, std::bitset<32> bits)
{
	std::bitset<23> mantissa;
	int i = 1;
	float res = 0;

	while (i < n)
	{
		res += 1 / (bits[n - i] * power2(i));
		std::cout << i << ": "<< bits[i] << " "<< (bits[n - i] * power2(i))
		<< res << std::endl;
		i++;
	}
	return (res);
}

static std::bitset<32> iBinary(int num)
{
	std::bitset<32> binary(num);
	return (binary);
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
	std::cout << "Binary             : "<< (binary) << "\t" << iBinary(binary) << std::endl;
	std::cout << "23 right Bits shift: "<< (binary >> 23) << "\t" << iBinary(binary >> 23) << std::endl;
	std::cout << "Exponent           : " << (0xFF) << "\t" << iBinary(0xFF) << std::endl;
	std::cout << "And operation      : " << ((binary >> 23) & 255) << "\t" << iBinary((binary >> 23) & 0xFF) << std::endl;
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


static float fDecimal(std::bitset<32> bits)
{
	int intVal = bits.to_ulong();
	std::cout << "intVal: \t" << intVal << std::endl;
	std::cout << "intVal iBinary: " << iBinary(intVal) << std::endl;
	float* floatPtr = reinterpret_cast<float*>(&intVal);
	return (*floatPtr);
}

// static void moveBits(int num, int bits)
// {
// 	int i = -1;

// 	while (i++ < bits)
// 	{
// 		std::cout << "Movie right >>\t"<< num << "\t| " << iBinary(num) << "\n";
// 		num >>= 1;
// 	}
// }

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

void printBinary(float num)
{
	unsigned int asInt = *(unsigned int*)&num;
	for(int i = 31; i >= 0; i--) {
		std::cout << ((asInt >> i) & 1);
		if(i == 31 || i == 23) std::cout << " ";
	}
	std::cout << std::endl;
}

int main(void)
{
	std::cout << std::fixed;
	std::cout.precision(15);
	{
		// {
		// 	std::cout << std::endl;
		// 	std::cout << "INTMAX       \t\t" << INT_MAX << std::endl;
		// 	std::cout << "INTMAX iBINARY\t\t" << iBinary(INT_MAX) << std::endl;
		// 	std::cout << "------------------------"<< std::endl;
		// 	std::cout << "INTMIN       \t\t" << INT_MIN << std::endl;
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
			getMantissaAndExponent(f);
			floatBitsConversion(f);
			std::cout << "------------------------"<< std::endl;
		}
		{
			float f = std::numeric_limits<float>::max();
			std::cout << "float Decimal Value :\t" << f << std::endl;
			getMantissaAndExponent(f);
			floatBitsConversion(f);
			std::cout << "------------------------"<< std::endl;
		}
		{
			float f = -45.4;
			std::cout << "float Decimal Value :\t" << f << std::endl;
			getMantissaAndExponent(f);
			floatBitsConversion(f);
			floatToBinary(f);
			std::cout << "------------------------"<< std::endl;
		}
		// {
		// 	float f = 0.0/0.0; //NAN
		// 	std::cout << "float Decimal Value :\t" << f << std::endl;
		// 	getMantissaAndExponent(f);
		// 	floatBitsConversion(f);
		// 	std::cout << "------------------------"<< std::endl;
		// }
		// {
		// 	float f = NAN;
		// 	std::cout << "float Decimal Value :\t" << f << std::endl;
		// 	getMantissaAndExponent(f);
		// 	floatBitsConversion(f);
		// 	std::cout << "------------------------"<< std::endl;
		// }
		// {
		// 	float f = -std::numeric_limits<float>::infinity();
		// 	std::cout << "float Decimal Value :\t" << f << std::endl;
		// 	getMantissaAndExponent(f);
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

		std::cout << "a         " << a << std::endl;
		std::cout << "b         " << b << std::endl;
		std::cout << "++a       " << ++a << std::endl;
		std::cout << " fixed point number    is " << a.getRawBits() << std::endl;
		std::cout << " float representation  is " << a << std::endl;
		std::cout << "a         " << a << std::endl;
		std::cout << "a++       " << a++ << std::endl;
		std::cout << "a         " << a << std::endl;
		std::cout << "b         " << b << std::endl;
		std::cout << "max(a, b) " << Fixed::max( a, b ) << std::endl;
		std::cout << "==================" << std::endl;
		std::cout << "--a       " << --a << std::endl;
		std::cout << "b         " << b << std::endl;
		std::cout << "b <  a    " <<  (b < a) << std::endl;
		std::cout << "b >  a    " <<  (b > a) << std::endl;
		std::cout << "b == a    " <<  (b == a) << std::endl;
		std::cout << "b <= a    " <<  (b <= a) << std::endl;
		std::cout << "b >= a    " <<  (b >= a) << std::endl;
		std::cout << "b != a    " <<  (b != a) << std::endl;
		std::cout << "==================" << std::endl;
		Fixed foo;
		std::cout << std::endl;
		std::cout << "foo;" << std::endl;
		std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
		std::cout << " float representation  is " << foo << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		foo++;
		std::cout << "foo++;" << std::endl;
		std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
		std::cout << " float representation  is " << foo << std::endl;
		std::cout << std::endl;
		{
			Fixed foo( .5f );
			std::cout << std::endl;
			std::cout << "foo;" << std::endl;
			std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
			std::cout << " float representation  is " << foo << std::endl;
			std::cout << std::endl;
		}
		foo++;
		std::cout << "foo++;" << std::endl;
		std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
		std::cout << " float representation  is " << foo << std::endl;
		std::cout << std::endl;

		foo.setRawBits( foo.getRawBits() - 1 );
		std::cout << "foo.setRawBits( foo.getRawBits() - 1 );" << std::endl;
		std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
		std::cout << " float representation  is " << foo << std::endl;
		std::cout << std::endl;

		foo = foo * 2;
		std::cout << "foo = foo * 2;" << std::endl;
		std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
		std::cout << " float representation  is " << foo << std::endl;
		std::cout << std::endl;

		foo = foo / 2;
		std::cout << "foo = foo / 2;" << std::endl;
		std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
		std::cout << " float representation  is " << foo << std::endl;
		std::cout << std::endl;

		foo = foo / 4.2f;
		std::cout << "foo = foo / 4.2;" << std::endl;
		std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
		std::cout << " float representation  is " << foo << std::endl;
		std::cout << std::endl;

		std::cout << "PRECISION LOST" << std::endl;
		std::cout << std::endl;

		foo = foo * 4.2f;
		std::cout << "foo = foo / 4.2;" << std::endl;
		std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
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
