/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:21:05 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/07 17:35:07 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int Zombie::_counter = 0;

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
	std::ostringstream newName;

	_counter++;
	newName << "WhiteWalker" << _counter;
	_name = newName.str();
	_color = setColor("", FRED);
	println(getColor(_name, _color) + ": " + setColor("\tCreated", DEFAULT));
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

Zombie::Zombie(std::string name): _name(name),_color(rColor(1))
{
	_counter++;
	std::string tab = ": \t";
	if (this->_name.length() < 6)
		tab += "\t";
	println(getColor(_name, _color) + tab + setColor("Created", FDEFAULT));
	return ;
}

#else

static std::string	rColor(int bold)
{
	std::ostringstream	redStr;
	std::ostringstream	gbStr;
	static int			redShade;
	static int			inc;

	if (redShade <= 0 || redShade >= 210)
		redShade = 150;
	redShade += (5 + inc);
	if (inc >= 20)
		inc = 0;
	inc += 5;
	gbStr << ";" << inc + 2 << ";" << inc + 2 << "m";
	if (bold)
		redStr << C_FMT << "1;" << FLRGB << ";2;" << redShade << gbStr.str();
	else
		redStr << C_FMT << FLRGB << ";2;" << redShade << gbStr.str();
	return (redStr.str());
}

Zombie::Zombie(std::string name)
{
	_counter++;
	this->_name = name;
	this->_color = rColor(1);
	println(getColor(_name, _color)+ ": " + setColor("\t\tCreated", FDEFAULT));
	return ;
}
#endif
/*******************************************************/
Zombie::~Zombie()
{
	std::string tab = ": \t";
	
	if (this->_name.length() < 6)
		tab += "\t";
	if (this->_name == "Unknown")
		println(getColor(_name, _color) + tab + setColor("Destroyed", DEFAULT));
	else
		println(getColor(_name, _color) + tab + setColor("Destroyed", FDARKGRAY));
	_counter--;
	return ;
}

void	Zombie::setName(std::string name)
{
	std::string tab = ": \t";
	
	if (this->_name.length() < 6)
		tab += "\t";
	std::cout << getColor(_name, _color) + tab + setColor("Renamed ", DEFAULT);
	_name = name;
	_color = rColor(1);
	println(getColor(_name, _color));
	return ;
}

void	Zombie::announce(void)
{
	std::string tab = ": \t";
	
	if (this->_name.length() < 6)
		tab += "\t";
	println(getColor(_name, _color) + tab + setColor("BraiiiiiiinnnzzzZ...", BRED));
	return ;
}