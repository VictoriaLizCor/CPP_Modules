/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringUtils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:56:07 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/24 09:29:16 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGUTILS_H
# define STRINGUTILS_H
# pragma once
# include <iostream>
# include <string>
# include <sstream>

typedef enum eColor
{
	DEFAULT		= 0,
	FRED		= 31,
	FGREEN		= 32,
	FBLUE		= 34,
	FDEFAULT	= 39,
	BRED		= 41,
	BGREEN		= 42,
	BBLUE		= 44,
	BDEFAULT	= 49
}	t_color;

void		println(std::string str);
std::string	toString(int value);
std::string	color(std::string msg, int color, bool err);
bool		checkInput(const std::string& str, int (*check_type)(int));
size_t		maxStringLength(int fieldSize, std::string* arrayData);
std::string	center(std::string s, int width);
#endif