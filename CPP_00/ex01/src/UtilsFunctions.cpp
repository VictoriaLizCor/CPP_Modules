/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsFunctions.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:32:12 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/17 13:17:02 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UtilsFunctions.hpp"

void	println(std::string str)
{
	std::cout << str << std::endl;
}

bool	checkInput(const std::string& str, int (*func)(int))
{
	std::string::const_iterator it;
	
	it = str.begin();
	while (it != str.end())
	{
		if (!func(*it))
			return false;
		it++;
	}
	return true;
}