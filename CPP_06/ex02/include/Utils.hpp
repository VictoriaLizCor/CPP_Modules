/**
 * @file Utils.hpp
 * @author lilizarr (lilizarr@student.42wolfsburg.de)
 * @brief 
 * @version 0.1
 * @date 2024-09-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef STRINGUTILS_H
# define STRINGUTILS_H
# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <iomanip>
# include <cxxabi.h>
# ifndef DEBUG
#  define DEBUG 0
# endif

# define C_FMT "\033["
# define C_FMT256 "\033[0;38;5;"
# define C_FMT256B "\033[1;38;5;"
# define C_END "\033[0m"

/*
	FL is light foreground color
	B is background color
	F is foreground color
*/
typedef enum eColor
{
	DEFAULT			= 0,
	FLBLACK			= 30,
	FLRED			= 31,
	FLGREEN			= 32,
	FLYELLOW		= 33,
	FLBLUE			= 34,
	FLMAGENTA		= 35,
	FLCYAN			= 36,
	FLWHITE			= 37,
	FLRGB			= 38, //\033[38;2;r;g;bm (rgb:from 0 to 255).
	FDEFAULT		= 39,
	BBLACK			= 40,
	BRED			= 41,
	BGREEN			= 42,
	BYELLOW			= 43,
	BBLUE			= 44,
	BMAGENTA		= 45,
	BCYAN			= 46,
	BWHITE			= 47,
	BRGB			= 48, //\033[48;2;r;g;bm (rgb:from 0 to 255).
	BDEFAULT		= 49,
	FGRAY			= 90,
	FRED			= 91,
	FGREEN			= 92,
	FYELLOW			= 93,
	FBLUE			= 94,
	FMAGENTA		= 95,
	FCYAN			= 96,
	FWHITE			= 97,
	BGRAY			= 100
}	t_color;

std::string	error(std::string str, bool bold);
void		nl(size_t newLines);
void		debug(int eColor, std::string str);
std::string	toStr(int value);
std::string	getColorFmt(int eColor);
std::string	getColorStr(std::string const& eColor, std::string const& str);
std::string	getColorStr(int eColor, std::string const& str);
std::string	getRandomColorFmt(bool bold);
std::string	getColorShade(int eColor, int pattern);
std::string	getColorShade(int eColor);
std::string	setObjColor(int const& color);
void		printTitle(std::string title, int n, char c);

template <typename T>
T getRandomNum(size_t num)
{
	static bool seeded = false;
	if (!seeded)
	{
		srand(static_cast<unsigned int>(time(0)));
		seeded = true;
	}
	return (static_cast<T>(rand()) % num);
}

#endif