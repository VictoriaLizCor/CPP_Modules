#include <ieee754.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include "../../CPP_02/ex02/includes/Fixed.hpp"

#define EPSILON 1.0e-7
#define LOG2_10 3.321928095
#define flt_equals(a, b) (fabs((a)-(b)) < EPSILON)
#define flt_zero(x) (fabs(x) < EPSILON)
 
int max_digs_rt = 10;  /* maximum # of 0's right of decimal before using
						 scientific notation */
int max_digs_lf = 10;  /* max # of digits left of decimal */

/**
 * @brief Prints a real number with a specific width and decimal precision.
 *
 * @param r The real number to print.
 * @param width The width of the printed number. If width is 0, no specific 
 * width is set.
 * @param dec The number of digits after the decimal point.
 *
 * The function calculates the magnitude of the number and decides whether to 
 * use scientific notation or fixed-point notation. It then formats the number 
 * accordingly and prints it.
 */
void print_real(double r, int width, int dec)
{
	int mag;
	double fpart, temp;
	char format[8];
	char num_format[3] = {'l',0,0};
	union ieee754_double *dl;
 
	dl = (union ieee754_double*)&r;
	mag = (dl->ieee.exponent - IEEE754_DOUBLE_BIAS) / LOG2_10;
	if (r == 0)
		mag = 0;
	if ((mag > max_digs_lf-1) || (mag < -max_digs_rt)) {
		num_format[1] = 'e';
		temp = r/pow(10, mag);	  /* see if number will have a decimal */
		fpart = temp - floor(temp); /* when written in scientific notation */
	}
	else {
		num_format[1] = 'f';
		fpart = r - floor(r);
	}
	if (flt_zero(fpart))
		dec = 0;
	if (width == 0) {
		snprintf(format, 8, "%%.%d%s", dec, num_format);
	}
	else {
		snprintf(format, 8, "%%%d.%d%s", width, dec, num_format);
	}
	printf(format, r);
}

int main()
{
	double number = 1234.5678;
	int width = 10;
	int dec = 5;

	print_real(number, width, dec);
	std:: cout << std::endl;
	return (0);
}