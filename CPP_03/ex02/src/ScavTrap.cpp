#include "ScavTrap.hpp"

unsigned int ScavTrap::_MAX_HIT_POINTS = 100;

/**
 * @brief Constructs a new ScavTrap object with default values.
 * 
 * Initializes a new ScavTrap object by calling the ClapTrap constructor with
 * default name "DefaultScavTrap" and predefined health, energy, and attack
 * values. It also activates guard mode immediately upon creation.
 */
ScavTrap::ScavTrap(void):
ClapTrap("DefaultScavTrap", 100, 50 , 20)
{
	guardGate();
};

/**
 * @brief Constructs a new ScavTrap object.
 * 
 * Initializes a new ScavTrap object with a custom name by calling the ClapTrap
 * constructor with specified name and predefined health, energy, and attack
 * values. It activates guard mode immediately upon creation.
 * 
 * @param name The name for the ScavTrap object.
 */
ScavTrap::ScavTrap(std::string const& name):
ClapTrap(name, 100, 50 , 20)
{
	guardGate();
};

/**
 * @brief Constructs a new ScavTrap object.
 * 
 * Initializes a new ScavTrap object with a custom name by calling the ClapTrap
 * constructor with specified name and predefined health, energy, and attack
 * values. It activates guard mode immediately upon creation.
 * 
 * @param name The name for the ScavTrap object.
 */
ScavTrap::ScavTrap(std::string const& name, unsigned int attackDamage):
ClapTrap(name, 100 , 50 , attackDamage)
{
	guardGate();
}

/**
 * @brief Constructs a new ScavTrap object.
 * 
 * Initializes a new ScavTrap object with a custom name by calling the ClapTrap
 * constructor with specified name and predefined health, energy, and attack
 * values. It activates guard mode immediately upon creation.
 * 
 * @param name The name for the ScavTrap object.
 */
ScavTrap::ScavTrap(
std::string const& name,
unsigned int hitPoints,
unsigned int energyPoints,
unsigned int attackDamage):
ClapTrap(name, hitPoints , energyPoints , attackDamage)
{
	std::cout << setColor(className(typeid(*this).name()), FLWHITE, 0)<< " " <<
	*this << setColor(" was Created", FGRAY, 0) << std::endl;
}

/**
 * @brief Constructs a new ScavTrap object.
 * 
 * Initializes a new ScavTrap object with a custom name by calling the ClapTrap
 * constructor with specified name and predefined health, energy, and attack
 * values. It activates guard mode immediately upon creation.
 * 
 * @param name The name for the ScavTrap object.
 */
ScavTrap::~ScavTrap()
{
	std::cout << setColor(className(typeid(*this).name()), FLWHITE, 0)<< " " <<
	*this << setColor(" was Destroyed", FGRAY, 0) << std::endl;
}

/**
 * @brief Constructs a new ScavTrap object.
 * 
 * Initializes a new ScavTrap object with a custom name by calling the ClapTrap
 * constructor with specified name and predefined health, energy, and attack
 * values. It activates guard mode immediately upon creation.
 * 
 * @param name The name for the ScavTrap object.
 */
void ScavTrap::attack(std::string const& target)
{
	std::cout << setColor(className(typeid(*this).name()), FLWHITE, 0) << " " <<
	*this << " " << setColor("attacks", BRED, 0) << " " << target <<
	", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

/**
 * @brief Constructs a new ScavTrap object.
 * 
 * Initializes a new ScavTrap object with a custom name by calling the ClapTrap
 * constructor with specified name and predefined health, energy, and attack
 * values. It activates guard mode immediately upon creation.
 * 
 * @param name The name for the ScavTrap object.
 */
unsigned int ScavTrap::getMaxPoints(void){return (_MAX_HIT_POINTS);}

/**
 * @brief Constructs a new ScavTrap object.
 * 
 * Initializes a new ScavTrap object with a custom name by calling the ClapTrap
 * constructor with specified name and predefined health, energy, and attack
 * values. It activates guard mode immediately upon creation.
 * 
 * @param name The name for the ScavTrap object.
 */
void ScavTrap::guardGate(void)
{
	std::cout << setColor(className(typeid(*this).name()), FLWHITE, 0) << " "
	<< *this << " is now in Gate Keeper Mode\n";
}