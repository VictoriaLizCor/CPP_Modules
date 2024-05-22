/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:21:05 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/10 15:39:06 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Get the name of the Zombie object.
 * 
 * @param z The Zombie object.
 * @return std::string The name of the Zombie object.
 */
std::string Zombie::getName(const Zombie &z){
	return (z._name);
}

/**
 * @brief Sets the color of a message using ANSI escape codes.
 * 
 * @param msg The message to be colored.
 * @param color The color code to be applied.
 * @return The colored message.
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
 * @brief Concatenates a color code, a message, and a default color code.
 *
 * This function takes a message and a color code as input and concatenates them
 * with a default color code. The resulting string is returned.
 *
 * @param msg The message to be colored.
 * @param color The color code to be applied to the message.
 * @return The colored message.
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
 * @brief Default constructor for the Zombie class.
 * 
 * This constructor initializes a Zombie object with default values.
 * The name is set to "Unknown" and the color is set to an empty string.
 * The constructor also prints a message indicating that the Zombie has been created.
 */
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

/**
 * @brief Generates a formatted string representing an RGB color.
 *
 * This function takes three integers representing the red, green, and blue
 * values of an RGB color and returns a formatted string representing that
 * color. The format of the string is determined by the constants C_FMT, FLRGB,
 * and the provided RGB values.
 *
 * @param red The red value of the RGB color.
 * @param green The green value of the RGB color.
 * @param blue The blue value of the RGB color.
 * @return A formatted string representing the RGB color.
 */
static std::string	rColorRGB(int red, int green, int blue)
{
	std::ostringstream ss;

	ss << C_FMT << "1;" << FLRGB << ";2;";
	ss << red << ";" << green << ";" << blue << "m";
	return (ss.str());
}

/**
 * Generates a random integer between the specified minimum and maximum values.
 *
 * @param min The minimum value for the random number (inclusive).
 * @param max The maximum value for the random number (inclusive).
 * @return A random integer between the specified minimum and maximum values. If
 * the minimum or maximum values are out of range, returns 255.
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

/**
 * @brief Generates a string representing a red color in RGB format.
 *
 * This function generates a string that represents a red color in RGB format.
 * The red shade value is incremented by a certain amount each time the function
 * is called. The function uses static variables to keep track of the red shade
 * value and the increment value.
 *
 * @return A string representing a red color in RGB format.
 */
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

/**
 * @brief Constructs a Zombie object with the given name.
 * 
 * @param name The name of the Zombie.
 */
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
/**
 * @brief Destructor for the Zombie class.
 * 
 * This destructor is responsible for destroying a Zombie object.
 * It prints a message indicating the destruction of the Zombie,
 * with different formatting based on the length of the Zombie's name.
 * 
 * @return None.
 */
Zombie::~Zombie()
{
	if (this->_name.length() > 5)
		println(getColor(_name, _color) + ": " + setColor("\tDestroyed", DEFAULT));
	else
		println(getColor(_name, _color) + ": " + setColor("\t\tDestroyed", FDARKGRAY));
	return ;
}


/**
 * @brief Announces the zombie's name and makes a sound.
 * 
 * This function prints the zombie's name followed by the sound "BraiiiiiiinnnzzzZ...".
 * The length of the zombie's name affects the formatting of the output.
 * If the name has more than 5 characters, it will be printed with a tab character.
 * Otherwise, it will be printed with two tab characters.
 */
void	Zombie::announce(void)
{
	if (this->_name.length() > 5)
		println(getColor(_name, _color) + ": \t" + setColor("BraiiiiiiinnnzzzZ...", BRED));
	else
		println(getColor(_name, _color) + ": \t\t" + setColor("BraiiiiiiinnnzzzZ...", BRED));
	return ;
}