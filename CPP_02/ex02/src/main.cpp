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

// static std::bitset<32> iBinary(int num)
// {
// 	std::bitset<32> binary(num);
// 	return (binary);
// }

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

// static void moveBits(int num, int bits)
// {
// 	int i = -1;

// 	while (i++ < bits)
// 	{
// 		std::cout << "Movie right >>\t"<< num << "\t| " << iBinary(num) << "\n";
// 		num >>= 1;
// 	}
// }

int main(void)
{
	std::cout.precision(30);
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
	{
		Fixed min( FLT_MIN );
		std::cout << std::endl;
		std::cout << "min;" << std::endl;
		std::cout << "MIN float value: " << FLT_MIN << std::endl;
		std::cout << "Binary   " << "\t| "<< fBinary(FLT_MIN) << std::endl;
		std::cout <<  " fixed point number    is " << min.getRawBits() << std::endl;
		std::cout << " float representation  is " << min << std::endl;
		std::cout << "Binary   " << "\t| "<< fBinary(min.toFloat()) << std::endl;

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
	}
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
