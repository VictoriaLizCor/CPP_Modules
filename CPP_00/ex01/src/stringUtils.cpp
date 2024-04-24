/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:32:12 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/24 09:29:10 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringUtils.h"

/**
 * @brief Applies color formatting to a given message.
 * 
 * @param msg The message to be colored.
 * @param color The color code to be applied.
 * @param err Flag indicating if the message is an error message.
 * @return The colored message.
 */
std::string	color(std::string msg, int color, bool err)
{
	std::string	strColor;
	std::string	strDefault;
	
	if (color == DEFAULT)
		return (msg);
	strColor = "\033[1;" + toString(color) + "m";
	strDefault = "\033[" + toString(DEFAULT) + "m";
	if (err)
		return (strColor + "Error: " + msg + strDefault);
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
 * Calculates the maximum length of strings in an array.
 * 
 * @param arraySize The size of the array.
 * @param arrayData The array of strings.
 * @return The maximum length of strings in the array.
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