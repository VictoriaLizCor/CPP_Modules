/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:07:44 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/22 15:11:40 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
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

/**
 * @brief Sets the color of a message.
 *
 * This function takes a message and a color code as input and returns the
 * message with the specified color. The color code is an integer value that
 * represents a specific color. If the message is empty, only the color code is
 * returned.
 *
 * @param msg The message to be colored.
 * @param color The color code to be applied to the message.
 * @return The colored message.
 */
static std::string	setColor(std::string msg, int color)
{
	std::ostringstream strColor;
	std::string	fmt;

	fmt = "\033[";
	if (msg.empty())
	{
		color = FDEFAULT;
		msg = "Unknown";
	}
	if (color >= FDEFAULT)
		fmt = fmt + "1;";
	strColor << fmt << color << "m" << msg << "\033[0m";
	return (strColor.str());
}

int main()
{
	std::string weapon1 = setColor("crude spiked club", FLRED);
	std::string weapon2 = setColor("some other type of club", FLYELLOW);
	{
		Weapon club = Weapon(weapon1);
		HumanA bob(setColor("Bob", FLBLUE), club);
		bob.attack();
		club.setType(weapon2);
		bob.attack();
	}
	{
		Weapon club = Weapon(weapon1);
		HumanB jim(setColor("Jim", FGREEN));
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType(weapon2);
		//club.setType("");
		jim.attack();
		jim.setWeapon(&club);
		jim.attack();
		jim.setWeapon(0);
		jim.attack();
	}
	return (0);
}
