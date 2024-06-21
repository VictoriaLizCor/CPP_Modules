#include "ScavTrap.hpp"

unsigned int ScavTrap::_MAX_HIT_POINTS = 100;

ScavTrap::ScavTrap(void):
ClapTrap("DefaultScavTrap", 100, 50 , 20)
{
	guardGate();
};

ScavTrap::ScavTrap(std::string const& name):
ClapTrap(name, 100, 50 , 20)
{
	guardGate();
};

ScavTrap::ScavTrap(std::string const& name, unsigned int attackDamage):
ClapTrap(name, 100 , 50 , attackDamage)
{
	guardGate();
}

ScavTrap::ScavTrap(
std::string const& name,
unsigned int hitPoints,
unsigned int energyPoints,
unsigned int attackDamage):
ClapTrap(name, hitPoints , energyPoints , attackDamage)
{
	std::cout << setColor(typeid(*this).name(), FLWHITE, 0)<< " " <<
	*this << setColor(" was Created", FGRAY, 0) << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << setColor(typeid(*this).name(), FLWHITE, 0)<< " " <<
	*this << setColor(" was Destroyed", FGRAY, 0) << std::endl;
}

void ScavTrap::attack(std::string const& target)
{
	std::cout << setColor(typeid(*this).name(), FLWHITE, 0) << " " <<
	*this << " " << setColor("attacks", BRED, 0) << " " << target <<
	", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

unsigned int ScavTrap::getMaxPoints(void){return (_MAX_HIT_POINTS);}

void ScavTrap::guardGate(void)
{
	std::cout << setColor(typeid(*this).name(), FLWHITE, 0) << " "
	<< *this << " is now in Gate Keeper Mode\n";
}