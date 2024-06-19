#include <ClapTrap.hpp>

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
	if (_energyPoints > 0 && _hitPoints > 0)
		return (false);
	if (_hitPoints == 0)
		std::cout << setColor("FATALITY!: ", FLRED, 0) << 
		*this << setColor(" has no more HP left\n", FWHITE, 0);
	else if (_energyPoints == 0)
		std::cout << *this << setColor(" has no more EP left\n", FWHITE, 0);
	return (true);
}

void ClapTrap::executaAttack(ClapTrap& o2, int amount)
{
	if (check_KO_Status() == 1)
		return ;
	attack(o2.getName());
	o2.takeDamage(amount);
}

void ClapTrap::attack(std::string const& target)
{
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
		(void)check_KO_Status();
}

void ClapTrap::beRepaired(unsigned int amount)
{
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

int ClapTrap::getObjects(void){return (_color - FGRAY);};

void ClapTrap::printStatus(void)
{
	std::cout << "[" << *this
	<< setColor(" HP:" + toString(getHitPoints()), FBLUE, 0) << ", "
	<< setColor("EP:" + toString(getEnergyPoints()), FCYAN, 0) << ", "
	<< setColor("AD:" + toString(getAttackDamage()), FMAGENTA, 0) << ", "
	<< setColor("RP:" + toString(getRecoveryPoints()), FGRAY, 0) << "]\n";
}

std::string ClapTrap::getName(void){return (_name.color + _name.str + C_DEFAULT);}

std::ostream& operator << (std::ostream & os, ClapTrap& rhs)
{
	os << rhs.getName();
	return (os);
}
