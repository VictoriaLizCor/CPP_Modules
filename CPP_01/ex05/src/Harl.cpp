/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:32:02 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/21 16:19:59 by lilizarr         ###   ########.fr       */
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
	std::string debug =	"DEBUG mode ON. Now you can see all the "
						"flow of the program and state of the variables.";
	std::cout << debug << std::endl;
}

/**
 * @brief Prints an info message.
 */
void	Harl::_info( void )
{
	std::string info =	"The Harl class provides functionality for "
						"DEBUG, INFO, WARNING, ERROR and other things.";
	std::cout << info << std::endl;
}

/**
 * @brief Prints an warning message.
 */
void	Harl::_warning( void )
{
	std::string warning =	"There's a potential problem here."
							"The programm will continue to run, but you should "
							"probably run DEBUG mode to see what's going on.";
	std::cout << warning << std::endl;
}

/**
 * @brief Prints an error message.
 */
void	Harl::_error( void )
{
	std:: string error =	"Something went wrong."
							"The program will now terminate.";
	std::cout << error << std::endl;
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
	strColor << fmt << color << "m" << msg << "\033[0m";
	return (strColor.str());
}


/**
 * @brief This function handles complaints based on the provided level.
 * 
 * @param level The level of complaint. It can be "DEBUG", "INFO", 
 * "WARNING", or "ERROR".
 */
void	Harl::complain(std::string level)
{
	std::string	types[N_TYPE] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int color[N_TYPE] = {FGREEN, FBLUE, FYELLOW, FRED};
	int type = 0;

	for (; type < N_TYPE && types[type] != level; ++type);

	if (type < 0 || type < N_TYPE)
	{
		std:: cout << setColor("[" + types[type] + "]", color[type]) <<std::endl;
		(this->*_ptr[type])();
	}
	else
	{
		std:: cout << setColor("[UNKNOWN]", FDEFAULT) <<std::endl;
		std::cout << "Something unexpected happened, " <<
		"the program will have an unexpected behaviour" << std::endl;
	}

}

/*
 *In C++, member function pointers need to be called on an instance of a class,
 *and they have a different type from non-member function pointers. You need to
 *declare `ptr` as an array of member function pointers.
*/