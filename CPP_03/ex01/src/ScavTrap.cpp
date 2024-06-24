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
 * @brief Assignment operator for ScavTrap.
 * 
 * Assigns the values from one ScavTrap object to another. If the object being
 * assigned is not the same as the current object, it calls the base class
 * ClapTrap's assignment operator to copy the base class attributes.
 * 
 * @param rhs The ScavTrap object to assign from.
 * @return Returns a reference to the current object.
 */
ScavTrap&::ScavTrap::operator=(ScavTrap const& rhs)
{
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
	}
	std::cout << setColor(className(typeid(*this).name()), FLWHITE, 0) << " " 
	<< *this << setColor(" Copy was Created ", FGRAY, 0) << std::endl ;
	return *this;
}
/**
 * @brief Copy constructor for ScavTrap.
 * 
 * This constructor creates a new ScavTrap as a copy of an existing one by
 * invoking the copy constructor of the base class, ClapTrap.
 * 
 * @param rhs The ScavTrap instance to copy.
 */
ScavTrap::ScavTrap(ScavTrap const& rhs): ClapTrap(rhs)
{
	std::cout << setColor(className(typeid(*this).name()), FLWHITE, 0) << " " 
	<< *this << setColor(" Copy was Created ", FGRAY, 0) << std::endl ;
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