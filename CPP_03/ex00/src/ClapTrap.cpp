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

/**
 * @brief Construct a new Clap Trap object
 * 
 * @param name The name of the Clap Trap
 * 	_name{name, setName(++_color)}; // not allowed in std98++
 */
ClapTrap::ClapTrap(std::string const& name):
_hitPoints(10),
_energyPoints(10),
_attackDamage(0)
{
	_name.str = name;
	_name.color = setName(++_color);
	coutnl(std::cout << getName() + " " + setColor(" was Created", FGRAY, 0));
};

ClapTrap::ClapTrap(std::string const& name, int attackDamage):
_hitPoints(10),
_energyPoints(10),
_attackDamage(attackDamage)
{
	_name.str = name;
	_name.color = setName(++_color);
	coutnl(std::cout << *this << + " " + setColor(" was Created", FGRAY, 0));
};

/**
 * @brief Construct a new Clap Trap object
 * 
 * @param name The name of the Clap Trap
 */
ClapTrap::~ClapTrap(void)
{
	coutnl(std::cout << *this << " " + setColor(" was Destroyed", FGRAY, 0));
}

void ClapTrap::setAD(unsigned int amount)
{
	_attackDamage = amount;
}

void ClapTrap::action(ClapTrap& o1, ClapTrap& o2, int amount)
{
	o1.attack(o2.getName());
	o2.takeDamage(amount);
}

void ClapTrap::attack(const std::string& target)
{
	_energyPoints--;
	std::cout << "ClapTrap " << *this << " attacks " << target
	<< ", causing " << _attackDamage << " points of damage!";
	coutnl(std::cout);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	std::cout << "ClapTrap " << *this << " took "
	<< amount << " points of damage!";
	// status();
}

void ClapTrap::beRepaired(unsigned int amount)
{
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << *this << " " << "recovered "
	<< amount << " hit points!";
	coutnl(std::cout);
}

int ClapTrap::getHP(void) const {return (static_cast<int>(_hitPoints));}

int ClapTrap::getEP(void) const {return (static_cast<int>(_energyPoints));}

int ClapTrap::getAD(void) const {return (static_cast<int>(_attackDamage));}

int ClapTrap::getMP(void) const {return (static_cast<int>(_MAX_POINTS));}

// static std::string coloredStatus(std::string strType, unsigned int type, int color)
// {
// 	std::ostringstream ss;
// 	ss << strType << type;
// 	return (setColor(ss.str(), color, 0));
// }

void ClapTrap::status(void)
{
	// std::cout << "\t||" << *this << "->("
	// std::cout << "\t["
	// std::cout << setColor("HP: " + toString(static_cast<int>(_hitPoints)), FGREEN, 0) 
	// << ", " << std::endl;
	// << coloredStatus("HP: ", _hitPoints, FGREEN) << ", "
	// << coloredStatus("AD: ", _attackDamage, FRED) << ", "
	// << coloredStatus("EP: ", _energyPoints, FBLUE) << ")||\n";
}

std::string ClapTrap::getName(void)
{
	return (_name.getName());
}

std::ostream& operator << (std::ostream & os, ClapTrap& rhs)
{
	os << rhs.getName();
	return (os);
}
