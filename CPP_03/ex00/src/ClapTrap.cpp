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

void ClapTrap::initialize(std::string const& name)
{
	_hitPoints = _MAX_POINTS;
	_energyPoints = _MAX_POINTS;
	_recoveryPoints = 0;
	_name.str = name;
	_name.color = setName(++_color);
}

/**
 * @brief Construct a new Clap Trap object
 * 
 * @param name The name of the Clap Trap
 * 	_name{name, setName(++_color)}; // not allowed in std98++
 */
ClapTrap::ClapTrap(std::string const& name)
{
	initialize(name);
	coutnl(std::cout << getName() + " " + setColor(" was Created", FGRAY, 0));
};

ClapTrap::ClapTrap(std::string const& name, unsigned int attackDamage)
{
	initialize(name);
	setAttackDamage(attackDamage);
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

void ClapTrap::setAttackDamage(unsigned int amount)
{
	_attackDamage = amount;
	if (_attackDamage == _MAX_POINTS)
		_attackDamage--;
	setRecoveryPoints();
}

void ClapTrap::setRecoveryPoints(void)
{
	_recoveryPoints = abs(static_cast<int>(_MAX_POINTS) - static_cast<int>(_attackDamage));
}

bool	ClapTrap::check_KO_Status(void)
{
	if (_energyPoints && _hitPoints)
		return (0);
	if (!_hitPoints)
		std::cout << setColor("FATALITY!: ", FLRED, 0) << 
		*this << setColor(" has no more HP left\n", FWHITE, 0);
	else if (!_energyPoints)
		std::cout << *this << setColor(" has no more EP left\n", FWHITE, 0);
	return (1);
}

void ClapTrap::executaAttack(ClapTrap& o2, int amount)
{
	if (!getHitPoints() || check_KO_Status())
		return ;
	attack(o2.getName());
	o2.takeDamage(amount);
}

void ClapTrap::attack(std::string const& target)
{
	if (check_KO_Status())
		return ;
	std::cout << "ClapTrap " << *this << " " << setColor("attacks", BRED, 0)
	<< " " << target << ", causing " << _attackDamage << " points of damage!";
	_energyPoints--;
	coutnl(std::cout);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _hitPoints)
	{
		amount = _hitPoints;
		_hitPoints = 0;
	}
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << *this << " took "
	<< amount << " points of damage!\n";
	if (_hitPoints == 0)
		check_KO_Status();
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (check_KO_Status())
		return ;
	std::cout << "ClapTrap " << *this << " " << setColor("recovers", BGREEN, 0)
	<< " " << amount << " hit points!\n";
	_energyPoints--;
	if ((_hitPoints + amount) > _MAX_POINTS)
		_hitPoints = _MAX_POINTS;
	else
		_hitPoints += amount;
}

int ClapTrap::getHitPoints(void) const {return (static_cast<int>(_hitPoints));}

int ClapTrap::getEnergyPoints(void) const {return (static_cast<int>(_energyPoints));}

int ClapTrap::getAttackDamage(void) const {return (static_cast<int>(_attackDamage));}

int ClapTrap::getRecoveryPoints(void) const {return (static_cast<int>(_recoveryPoints));}

int ClapTrap::getMaxPoints(void){return (static_cast<int>(_MAX_POINTS));}


void ClapTrap::printStatus(void)
{
	std::cout << "[" << *this
	<< setColor(" HP:" + toString(getHitPoints()), FBLUE, 0) << ", "
	<< setColor("EP:" + toString(getEnergyPoints()), FCYAN, 0) << ", "
	<< setColor("AD:" + toString(getAttackDamage()), FMAGENTA, 0) << ", "
	<< setColor("RP:" + toString(getRecoveryPoints()), FGRAY, 0) << "]\n";
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