/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringUtils.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:13:36 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/25 12:41:51 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
#ifndef STRINGUTILS_H
# define STRINGUTILS_H
# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>

# define C_FMT "\033["
# define C_DEFAULT "\033[0m"

# ifndef DEBUG
#  define DEBUG 0
# endif

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
	BGRAY			= 100,
} t_color;

void		println(std::string str);
std::string	toString(int value);
std::string	sColor(const std::string& msg, int color, bool err);
std::string	gColor(const std::string& msg, std::string color);
std::string rColor(int bold);
bool		checkInput(const std::string& str, int (*check_type)(int));
bool		isOnlySpaces(const std::string& str);
size_t		maxStringLength(int fieldSize, std::string* arrayData);
std::string	center(const std::string& s, int width);
#endif