#include <ClapTrap.hpp>

void ClapTrap::setName(std::string const& name){_name.str = name + toString(getObjects());}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	if (amount >= _hitPoints)
		_attackDamage = _hitPoints - 1;
	else
	_attackDamage = amount;
	setRecoveryPoints();
}

void ClapTrap::setRecoveryPoints(void)
{
	_recoveryPoints = _hitPoints - _attackDamage;
}

bool	ClapTrap::check_KO_Status(void)
{
	if (_energyPoints > 0 && _hitPoints > 0)
		return (false);
	if (_hitPoints == 0)
		std::cout << setColor(typeid(*this).name(), FGRAY, 0) << " " <<
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
	std::cout << setColor(typeid(*this).name(), FGRAY, 0) << " " <<
	*this << " " << setColor("attacks", BRED, 0) << " " << target <<
	", causing " << _attackDamage << " points of damage!";
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
	std::cout << setColor(typeid(*this).name(), FGRAY, 0) << " " <<
	*this << " took " << amount << " points of damage!\n";
	if (_hitPoints == 0)
	{
		std::cout << setColor("FATALITY!: ", FLRED, 0);
		(void)check_KO_Status();
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << setColor(typeid(*this).name(), FGRAY, 0) << " " <<
	*this << " " << setColor("recovers", BGREEN, 0)
	<< " " << amount << " hit points!\n";
	_energyPoints--;
	if ((_hitPoints + amount) > this->getMaxPoints())
		_hitPoints = this->getMaxPoints();
	else
		_hitPoints += amount;
}

unsigned int ClapTrap::getHitPoints(void) const{return (_hitPoints);}

unsigned int ClapTrap::getEnergyPoints(void) const{return (_energyPoints);}

unsigned int ClapTrap::getAttackDamage(void) const{return (_attackDamage);}

unsigned int ClapTrap::getRecoveryPoints(void) const{return (_recoveryPoints);}

unsigned int ClapTrap::getMaxPoints(void){return (_MAX_HIT_POINTS);}

int ClapTrap::getObjects(void){return (_objectColor - FGRAY);};

void ClapTrap::printStatus(void)
{
	std::cout << "[" + setColor(typeid(*this).name(), FGRAY, 0) << " " << *this
	<< setColor(" HP:" + toString(getHitPoints()), FLGREEN, 0) << ", "
	<< setColor("EP:" + toString(getEnergyPoints()), FLYELLOW, 0) << ", "
	<< setColor("AD:" + toString(getAttackDamage()), FLMAGENTA, 0) << ", "
	<< setColor("RP:" + toString(getRecoveryPoints()), FLCYAN, 0) << "]\n";
}

// std::string ClapTrap::getName(void){return (_name.color + _name.str + C_DEFAULT);}
std::string ClapTrap::getName(void){return (_name.getName());}

std::ostream& operator << (std::ostream & os, ClapTrap& rhs)
{
	os << rhs.getName();
	return (os);
}
