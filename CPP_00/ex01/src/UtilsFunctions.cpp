/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsFunctions.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:32:12 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/18 13:49:04 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UtilsFunctions.hpp"

std::string	color(std::string msg, int color, bool err)
{
	std::string	strColor;
	std::string	strDefault;
	
	strColor = "\033[1;" + std::to_string(color) + "m";
	strDefault = "\033[" + std::to_string(DEFAULT) + "m";
	if (err)
		return (strColor + "Error: " + msg + strDefault);
	else
		return (strColor + msg + strDefault);
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
// static std::string	center(const std::string& s, int width)
// {
// 	int padding = width - s.size();
// 	int left = padding / 2 + padding % 2;
// 	int right = padding / 2;
// 	return (std::string(left, ' ') + s + std::string(right, ' '));
// }