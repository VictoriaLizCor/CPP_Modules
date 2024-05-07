/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:21:05 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/07 15:30:03 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string Zombie::getName(Zombie &z){
	return (z._name);
}

static std::string	setColor(std::string msg, int color)
{
	std::ostringstream strColor;
	std::string	fmt;

	fmt = C_FMT;
	if (msg.empty())
	{
		strColor << fmt << color << "m";
		return (strColor.str());
	}
	if (color >= FDEFAULT)
		fmt = fmt + "1;";
	strColor << fmt << color << "m" << msg << C_DEFAULT;
	return (strColor.str());
}

static std::string	getColor(std::string msg, std::string color)
{
	return (color + msg + C_DEFAULT);
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

/******************************* CONSTRUCTORS ****************/
Zombie::Zombie()
{
	_name = "Unknown";
	_color = setColor("", FRED);
	if (_name.length() > 5)
		println(getColor(_name, _color) + ": " + setColor("\tCreated", DEFAULT));
	else
		println(getColor(_name, _color) + ": " + setColor("\t\tCreated", DEFAULT));
	return ;
}

#if (DEBUG == 1)

static std::string	rColorRGB(int red, int green, int blue)
{
	std::ostringstream ss;

	ss << C_FMT << "1;" << FLRGB << ";2;";
	ss << red << ";" << green << ";" << blue << "m";
	return (ss.str());
}

static int ft_rand(int min, int max)
{
	if (min < 0 || min > 256|| max < 0 || max > 256)
		return (255);
	return (rand() % (max - min + 1) + min);
}

/**
 * @brief Generate a colored string with optional bold formatting.
 * 
 * @param msg The message to be colored.
 * @param bold Whether to apply bold formatting.
 * @return std::string The colored string.
 */
std::string rColor(int bold)
{
	std::ostringstream strColor;
	std::string	fmt;

	fmt = C_FMT;
	if (bold)
		fmt = fmt + "1;";
	strColor << fmt << rColorRGB(ft_rand(80, 150), ft_rand(80, 200), ft_rand(80, 200));
	return (strColor.str());
}

Zombie::Zombie(std::string name)
{
	_name = name;
	_color = rColor(1);
	if (_name.length() > 5)
		println(getColor(_name, _color) + ": " + setColor("\tCreated", FDEFAULT));
	else
		println(getColor(_name, _color) + ": " + setColor("\t\tCreated", FDEFAULT));
	return ;
}

#else

static std::string	redColorRGB()
{
	std::ostringstream redStr;
	std::ostringstream gbStr;
	static int redShade = 150;
	static int inc = 0;

	if (redShade >= 210)
		redShade = 150;
	redShade += (5 + inc);
	if (inc >= 20)
		inc = 0;
	inc += 5;
	gbStr << ";" << inc + 2 << ";" << inc + 2 << "m";
	redStr << C_FMT << "1;" << FLRGB << ";2;" << redShade << gbStr.str();
	return (redStr.str());
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	this->_color = redColorRGB();
	if (this->_name.length() > 5)
		println(getColor(_name, _color) + ": " + setColor("\tDestroyed", FDEFAULT));
	else
		println(getColor(_name, _color) + ": " + setColor("\t\tDestroyed", FDEFAULT));
	return ;
}
#endif
/*******************************************************/
Zombie::~Zombie()
{
	if (this->_name.length() > 5)
		println(getColor(_name, _color) + ": " + setColor("\tDestroyed", DEFAULT));
	else
		println(getColor(_name, _color) + ": " + setColor("\t\tDestroyed", FDARKGRAY));
	return ;
}


void	Zombie::announce(void)
{
	if (this->_name.length() > 5)
		println(getColor(_name, _color) + ": \t" + setColor("BraiiiiiiinnnzzzZ...", BRED));
	else
		println(getColor(_name, _color) + ": \t\t" + setColor("BraiiiiiiinnnzzzZ...", BRED));
	return ;
}