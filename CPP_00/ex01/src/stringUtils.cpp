/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:32:12 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/03 16:01:04 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringUtils.hpp"

/**
 * @brief Applies color formatting to a string message.
 *
 * This function accepts a string message, a color code, and a boolean error
 * flag. It applies the specified color code to the message. If the color code
 * is DEFAULT, it leaves the message unchanged. If the color code exceeds
 * FDEFAULT(39), the function applies bold formatting to the message. If the
 * error flag is set to true, the function applies the FLRED(41) color to the
 * message and prepends "Error: " to the start of the message.
 *
 * @param msg The message to which color formatting will be applied.
 * @param color The color code defining the color formatting.
 * @param err The error flag indicating whether the message is an error.
 * @return The message after color formatting has been applied.
 */
std::string	color(std::string msg, int color, bool err)
{
	std::string	strColor;
	std::string	strDefault;
	std::string	fmt;

	if (color == DEFAULT)
		return (msg);
	fmt = C_FMT;
	if (color >= FDEFAULT)
		fmt = fmt + "1;";
	strColor = fmt + toString(color) + "m";
	strDefault = fmt + toString(DEFAULT) + "m";
	if (err)
		return (fmt + toString(FLRED) + "m" + "Error: " + msg + strDefault);
	else
		return (strColor + msg + strDefault);
}

/**
 * @brief Converts an integer value to a string.
 * 
 * @param value The integer value to be converted.
 * @return std::string The string representation of the integer value.
 */
std::string toString(int value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

std::string rColorRGB(int r, int g, int b)
{
	std::stringstream ss;

	ss << toString(FLRGB) << ";2;";
	ss << toString(r) << ";" << toString(g) << ";" << toString(b) << "m";
	return (ss.str());
}

std::string rColor(std::string msg, int bold)
{
	std::stringstream strColor;
	std::string	fmt;

	fmt = C_FMT;
	if (bold)
		fmt = fmt + "1;";
	strColor << fmt << rColorRGB(rand() % 256, rand() % 256, rand() % 256);
	return (strColor.str() + msg + fmt + toString(DEFAULT) + "m");
}

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

std::string	center(std::string s, int width)
{
	int padding = width - s.size();
	int left = padding / 2 + padding % 2;
	int right = padding / 2;
	return (std::string(left, ' ') + s + std::string(right, ' '));
}