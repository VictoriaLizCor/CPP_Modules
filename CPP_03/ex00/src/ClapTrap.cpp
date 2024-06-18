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
_hitPoints(_MAX_POINTS),
_energyPoints(_MAX_POINTS),
_attackDamage(0),
_recoveryPoints(0)
{
	_name.str = name;
	_name.color = setName(++_color);
	coutnl(std::cout << getName() + " " + setColor(" was Created", FGRAY, 0));
};

ClapTrap::ClapTrap(std::string const& name, unsigned int attackDamage):
_hitPoints(_MAX_POINTS),
_energyPoints(_MAX_POINTS),
_recoveryPoints(0)
{
	_name.str = name;
	_name.color = setName(++_color);
	setAD(attackDamage);
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
	setRP();
}

void ClapTrap::setRP(void)
{
	_recoveryPoints = abs(static_cast<int>(_MAX_POINTS) - static_cast<int>(_attackDamage));
}

void ClapTrap::executaAttack(ClapTrap& o1, ClapTrap& o2, int amount)
{
	o1.attack(o2.getName());
	if (o1.getHP() && o1.getEP())
		o2.takeDamage(amount);
}

void ClapTrap::attack(std::string const& target)
{
	if (!_energyPoints)
	{
		std::cout << *this << " has no more EP left\n";
		return ;
	}
	std::cout << "ClapTrap " << *this << " " << setColor("attacks", BRED, 0)
	<< " " << target << ", causing " << _attackDamage << " points of damage!";
	_energyPoints--;
	coutnl(std::cout);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << *this << " took "
	<< amount << " points of damage!\n";
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!_energyPoints)
	{
		std::cout << *this << " has no more EP left\n";
		return ;
	}
	std::cout << "ClapTrap " << *this << " " << setColor("recovers", BGREEN, 0)
	<< " " << amount << " hit points!\n";
	_energyPoints--;
	if ((_hitPoints + amount) > _MAX_POINTS)
		_hitPoints = _MAX_POINTS;
	else
		_hitPoints += amount;
}

int ClapTrap::getHP(void) const {return (static_cast<int>(_hitPoints));}

int ClapTrap::getEP(void) const {return (static_cast<int>(_energyPoints));}

int ClapTrap::getAD(void) const {return (static_cast<int>(_attackDamage));}

int ClapTrap::getRP(void) const {return (static_cast<int>(_recoveryPoints));}

int ClapTrap::getMP(void){return (static_cast<int>(_MAX_POINTS));}


void ClapTrap::status(void)
{
	std::cout << "[" << *this << "->("
	<< setColor("HP: " + toString(getHP()), FBLUE, 0) << ", "
	<< setColor("EP: " + toString(getEP()), FCYAN, 0) << ", "
	<< setColor("AD: " + toString(getAD()), FMAGENTA, 0) << ", "
	<< setColor("RP: " + toString(getRP()), FGRAY, 0) << ")]";
}

std::string ClapTrap::getName(void){return (_name.getName());}

std::ostream& operator << (std::ostream & os, ClapTrap& rhs)
{
	os << rhs.getName();
	return (os);
}


/**
 * 	// if (_attackDamage == 1)
	// 	_recoveryPoints = _MAX_POINTS - 1;
	// else if (_attackDamage == _MAX_POINTS - 1)
	// 	_recoveryPoints = 1;
	// else
	// {
	// 	double ratio = static_cast<double>(_attackDamage) / _MAX_POINTS - 1;
	// 	unsigned int tmp = static_cast<unsigned int>((1 - ratio) * (_MAX_POINTS - 1));

	// 	_recoveryPoints = tmp;
	// 	if (tmp >= _MAX_POINTS / 2)
	// 		_recoveryPoints = _MAX_POINTS / 2;
	// }
 * 
*/