#include "Utils.hpp"

/**
 * @brief Get the colored name.
 * This function returns the colored name.
 * @return The colored name.
 */
std::string s_coloredName::getName() const
{
	return (colorStr + str + C_END);
}

/**
 * @brief Prints a string followed by a newline.
 *
 * This function takes a string as input and prints it to the standard output
 * followed by a newline. It uses the std::cout object from the iostream
 * library to print the string.
 *
 * @param str The string to print.
 * std::string string1 = "Hello";
 * std::string string2 = "World";
 * printnl(std::cout, string1);
 * printnl(std::cout, string2);
 */
void coutnl(std::ostream& os)
{
	os << std::endl;
}


/**
 * @brief Formats a string with color for console output.
 *
 * This function takes a message string, a color code, and a boolean error flag.
 * It returns the message string formatted with the specified color. If the error
 * flag is true, it prepends "ERROR:" to the message and sets the color to red,
 * regardless of the specified color code.
 *
 * @param msg The message string to be formatted.
 * @param color The color code for the message. This should be a value from the
 *              t_color enum.
 * @param err A boolean flag indicating whether the message is an error message.
 * @return The formatted message string.
 */
std::string	getColorFmt(int eColor)
{
	std::ostringstream strColor;
	std::string	fmt;

	fmt = C_FMT;
	if (eColor < 0)
		eColor = DEFAULT;
	if (eColor > FGRAY)
		fmt += "1;";
	strColor << fmt << eColor << "m";
	return (strColor.str());
}

/**
 * Generates an error message with optional formatting.
 *
 * @param str The error message to be displayed.
 * @param bold A boolean value indicating whether the error message should be
 * displayed in bold.
 * @return The formatted error message.
 */
std::string error(std::string str, bool bold)
{
	std::ostringstream strColor;
	std::string	fmt;

	fmt = C_FMT;
	if (bold)
		fmt += "1;";
	strColor << fmt << FRED << "m"
	<< "ERROR: " << str << C_END;
	return (strColor.str());
}

/**
 * @brief Converts an integer value to a string.
 * 
 * @param value The integer value to be converted.
 * @return std::string The string representation of the integer value.
 */
std::string toStr(int value)
{
	std::ostringstream ss;
	ss << value;
	return (ss.str());
}

/**
 * @brief Concatenates a color code, a message, and a default color code.
 *
 * This function takes a message and a color code as input and concatenates them
 * with a default color code. The resulting string is returned.
 *
 * @param msg The message to be colored.
 * @param color The color code to be applied to the message.
 * @return The colored message.
 * gColor(msg, rColor(1));
 */
std::string	getColorStr(t_Name const& name)
{
	return (name.colorStr + name.str + C_END);
}


/**
 * Concatenates the given color string with the input string and the default color string.
 * 
 * @param eColor The color string to be concatenated.
 * @param str The input string to be concatenated.
 * @return The concatenated string with the color string and the default color string.
 */
std::string	getColorStr(std::string const& eColor, std::string const& str)
{
	return (eColor + str + std::string(C_END));
}

/**
 * Returns a string with the specified color formatting applied.
 *
 * @param eColor The color code to apply to the string.
 * @param str The input string.
 * @return The formatted string with the specified color.
 */
std::string	getColorStr(int eColor, std::string const& str)
{
	return (getColorFmt(eColor) + str + std::string(C_END));
}

std::string	getColorStr(int eColor, lsi num)
{
	std::ostringstream os;
	os << getColorFmt(eColor) << num << C_END;
	return (os.str());
}

/**
 * @brief Generates an RGB color string for terminal output.
 *
 * Constructs a string that represents an RGB color using ANSI escape codes.
 * This string can be used to set text color in terminal outputs. The function
 * takes three integers representing the red, green, and blue components of the
 * color, each in the range [0, 255].
 *
 * @param red The red component of the color, [0, 255].
 * @param green The green component of the color, [0, 255].
 * @param blue The blue component of the color, [0, 255].
 * @return std::string The ANSI escape code string for the RGB color.
 */
static std::string	rColorRGB(int red, int green, int blue)
{
	std::ostringstream ss;

	ss << FLRGB << ";2;";
	ss << red << ";" << green << ";" << blue << "m";
	return (ss.str());
}

/**
 * Generates a random integer between the given minimum and maximum values.
 *
 * @param min The minimum value for the random number (inclusive).
 * @param max The maximum value for the random number (inclusive).
 * @return A random integer between the minimum and maximum values.
 */
int ft_rand(int min, int max)
{
	static bool seeded = false;
	if (!seeded)
	{
		srand(static_cast<unsigned int>(time(0)));
		seeded = true;
	}
	if (min < 0 || min > 256|| max < 0 || max > 256)
		return (255);
	return (rand() % (max - min + 1) + min);
}

/**
 * @brief Generate a colored string with optional bold formatting.
 * 
 * @param msg The message to be colored.
 * @param bold Whether to apply bold formatting.
 * @return std::string The colored string.
 * strColor << fmt
	<< rColorRGB(ft_rand(80, 200), ft_rand(80, 200), ft_rand(80, 200));
 */
std::string getRandomColorFmt(bool bold)
{
	std::ostringstream strColor;
	std::string	fmt;

	fmt = C_FMT;
	if (bold)
		fmt = fmt + "1;";
	strColor << fmt
	<< rColorRGB(ft_rand(60, 255), ft_rand(60, 255), ft_rand(60, 255));
	return (strColor.str());
}

/**
 * @brief Sets the color name based on the provided color code.
 * 
 * @param color The color code.
 * @return std::string The color name.
 */
std::string setObjColor(int const& color)
{
	if (DEBUG == 0)
	{
		if ((color > FWHITE && color < BGRAY ) || color > 107)
			return(getRandomColorFmt(1));
		return (getColorFmt(color));
	}
	else
		return (getRandomColorFmt(1));
}

/**
 * @brief Checks if all characters in a string satisfy a given condition.
 *
 * @param str The input string to be checked.
 * @param check_type A function pointer to the condition that each character
 * must satisfy.
 * @return true if all characters satisfy the condition, false otherwise.
 */
bool	checkInput(const std::string& str, int (*check_type)(int))
{
	std::string::const_iterator it;
	
	it = str.begin();
	while (it != str.end())
	{
		if (!check_type(*it) && !std::isspace(*it))
			return false;
		it++;
	}
	return true;
}

/**
 * @brief Checks if a string contains only spaces.
 *
 * This function takes a string as input and iterates through each character.
 * If it finds a character that is not a space, it returns false. If it
 * doesn't find any non-space characters, it returns true.
 *
 * @param str The string to check.
 * @return true if the string contains only spaces, false otherwise.
 */
bool	isOnlySpaces(const std::string& str)
{
	std::string::const_iterator it;
	
	for (it = str.begin(); it != str.end(); it++)
	{
		if (*it != ' ')
			return false;
	}
	return true;
}

/**
 * @brief Finds the maximum string length in an array.
 *
 * This function takes an array size and a string array as input. It iterates
 * through the array and finds the length of the longest string. It returns
 * the length of the longest string.
 *
 * @param arraySize The size of the string array.
 * @param arrayData The string array to search.
 * @return The length of the longest string in the array.
 */
size_t	maxStringLength(int arraySize, std::string* arrayData)
{
	int			i;
	size_t		len;

	i = 0;
	len = 0;
	while (i < arraySize)
	{
		if (len < arrayData[i].length())
			len = arrayData[i].length();
		i++;
	}
	return (len);
}

/**
 * @brief Centers a string within a specified width.
 *
 * This function takes a string and a target width, then pads the string with
 * spaces on both sides such that it appears centered if printed in a field of
 * the given width. If the required padding is odd, the extra space is added to
 * the left side of the string.
 *
 * @param s The string to center.
 * @param width The total width of the field in which to center the string.
 * @return std::string The centered string, padded with spaces.
 */
std::string	center(const std::string& s, std::string::size_type width)
{
	if (width <= s.size())
		return s;
	std::string::size_type padding = width - s.size();
	std::string::size_type left = padding / 2 + padding % 2;
	std::string::size_type right = padding / 2;
	return (std::string(left, ' ') + s + std::string(right, ' '));
}

/**
 * @brief Extracts and returns the class name from a mangled string.
 *
 * This function takes a mangled class name as input and returns a cleaner
 * version of the class name by removing any leading numeric characters. If the
 * input string does not contain any non-numeric characters, an empty string is
 * returned.
 *
 * @param str The mangled class name string.
 * @return std::string The cleaned class name without leading numeric
 * characters.
 */
std::string className(const std::string& str)
{
	size_t pos = str.find_first_not_of("0123456789");
	if (pos != std::string::npos)
		return str.substr(pos);
	else
		return "";
}

/**
 * Generates a random string of length 10.
 * 
 * @return The randomly generated string.
 */
std::string getRandString()
{
	static bool seeded = false;
	std::string randomStr= "";
	size_t strLen = 10;

	if (!seeded)
	{
		srand(static_cast<unsigned int>(time(0)));
		seeded = true;
	}
	for(size_t i = 0; i < strLen; i++)
	{
		char random_char = 'a' + static_cast<char>(rand() % 26); // random character between 'a' and 'z'
		randomStr += random_char;
	}
	return (randomStr);
}

/**
 * Prints a title surrounded by equal signs.
 * 
 * @param title The title to be printed.
 */
void printTitle(std::string title, int n)
{
	int size = n;
	std::string toPrint = " " + title + " "; 

	if (size <= 0 || size > 60)
		size = 60;
	int len = static_cast<int>(toPrint.size());
	int padding = (size - len) / 2;

	if (len % 2 != 0 && size % 2 == 0)
		padding++;

	std::cout << std::setfill('=') << std::setw(padding) << "";
	std::cout << toPrint;
	std::cout << std::setfill('=') << std::setw(size - len - padding)
	<< "" << std::endl;
}

size_t getRandomNum(size_t num)
{
	static bool seeded = false;
	if (!seeded)
	{
		srand(static_cast<unsigned int>(time(0)));
		seeded = true;
	}
	return (static_cast<size_t>(rand()) % num);
}