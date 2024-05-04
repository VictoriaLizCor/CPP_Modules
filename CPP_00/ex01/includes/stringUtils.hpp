/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringUtils.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:13:36 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/04 12:19:43 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
#ifndef STRINGUTILS_H
# define STRINGUTILS_H
# include <iostream>
# include <string>
# include <sstream>
#include <cstdlib>

# define C_FMT "\033["
typedef enum eColor
{
	DEFAULT			= 0,
	FBLACK			= 30,
	FRED			= 31,
	FGREEN			= 32,
	FYELLOW			= 33,
	FBLUE			= 34,
	FMAGENTA		= 35,
	FCYAN			= 36,
	FLGRAY			= 37,
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
	BDEFAULT		= 49,
	FDARKGRAY		= 90,
	FLRED			= 91,
	FLGREEN			= 92,
	FLYELLOW		= 93,
	FLBLUE			= 94,
	FLMAGENTA		= 95,
	FLCYAN			= 96,
	FWHITE			= 97,
} t_color;

void		println(std::string str);
std::string	toString(int value);
std::string	color(std::string msg, int color, bool err);
bool		checkInput(const std::string& str, int (*check_type)(int));
bool		isOnlySpaces(const std::string& str);
size_t		maxStringLength(int fieldSize, std::string* arrayData);
std::string	center(std::string s, int width);
std::string rColorRGB(int r, int g, int b);
std::string rColor(std::string msg, int bold);
#endif