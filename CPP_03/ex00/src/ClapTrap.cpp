#include <ClapTrap.hpp>

int ClapTrap::_ObjectColor = FGRAY;
/**
 * @brief Concatenates a message with a color and returns the result.
 * 
 * @param msg The message to be concatenated.
 * @param color The color to be added to the message.
 * @return The concatenated string with the color.
 */
static std::string setName(int const& color)
{
	if (DEBUG == 0)
		return (setColor("", color, 0));
	else
		return (setRandomColor(1));
}

void ClapTrap::initialize(std::string const& name)
{
	_hitPoints = _MAX_POINTS;
	_energyPoints = _MAX_POINTS;
	_recoveryPoints = 0;
	_attackDamage = 0;
	_name.str = name;
	_name.color = setName(++_ObjectColor);
}
 
ClapTrap::ClapTrap(void)
{
	initialize("DefaultName");
	coutnl(std::cout << getName() + setColor(" was Created", FGRAY, 0));
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
	coutnl(std::cout << getName() + setColor(" was Created", FGRAY, 0));
};

ClapTrap::ClapTrap(std::string const& name, unsigned int attackDamage)
{
	initialize(name);
	setAttackDamage(attackDamage);
	coutnl(std::cout << *this << setColor(" was Created", FGRAY, 0));
};

/**
 * @brief Construct a new Clap Trap object
 * 
 * @param name The name of the Clap Trap
 */
ClapTrap::~ClapTrap(void)
{
	coutnl(std::cout << *this << setColor(" was Destroyed", FGRAY, 0));
}

ClapTrap&::ClapTrap::operator=(ClapTrap const& rhs)
{
	if (this != &rhs)
	{
		_name.str = rhs._name.str;
		_name.color = setName(++_ObjectColor);
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

ClapTrap::ClapTrap(ClapTrap const& rhs){*this = rhs;}