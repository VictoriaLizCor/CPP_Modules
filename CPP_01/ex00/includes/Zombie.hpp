/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:15:04 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/03 17:42:24 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>
# include <sstream>

# ifndef DEBUG
#  define DEBUG 0
# endif

# define C_FMT "\033["
# define C_DEFAULT "\033[0m"

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
	FGRAY			= 37,
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
	COLOR_COUNT	 	= 27,
} t_color;


class Zombie
{
	private:
		std::string	_color;
		std::string	_name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce(void);
};
Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
#endif