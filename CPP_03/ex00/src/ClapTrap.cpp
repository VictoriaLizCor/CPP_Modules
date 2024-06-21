#include "ClapTrap.hpp"
#include <typeinfo>

int ClapTrap::_objectColor = FGRAY;
unsigned int ClapTrap::_MAX_HIT_POINTS = 10;
unsigned int ClapTrap::_MAX_ATTACK_POINTS = _MAX_HIT_POINTS;
/**
 * @brief Concatenates a message with a color and returns the result.
 * 
 * @param msg The message to be concatenated.
 * @param color The color to be added to the message.
 * @return The concatenated string with the color.
 */
static std::string setColorName(int const& color)
{
	if (DEBUG == 0)
		return (setColor("", color, 0));
	else
		return (setRandomColor(1));
}

void ClapTrap::initialize(std::string const& name)
{
	if(_name.str.empty())
		_name.color = setColorName(++_objectColor);
	setName(name);
	_hitPoints = 10;
	_energyPoints = 10;
	_recoveryPoints = 0;
	_attackDamage = 0;
}
 
ClapTrap::ClapTrap(void)
{
	initialize("DefaultClapTrap");
	std::cout << setColor(typeid(*this).name(), FGRAY, 0) << " " <<
	*this << setColor(" was Created", FGRAY, 0) << std::endl ;
};

/**
 * @brief Construct a new Clap Trap object
 * 
 * @param name The name of the Clap Trap
 * 	_name{name, setName(++_color)}; // not allowed in std98++
 */
ClapTrap::ClapTrap(std::string const& name)
{
	initialize(name);
	std::cout << setColor(typeid(*this).name(), FGRAY, 0) << " " <<
	*this << setColor(" was Created", FGRAY, 0) << std::endl ;
};

ClapTrap::ClapTrap(std::string const& name, unsigned int attackDamage)
{
	initialize(name);
	setAttackDamage(attackDamage);
	std::cout << setColor(typeid(*this).name(), FGRAY, 0) << " " <<
	*this << setColor(" was Created", FGRAY, 0) << std::endl ;
};

/**
 * @brief Construct a new Clap Trap object
 * 
 * @param name The name of the Clap Trap
 */
ClapTrap::~ClapTrap(void)
{
	std::cout << setColor(typeid(*this).name(), FGRAY, 0)<< " " <<
	*this << setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}

ClapTrap&::ClapTrap::operator=(ClapTrap const& rhs)
{
	if (this != &rhs)
	{
		_name.str = rhs._name.str;
		_name.color = setColorName(++_objectColor);
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

ClapTrap::ClapTrap(ClapTrap const& rhs){*this = rhs;}