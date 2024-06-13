#include <ClapTrap.hpp>

int ClapTrap::_color = FGRAY;
/**
 * @brief Concatenates a message with a color and returns the result.
 * 
 * @param msg The message to be concatenated.
 * @param color The color to be added to the message.
 * @return The concatenated string with the color.
 */
static std::string	setName(int const& color)
{
	if (DEBUG == 0)
		return (setColor("", color, 0));
	else
		return (setRandomColor(1));
}

ClapTrap::ClapTrap(std::string const& name):
_hitPoints(10),
_energyPoints(10),
_attackDamage(0)
{
	_name.str = name;
	_name.color = setName(++_color);
	printnl(getColor(_name) + " " + setColor(" was Created", FGRAY, 0));
};

ClapTrap::~ClapTrap(void)
{
	printnl(getColor(_name) + " " + setColor(" was Destroyed", FGRAY, 0));
}

