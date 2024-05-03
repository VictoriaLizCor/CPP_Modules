/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:21:05 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/03 17:46:15 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


static std::string	setColor(std::string msg, int color)
{
	std::stringstream strColor;
	std::string	fmt;

	fmt = C_FMT;
	if (color >= FDEFAULT)
		fmt = fmt + "1;";
	strColor << fmt << color << "m" << msg << C_DEFAULT;
	return (strColor.str());
}


/**
 * @brief Prints a string followed by a newline.
 *
 * This function takes a string as input and prints it to the standard output
 * followed by a newline. It uses the std::cout object from the iostream library
 * to print the string.
 *
 * @param str The string to print.
 */
static void	println(std::string str)
{
	std::cout << str << std::endl;
}

Zombie::Zombie()
{
	this->_name = setColor("Unknown", FRED);
	println("*" + setColor(this->_name, FRED) + ": " + setColor("\tCreated", DEFAULT));
	return ;
}

#if (DEBUG == 1)
Zombie::Zombie(std::string name)
{
	this->_name = name;
	println("*" + this->_name + ": " + setColor("\t\tCreated", FDEFAULT));
	return ;
}
#else
static std::string	redColorRGB(std::string msg)
{
	std::stringstream redStr;
	std::stringstream gbStr;
	static int redShade = 128;
	static int inc = 0;

	if (redShade >= 255)
		redShade = 128;
	redShade += (10 + inc);
	if (inc >= 20)
		inc = 0;
	inc += 1;
	gbStr << ";" << inc << ";" << inc << "m";
	redStr << C_FMT << "1;" << FLRGB << ";2;" << redShade << gbStr.str();
	return (redStr.str() + msg + C_DEFAULT);
}
Zombie::Zombie(std::string name)
{
	this->_name = redColorRGB(name);
	println("*" + this->_name + ": " + setColor("\t\tCreated", FDEFAULT));
	return ;
}
#endif

Zombie::~Zombie()
{
	if (this->_name == setColor("Unknown", FRED))
		println("*" + this->_name + ": " + setColor("\tDestroyed", DEFAULT));
	else
		println("*" + this->_name + ": " + setColor("\t\tDestroyed", FDARKGRAY));
	return ;
}


void	Zombie::announce(void)
{
	println(this->_name + ":\t\t" + setColor("BraiiiiiiinnnzzzZ...", BRED));
	return ;
}