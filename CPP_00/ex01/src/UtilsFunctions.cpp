/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsFunctions.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:32:12 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/19 13:10:44 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UtilsFunctions.hpp"

std::string	color(std::string msg, int color, bool err)
{
	std::string	strColor;
	std::string	strDefault;
	
	if (color == DEFAULT)
		return (msg);
	strColor = "\033[1;" + toString(color) + "m";
	strDefault = "\033[" + toString(DEFAULT) + "m";
	// println("\nstrColor = " + toString(strColor.length()));
	// println("msg[" + msg + "] = " + toString(msg.length()));
	// println("strDefault = " + toString(strDefault.length()));
	if (err)
		return (strColor + "Error: " + msg + strDefault);
	else
		return (strColor + msg + strDefault);
}

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

bool	checkInput(const std::string& str, int (*check_type)(int))
{
	std::string::const_iterator it;
	
	it = str.begin();
	while (it != str.end())
	{
		if (!check_type(*it))
			return false;
		it++;
	}
	return true;
}

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

// static std::string	center(const std::string& s, int width)
// {
// 	int padding = width - s.size();
// 	int left = padding / 2 + padding % 2;
// 	int right = padding / 2;
// 	return (std::string(left, ' ') + s + std::string(right, ' '));
// }