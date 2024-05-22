/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:21:05 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/10 14:44:54 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int Zombie::_counter = 0;

/**
 * @brief Sets the color of a message string.
 *
 * This function sets the color of a message string using ANSI escape codes.
 * If the message string is empty, it returns the color code only.
 * If the color is greater than or equal to FDEFAULT, it adds "1;" to the format.
 *
 * @param msg The message string to colorize.
 * @param color The color code to use.
 * @return The colorized message string.
 */
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

/**
 * @brief Concatenates a message with a color and returns the result.
 * 
 * @param msg The message to be concatenated.
 * @param color The color to be added to the message.
 * @return The concatenated string with the color.
 */
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
/**
 * @brief Constructs a Zombie object.
 * 
 * This constructor initializes a Zombie object by setting its name and color.
 * The name is set to "WhiteWalker" followed by a counter value, and the color
 * is set to an empty string with the FRED color code. The constructor also
 * prints a message indicating that the Zombie has been created.
 */
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

/**
 * @brief Generates a formatted string representing an RGB color.
 *
 * This function takes three integer values representing the red, green, and
 * blue components of an RGB color and returns a formatted string representing
 * the color in ANSI escape code format.
 *
 * @param red The red component of the RGB color.
 * @param green The green component of the RGB color.
 * @param blue The blue component of the RGB color.
 * @return A formatted string representing the RGB color in ANSI escape code
 * format.
 */
static std::string	rColorRGB(int red, int green, int blue)
{
	std::ostringstream ss;

	ss << C_FMT << "1;" << FLRGB << ";2;";
	ss << red << ";" << green << ";" << blue << "m";
	return (ss.str());
}


/**
 * Generates a random integer between the given minimum and maximum values.
 *
 * @param min The minimum value for the random number (inclusive).
 * @param max The maximum value for the random number (inclusive).
 * @return A random integer between the minimum and maximum values.
 */
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

/**
 * @brief Constructs a Zombie object with the given name.
 * 
 * @param name The name of the Zombie.
 */
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

/**
 * @brief Generates a string representing a color in ANSI escape code format.
 * 
 * The generated color string is used for formatting text in the terminal. The
 * color is determined by the redShade value, which is incremented by a fixed
 * amount each time the function is called. The color can be made bold by
 * setting the bold parameter to a non-zero value.
 *
 * @param bold A flag indicating whether the color should be bold or not.
 * @return A string representing the color in ANSI escape code format.
 */
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

/**
 * @brief Constructs a Zombie object with the given name.
 * 
 * @param name The name of the Zombie.
 */
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

/**
 * @brief Destructor for the Zombie class.
 * 
 * This destructor is responsible for destroying a Zombie object.
 * It prints a message indicating the destruction of the Zombie,
 * including its name and whether it was destroyed as "Unknown" or not.
 * The message is printed in a colored format.
 * 
 * @return None.
 */
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

/**
 * @brief Sets the name of the Zombie.
 * 
 * This function sets the name of the Zombie object to the specified name.
 * It also prints a message indicating that the Zombie has been renamed.
 * 
 * @param name The new name for the Zombie.
 */
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

/**
 * @brief Announces the zombie's name and emits a sound.
 * 
 * This function prints the zombie's name followed by a sound
 * that represents the zombie's announcement.
 * The sound emitted is "BraiiiiiiinnnzzzZ...".
 */
void	Zombie::announce(void)
{
	std::string tab = ": \t";
	
	if (this->_name.length() < 6)
		tab += "\t";
	println(getColor(_name, _color) + tab + setColor("BraiiiiiiinnnzzzZ...", BRED));
	return ;
}