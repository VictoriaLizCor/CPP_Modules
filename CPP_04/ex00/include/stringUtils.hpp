#ifndef STRINGUTILS_H
# define STRINGUTILS_H
# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>

# ifndef DEBUG
#  define DEBUG 0
# endif

# define C_FMT "\033["
# define C_DEFAULT "\033[0m"

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
} t_color;

/**
 * @struct s_coloredName
 * @brief Struct for storing a colored name.
 *
 * This struct stores a name and its associated color.
 * inline std::string getName() const
 * {
 * 	return (color + str + C_DEFAULT);
 * }
 */
struct s_coloredName
{
	std::string		str;
	std::string		color;

	std::string getName() const;
	
};

typedef s_coloredName t_Name;
void 		coutnl(std::ostream& os);
std::string	toString(int value);
std::string	setColor(const std::string& msg, unsigned int color, bool err);
std::string	setColor(const std::string& msg, std::string const& color, bool err);
std::string	getColorStr(t_Name const& name);
std::string setRandomColor(bool bold);
std::string setObjColor(unsigned int const& color);
bool		checkInput(const std::string& str, int (*check_type)(int));
bool		isOnlySpaces(const std::string& str);
size_t		maxStringLength(int fieldSize, std::string* arrayData);
std::string	center(const std::string& s, std::string::size_type width);
std::string	className(const std::string& str);

#endif