/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:32:12 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/23 11:48:33 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringUtils.hpp"

/**
 * @brief Prints a string followed by a newline.
 *
 * This function takes a string as input and prints it to the standard output
 * followed by a newline. It uses the std::cout object from the iostream
 * library to print the string.
 *
 * @param str The string to print.
 */
void	println(std::string str)
{
	std::cout << str << std::endl;
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
std::string	sColor(const std::string& msg, int color, bool err)
{
	std::ostringstream strColor;
	std::string	fmt;

	fmt = C_FMT;
	if (err)
		strColor << fmt << FRED << "m" << "ERROR:";
	else
		strColor << fmt << color << "m";
	if (msg.empty())
		return (strColor.str());
	if (color >= FDEFAULT)
		fmt += "1;";
	strColor << msg << C_DEFAULT;
	return (strColor.str());
}

/**
 * @brief Converts an integer value to a string.
 * 
 * @param value The integer value to be converted.
 * @return std::string The string representation of the integer value.
 */
std::string toString(int value)
{
	std::ostringstream ss;
	ss << value;
	return ss.str();
}

/**
 * @brief Generates a formatted string representing an RGB color.
 *
 * This function takes three integer values representing the red, green, and
 * blue components of an RGB color and returns a formatted string representing
 * the color in ANSI escape code format.
 *
 * @param red The red component of the RGB color.
 * @param green The green component of the RGB color.
 * @param blue The blue component of the RGB color.
 * @return A formatted string representing the RGB color in ANSI escape code
 * format.
 */

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
std::string	gColor(const std::string& msg, std::string color)
{
	return (color + msg + C_DEFAULT);
}

static std::string	rColorRGB(int red, int green, int blue)
{
	std::ostringstream ss;

	ss << C_FMT << "1;" << FLRGB << ";2;";
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
static int ft_rand(int min, int max)
{
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
 */
std::string rColor(int bold)
{
	std::ostringstream strColor;
	std::string	fmt;

	fmt = C_FMT;
	if (bold)
		fmt = fmt + "1;";
	strColor << fmt << rColorRGB(ft_rand(80, 150), ft_rand(80, 200), ft_rand(80, 200));
	return (strColor.str());
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
		if (!check_type(*it) && !isspace(*it))
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

std::string	center(const std::string& s, int width)
{
	int padding = width - s.size();
	int left = padding / 2 + padding % 2;
	int right = padding / 2;
	return (std::string(left, ' ') + s + std::string(right, ' '));
}