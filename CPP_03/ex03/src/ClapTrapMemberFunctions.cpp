#include <ClapTrap.hpp>

/**
 * @brief Sets the name of the ClapTrap.
 * 
 * This method assigns a new name to the ClapTrap instance. If the ClapTrap's
 * name is currently empty, it assigns a new color to the name based on the
 * incremented _objectColor. Then, it sets the ClapTrap's name to the provided
 * name.
 * 
 * @param name The new name to be assigned to the ClapTrap.
 */
void ClapTrap::setName(std::string const& name)
{
	if(this->_name.str.empty())
		this->_name.color = setColorName(++_objectColor);
	this->_name.str = name;
}

/**
 * @brief Sets the attack damage of the ClapTrap object.
 * 
 * @param amount The new attack damage for the ClapTrap object.
 */
void ClapTrap::setAttackDamage(unsigned int amount)
{
	if (amount >= _hitPoints)
		_attackDamage = _hitPoints - 1;
	else
	_attackDamage = amount;
	this->setRecoveryPoints();
}

/**X
 * @brief Sets the recovery points of the ClapTrap object.
 * 
 * Recovery points are calculated as the difference between hit points and attack damage.
 */
void ClapTrap::setRecoveryPoints(void)
{
	this->_recoveryPoints = this->getMaxPoints() - _attackDamage;
}

/**
 * @brief Checks if the ClapTrap object is knocked out (KO).
 * 
 * A ClapTrap object is considered KO if it has no hit points or energy points left.
 * 
 * @return bool Returns true if the ClapTrap is KO, false otherwise.
 */
bool	ClapTrap::check_KO_Status(void)
{
	if (_energyPoints > 0 && _hitPoints > 0)
		return (false);
	if (_hitPoints == 0)
		std::cout << setColor(className(typeid(*this).name()), FGRAY, 0) << " " <<
		*this << setColor(" has no more HP left\n", FWHITE, 0);
	else if (_energyPoints == 0)
		std::cout << *this << setColor(" has no more EP left\n", FWHITE, 0);
	return (true);
}

/**
 * @brief Checks if the ClapTrap object is knocked out (KO).
 * 
 * A ClapTrap object is considered KO if it has no hit points or energy points left.
 * 
 * @return bool Returns true if the ClapTrap is KO, false otherwise.
 */
void ClapTrap::executaAttack(ClapTrap& o2, unsigned int amount)
{
	if (check_KO_Status() == 1)
		return ;
	attack(o2.getName());
	o2.takeDamage(amount);
}

/**
 * @brief Executes an attack on a target.
 * 
 * @param target The name of the target to attack.
 * 
 * Outputs a message indicating the attack and the damage caused. Decreases the 
 * energy points of the ClapTrap object by 1 after the attack.
 */
void ClapTrap::attack(std::string const& target)
{
	std::cout << setColor(className(typeid(*this).name()), _CLASS_COLOR, 0) << " " <<
	*this << " " << setColor("attacks", BRED, 0) << " " << target <<
	", causing " << _attackDamage << " points of damage!";
	_energyPoints--;
	coutnl(std::cout);
}

/**
 * @brief Inflicts damage on the ClapTrap object.
 * 
 * @param amount The amount of damage to inflict.
 * 
 * If the amount of damage is greater than the ClapTrap's hit points, the hit points
 * are set to 0. Otherwise, the hit points are reduced by the amount of damage.
 * Outputs a message indicating the damage taken. If the hit points reach 0, a 
 * "FATALITY!" message is output and the KO status is checked.
 */
void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _hitPoints)
	{
		amount = _hitPoints;
		_hitPoints = 0;
	}
	else
		_hitPoints -= amount;
	std::cout << setColor(className(typeid(*this).name()), FGRAY, 0) << " " <<
	*this << " took " << amount << " points of damage!\n";
	if (_hitPoints == 0)
	{
		std::cout << setColor("FATALITY!: ", FLRED, 0);
		(void)check_KO_Status();
	}
}

/**
 * @brief Repairs the ClapTrap object, recovering hit points.
 * 
 * @param amount The amount of hit points to recover.
 * 
 * Outputs a message indicating the recovery. Decreases the energy points of the 
 * ClapTrap object by 1 after the recovery. If the recovery amount would cause the 
 * hit points to exceed the maximum, the hit points are set to the maximum. 
 * Otherwise, the hit points are increased by the recovery amount.
 */
void ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int tmp;

	tmp = _hitPoints;
	if ((_hitPoints + amount) > this->getMaxPoints())
		_hitPoints = this->getMaxPoints();
	else
		_hitPoints += amount;
	tmp = _hitPoints - tmp;
	std::cout << setColor(className(typeid(*this).name()), FGRAY, 0) << " " <<
	*this << " " << setColor("recovers", BGREEN, 0)
	<< " " << tmp << " hit points!\n";
	_energyPoints--;
}

/**
 * @brief Prints the status of the ClapTrap object.
 * 
 * Getters for attributes
 */
unsigned int ClapTrap::getHitPoints(void) const{return (_hitPoints);}

unsigned int ClapTrap::getEnergyPoints(void) const{return (_energyPoints);}

unsigned int ClapTrap::getAttackDamage(void) const{return (_attackDamage);}

unsigned int ClapTrap::getRecoveryPoints(void)
{
	unsigned int tmp;
	tmp = this->_recoveryPoints;
	return (tmp);
}

unsigned int ClapTrap::getMaxPoints(void)
{
	unsigned int tmp;
	tmp = this->_MAX_HIT_POINTS;
	return (tmp);
}

unsigned int ClapTrap::getObjectColor(void){return (_objectColor);}

/**
 * @brief Retrieves the class color of the ClapTrap.
 * 
 * This function returns the class color of the ClapTrap instance, which is
 * stored in the private member variable _CLASS_COLOR.
 * 
 * @return unsigned int The class color of the ClapTrap.
 */
unsigned int ClapTrap::getClassColor(void)
{
	unsigned int tmp;
	tmp = this->_CLASS_COLOR;
	return (tmp);
}
/**
 * @brief Gets the number of ClapTrap objects.
 * 
 * @return int The number of ClapTrap objects, calculated as the difference 
 * between the current object color and the base color (FGRAY).
 */
int ClapTrap::getObjects(void){return (static_cast<int>(_objectColor - FGRAY));}

/**
 * @brief Prints the status of the ClapTrap object.
 * 
 * Outputs the name, hit points, energy points, attack damage, and recovery points
 * of the ClapTrap object. Each attribute is color-coded for easy reading.
 */
void ClapTrap::printStatus(void)
{
	std::cout << "[" + setColor(className(className(typeid(*this).name())), this->getClassColor(), 0)
	<< " " << this->getName()
	<< setColor(" HP:" + toString(static_cast<int>(getHitPoints())), FLGREEN, 0) << ", "
	<< setColor("EP:" + toString(static_cast<int>(getEnergyPoints())), FLYELLOW, 0) << ", "
	<< setColor("AD:" + toString(static_cast<int>(getAttackDamage())), FLMAGENTA, 0) << ", "
	<< setColor("RP:" + toString(static_cast<int>(this->getRecoveryPoints())), FLCYAN, 0) << "] "
	<< setColor(" MaxPoints: " + toString(static_cast<int>(this->getMaxPoints())), FGRAY, 0) << "\n";
}
// 
// std::string ClapTrap::getName(void){return (_name.color + _name.str + C_DEFAULT);}
/**
 * @brief Gets the name of the ClapTrap object.
 * 
 * @return std::string The name of the ClapTrap object.
 */
std::string ClapTrap::getName(void){return (this->_name.getName());}

/**
 * @brief Overloads the << operator for the ClapTrap class.
 * 
 * @param os The output stream to write to.
 * @param rhs The ClapTrap object to write to the output stream.
 * 
 * @return std::ostream& The output stream after writing the ClapTrap object.
 */
std::ostream& operator << (std::ostream & os, ClapTrap& rhs)
{
	os << rhs.getName();
	return (os);
}
