#include "fixed.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <bitset>

using fixed = numeric::fixed<16, 16>;

#if __cplusplus >= 201402L
#define STATIC_ASSERT14(expr) static_assert((expr), "")
#else
#define STATIC_ASSERT14(expr) assert((expr))
#endif

static std::bitset<32> iBinary(int num)
{
	std::bitset<32> binary(num);
	return (binary);
}

int main() {
	std::cout << std::fixed;
	std::cout.precision(15);
	// fixed f = (8388607.9960937500);
	// fixed f = (32767.9960937500);
	// fixed f = (-0.9960937500);
	float nf = 4194303.0;
	fixed f = (nf);
	// fixed f = (0.0f/0.0f);
	// f-= 0.0039062500;
	f+= 0.0039062500;
	// f-= 0.0039062500;
	std::cout << f << std::endl;
	std::cout << "int : " << f.to_int() << std::endl;
	std::cout << "raw : " << f.to_raw() << " : "<< iBinary(f.to_raw()) << std::endl;
	std::cout << "frc : " << (f.to_raw() & 255 ) << " : "<< iBinary(f.to_raw() & 255) << std::endl;
	std::cout << "nf  : " << nf << " : " << iBinary((int)nf)<<std::endl;
	std::cout << "nf  : " << -nf << " : " << iBinary(-(int)nf)<<std::endl;
	int i = 8388607;
	std::cout << i <<" : " << iBinary(i) << std::endl;
	std::cout << (i<<8) <<" : " << iBinary(i<<8) << std::endl;
	// TODO(eteran): perform these tests on the bit-patterns, as float conversions aren't ideal to use
	// constexpr numeric::fixed<8, 8> a8 = 50.25;
	// STATIC_ASSERT14(fixed(a8) == fixed(50.25));

	// // TODO(eteran): perform these tests on the bit-patterns, as float comparisons aren't ideal to use
	// STATIC_ASSERT14((fixed(10.5) * 3)          == 31.5);
	// STATIC_ASSERT14((fixed(10.5) * fixed(3))   == 31.5);
	// STATIC_ASSERT14((3 * fixed(10.5))          == 31.5);
	// STATIC_ASSERT14((fixed(10.5) * 3.0)        == 31.5);
	// STATIC_ASSERT14((fixed(10.5) * fixed(3.0)) == 31.5);
	// STATIC_ASSERT14((3.0 * fixed(10.5))        == 31.5);

	// STATIC_ASSERT14(fixed(50) / fixed(5) == fixed(10));

	// STATIC_ASSERT14(-fixed(10) == -10);
	// STATIC_ASSERT14(+fixed(10) == +10);

	// STATIC_ASSERT14(-fixed(10) - 5 == -15);

	// STATIC_ASSERT14(++fixed(5) == fixed(6));
	// STATIC_ASSERT14(fixed(5)++ == fixed(5));
	// STATIC_ASSERT14(--fixed(5) == fixed(4));
	// STATIC_ASSERT14(fixed(5)-- == fixed(5));

	// // test some constexpr comparisons stuff
	// static_assert(fixed{1} >    fixed{0}, "");
	// static_assert(fixed{0.5} <  fixed{1}, "");
	// static_assert(fixed{1} ==   fixed{1}, "");
	// static_assert(fixed{0} !=   fixed{1}, "");
	// static_assert(fixed{1} >=   fixed{0}, "");
	// static_assert(fixed{0.5} <= fixed{1}, "");

	// static_assert(fixed{1} >   0, "");
	// static_assert(fixed{0.5} < 1, "");
	// static_assert(fixed{1} ==   1, "");
	// static_assert(fixed{0} !=   1, "");
	// static_assert(fixed{1} >=   0, "");
	// static_assert(fixed{0.5} <= 1, "");

	// static_assert(1 >    fixed{0}, "");
	// static_assert(0.5 <  fixed{1}, "");
	// static_assert(1 ==   fixed{1}, "");
	// static_assert(0 !=   fixed{1}, "");
	// static_assert(1 >=   fixed{0}, "");
	// static_assert(0.5 <= fixed{1}, "");

	// // conversion test
	// assert(fixed(0x8000).to_uint() == 0x8000);

	return EXIT_SUCCESS;
}