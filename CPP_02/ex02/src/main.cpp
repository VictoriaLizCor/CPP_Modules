#include "Fixed.hpp"

#if (DEBUG == 0)
int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}
#else
#include <iostream>
#include <bitset>
#include <iomanip>
# include "stringUtils.hpp"
#include <cfloat>
#include <climits>
#include <cmath>

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
// static std::bitset<32> fBinary(float num)
// {
// 	int* intPtr = reinterpret_cast<int*>(&num);
// 	std::bitset<32> bits(*intPtr);
// 	return (bits);
// }

// static float fDecimal(std::bitset<32> bits)
// {
// 	int intVal = bits.to_ulong();
// 	std::cout << "intVal: \t" << intVal << std::endl;
// 	std::cout << "intVal iBinary: " << iBinary(intVal) << std::endl;
// 	float* floatPtr = reinterpret_cast<float*>(&intVal);
// 	return (*floatPtr);
// }

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
static void getData(Fixed const& f)
{
	std::cout.precision(10);
	std::cout << "RawBinary Value is:\t" << iBinary(f.getRawBits()) << std::endl;
	std::cout << "RawDecimal Value is:\t" << iBinary(f.getRawBits()).to_ulong() << std::endl;
	std::cout << "Int  Value is:\t" << f.toInt() << std::endl;
	std::cout << "Float Value is:\t" << f.toFloat() << std::endl;
	std::cout << "\nFractional Bits:\t" << f.getFractionalBits() << std::endl;
	std::cout << "Max Value is:\t" << f.MaxValue() << std::endl;
	std::cout << "Min Value is:\t" << f.MinValue() << std::endl;
	std::cout << "------------------------"<< std::endl;
	
}
int main(void)
{
	std::cout.precision(10);
	{
		std::cout << std::endl;
		std::cout << "INTMAX       \t" << INT_MAX << std::endl;
		std::cout << "INTMAX iBINARY\t" << iBinary(INT_MAX) << std::endl;
		std::cout << "------------------------"<< std::endl;
		std::cout << "INTMIN       \t" << INT_MIN << std::endl;
		std::cout << "INTMIN iBINARY\t" << iBinary(INT_MIN) << std::endl;
		std::cout << "------------------------"<< std::endl;
		// 00000000100000000000000000000000
		// std::cout << std::ceil(std::log(1.0 / f) / std::log(2.0)) << std::endl;
		float f = 0.00390625;
		{
			Fixed min( f );
			std::cout << "min (float): " << f << std::endl;
			getData(min);
		}
		{
			int i = 1;
			Fixed min( i );
			std::cout << "min (float): " << i << std::endl;
			getData(min);
		}
	}
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << "a         " << a << std::endl;
	// std::cout << "b         " << b << std::endl;
	// std::cout << "++a       " << ++a << std::endl;
	// std::cout << " fixed point number    is " << a.getRawBits() << std::endl;
	// std::cout << " float representation  is " << a << std::endl;
	// std::cout << "a         " << a << std::endl;
	// std::cout << "a++       " << a++ << std::endl;
	// std::cout << "a         " << a << std::endl;
	// std::cout << "b         " << b << std::endl;
	// std::cout << "max(a, b) " << Fixed::max( a, b ) << std::endl;
	// std::cout << "==================" << std::endl;
	// std::cout << "--a       " << --a << std::endl;
	// std::cout << "b         " << b << std::endl;
	// std::cout << "b <  a    " <<  (b < a) << std::endl;
	// std::cout << "b >  a    " <<  (b > a) << std::endl;
	// std::cout << "b == a    " <<  (b == a) << std::endl;
	// std::cout << "b <= a    " <<  (b <= a) << std::endl;
	// std::cout << "b >= a    " <<  (b >= a) << std::endl;
	// std::cout << "b != a    " <<  (b != a) << std::endl;
	// std::cout << "==================" << std::endl;
	// Fixed foo;
	// std::cout << std::endl;
	// std::cout << "foo;" << std::endl;
	// std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
	// std::cout << " float representation  is " << foo << std::endl;
	// std::cout << std::endl;
	// std::cout << std::endl;
	// foo++;
	// std::cout << "foo++;" << std::endl;
	// std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
	// std::cout << " float representation  is " << foo << std::endl;
	// std::cout << std::endl;
	// Fixed foo( .5f );
	// std::cout << std::endl;
	// std::cout << "foo;" << std::endl;
	// std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
	// std::cout << " float representation  is " << foo << std::endl;
	// std::cout << std::endl;

	// foo++;
	// std::cout << "foo++;" << std::endl;
	// std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
	// std::cout << " float representation  is " << foo << std::endl;
	// std::cout << std::endl;

	// foo.setRawBits( foo.getRawBits() - 1 );
	// std::cout << "foo.setRawBits( foo.getRawBits() - 1 );" << std::endl;
	// std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
	// std::cout << " float representation  is " << foo << std::endl;
	// std::cout << std::endl;

	// foo = foo * 2;
	// std::cout << "foo = foo * 2;" << std::endl;
	// std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
	// std::cout << " float representation  is " << foo << std::endl;
	// std::cout << std::endl;

	// foo = foo / 2;
	// std::cout << "foo = foo / 2;" << std::endl;
	// std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
	// std::cout << " float representation  is " << foo << std::endl;
	// std::cout << std::endl;

	// foo = foo / 4.2f;
	// std::cout << "foo = foo / 4.2;" << std::endl;
	// std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
	// std::cout << " float representation  is " << foo << std::endl;
	// std::cout << std::endl;

	// std::cout << "PRECISION LOST" << std::endl;
	// std::cout << std::endl;

	// foo = foo * 4.2f;
	// std::cout << "foo = foo / 4.2;" << std::endl;
	// std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
	// std::cout << " float representation  is " << foo << std::endl;
	// std::cout << std::endl;

	// std::cout << "foo.max( Fixed( 5.01f ), Fixed( 5.49f ).toInt() );"
	// 			<< std::endl;
	// std::cout << " max is " << foo.max( Fixed( 5.01f ), Fixed( 5.49f ).toInt() )
	// 			<< std::endl;
	// std::cout << "foo.min( Fixed( 6 ), Fixed( 66 ).toInt() );"
	// 			<< std::endl;
	// std::cout << " min is " << foo.min( 6, 66 ) << std::endl;
	// std::cout << std::endl;

	// Fixed i( 3.2f );
	// Fixed j( 42.1f );

	// std::cout << "foo.max( Fixed( 42f ), Fixed( -42 ) );" << std::endl;
	// std::cout << " max is " << foo.max( i, j ) << std::endl;
	return 0;
}
#endif
