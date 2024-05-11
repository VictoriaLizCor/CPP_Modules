/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:07:44 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/11 15:24:35 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Files.hpp"
#include <sstream>

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
	FLGRAY			= 37,
	FLRGB			= 38, //\033[38;2;r;g;bm (rgb:from 0 to 255).
	FDEFAULT		= 39,
	FDARKGRAY		= 90,
	FRED			= 91,
	FGREEN			= 92,
	FYELLOW			= 93,
	FBLUE			= 94,
	FMAGENTA		= 95,
	FCYAN			= 96,
	FWHITE			= 97,
	COLOR_COUNT	 	= 27,
} t_color;

// /**
//  * @brief Sets the color of a message.
//  *
//  * This function takes a message and a color code as input and returns the
//  * message with the specified color. The color code is an integer value that
//  * represents a specific color. If the message is empty, only the color code is
//  * returned.
//  *
//  * @param msg The message to be colored.
//  * @param color The color code to be applied to the message.
//  * @return The colored message.
//  */
static std::string	setColor(std::string msg, int color, int err)
{
	std::ostringstream strColor;
	std::string	fmt;

	fmt = "\033[";
	if (color == DEFAULT)
		return (msg);
	if (err)
		 msg = "Error: " + msg;
	if (color >= FDEFAULT)
		fmt = fmt + "1;";
	strColor << fmt << color << "m" << msg << "\033[0m";
	return (strColor.str());
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << setColor("Usage: ./replace filename s1 s2\n", FRED, 1);
		return (1);
	}
	else if (std::string(av[2]).empty() || std::string(av[3]).empty())
	{
		std::cerr << setColor("s1 and s2 must not be empty.\n", FRED, 1);
		return (1);
	}
	else
	{
		//Creates a Files object
		Files f1(av[1], std::ios::in);

		//Reads from Files instances, creates another one 
		// and writes to another file, adding ".replace" to the name
		Files f2(f1, av[2], av[3]);

		//Creates a Files object with the same name as f1
		// Files f3(f1);
		Files f4(av[1]);
		f4.replaceInFile(av[2], av[3]);
		return (0);
	}
}
