#include <iostream>
#include <bitset>
#include "../../CPP_02/ex02/includes/Fixed.hpp"

void compareFloatAndFixed(float number, Fixed fixedNumber) {
	// Assuming that float is 4 bytes
	if(sizeof(float) != 4) {
	std::cout << "Unsupported float size for IEEE 754 representation" << std::endl;
	return;
	}

	// Cast float to unsigned int
	unsigned int binary = *(unsigned int*)&number;

	// Print sign bit
	std::cout << "Float Sign: " << ((binary >> 31) ? "-" : "+") << std::endl;

	// Print exponent bits
	std::bitset<8> exponentBits((binary >> 23) & 0xFF);
	std::cout << "Float Exponent: " << exponentBits << std::endl;

	// Print fraction bits
	std::bitset<23> fractionBits(binary & 0x7FFFFF);
	std::cout << "Float Fraction: " << fractionBits << std::endl;

	// Print Fixed point value
	std::cout << "Fixed Point Value: " << fixedNumber.toFloat() << std::endl;
}

int main() {
	float number = 0.15625f;
	compareFloatAndFixed(number, Fixed(number));
	return 0;
}
