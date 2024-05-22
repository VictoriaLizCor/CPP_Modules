/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:32:02 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/22 10:52:00 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	_ptr[DEBUG] = &Harl::_debug;
	_ptr[INFO] = &Harl::_info;
	_ptr[WARNING] = &Harl::_warning;
	_ptr[ERROR] = &Harl::_error;
}

Harl::~Harl()
{
}

/**
 * @brief Prints a debug message.
 */
void	Harl::_debug( void )
{
	std::cout << "DEBUG mode ON. Now you can see all the "
				 "flow of the program and state of the variables."
	<< std::endl;
}

/**
 * @brief Prints an info message.
 */
void	Harl::_info( void )
{
	std::cout << "The Harl class provides functionality for "
				"DEBUG, INFO, WARNING, ERROR and other things."
	<< std::endl;
}

/**
 * @brief Prints an warning message.
 */
void	Harl::_warning( void )
{
	std::cout <<"There's a potential problem here."
				"The programm will continue to run, but you should "
				"probably run DEBUG mode to see what's going on."
	<< std::endl;
}

/**
 * @brief Prints an error message.
 */
void	Harl::_error( void )
{
	std::cout << "Something went wrong."
				"The program will now terminate."
	<< std::endl;
}

/**
 * @brief This function handles complaints based on the provided level.
 * 
 * @param level The level of complaint. It can be "DEBUG", "INFO", 
 * "WARNING", or "ERROR".
 */
static std::string setColor(std::string msg, int color)
{
	std::stringstream strColor;
	std::string	fmt;

	fmt = "\033[1;";
	strColor << fmt << color << "m";
	if (msg.empty())
		return (strColor.str());
	strColor << msg << "\033[0m";
	return (strColor.str());
}


std::string	Harl::checkType(int type)
{
	switch (type)
	{
		case DEBUG:
			return ("DEBUG");
		case INFO:
			return ("INFO");
		case WARNING:
			return ("WARNING");
		case ERROR:
			return ("ERROR");
		default:
			return ("UNKNOWN");
	}
}

/**
 * @brief This function handles complaints based on the provided level.
 * 
 * @param level The level of complaint. It can be "DEBUG", "INFO", 
 * "WARNING", or "ERROR".
 */
void	Harl::complain(std::string level)
{
	int color[N_TYPE] = {FGREEN, FBLUE, FYELLOW, FRED};
	int type = 0;

	for (; type < N_TYPE && checkType(type) != level; ++type);

	if (type == N_TYPE)
	{
		std:: cout << setColor("[" + checkType(type) + "]\n", FWHITE);
		std::cout << setColor("", FDEFAULT)
		<< "Something unexpected happened the program"
		<< " will have an unexpected behaviour"
		<< setColor(" \n", FDEFAULT) << std::endl;
		return ;
	}
	for (; type < N_TYPE; ++type)
	{
		std:: cout << setColor("[" + checkType(type) + "]", color[type]) << std::endl;
		std::cout << setColor("", FDEFAULT);
		(this->*_ptr[type])();
		std::cout << setColor(" \n", FDEFAULT);
	}
}
