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

/**
 * @struct s_coloredName
 * @brief Struct for storing a colored name.
 *
 * This struct stores a name and its associated color.
 * inline std::string getName() const
 * {
 * 	return (color + str + C_END);
 * }
 */
struct s_coloredName
{
	std::string		str;
	std::string		colorStr;

	std::string getName() const;
	
};

typedef long double lsi;
typedef s_coloredName t_Name;

std::string error(std::string str, bool bold);
void nl(size_t newLines);
void		out(std::ostream& os);
void		debug(int eColor, std::string str);
std::string	toStr(int value);
std::string	getColorFmt(int eColor);
// std::string	getColorStr(t_Name const& name);
std::string	getColorStr(std::string const& eColor, std::string const& str);
std::string	getColorStr(int eColor, std::string const& str);
std::string	getColorStr(int eColor, lsi num);
int			ft_rand(int min, int max);
std::string	getRandomColorFmt(bool bold);
std::string	getColorShade(int eColor, int pattern);
std::string	getColorShade(int eColor);
std::string	setObjColor(int const& color);
bool		checkInput(const std::string& str, int (*check_type)(int));
bool		isOnlySpaces(const std::string& str);
std::string toUpperCase(std::string const& str);
size_t		maxStringLength(int fieldSize, std::string* arrayData);
std::string	center(const std::string& s, std::string::size_type width);
std::string	className(const std::string& str);
std::string	classFunctionStr(std::string const& c, std::string const& f);
std::string	demangle(const char* mangled_name);
void		printTitle(std::string title, int n);
size_t		countNewlines(const std::string& str);
void printTitle(std::string title, int n, char c);

#endif