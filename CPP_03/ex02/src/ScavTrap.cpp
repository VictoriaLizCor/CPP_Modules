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
ScavTrap&::ScavTrap::operator=(ClapTrap const& rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
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
ScavTrap::ScavTrap(ClapTrap const& rhs): ClapTrap(rhs)
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
 * @brief Executes an attack on a target.
 * 
 * This function prints a message to the console indicating that the ScavTrap
 * instance has attacked a target, specifying the target and the amount of
 * damage dealt. It also decrements the energy points of the ScavTrap instance
 * by one.
 * 
 * @param target The name of the target being attacked.
 */
void ScavTrap::attack(std::string const& target)
{
	std::cout << setColor(className(typeid(*this).name()), FLWHITE, 0) << " " <<
	*this << " " << setColor("attacks", BRED, 0) << " ⚔️  " << target <<
	", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

/**
 * @brief Retrieves the maximum hit points for ScavTrap.
 * 
 * This function returns the maximum hit points value, defined by the
 * _MAX_HIT_POINTS constant, for a ScavTrap instance. It's a simple getter
 * method used to access the private _MAX_HIT_POINTS attribute from outside
 * the class.
 * 
 * @return The maximum hit points of ScavTrap.
 */
unsigned int ScavTrap::getMaxPoints(void){return (_MAX_HIT_POINTS);}

/**
 * @brief Activates Gate Keeper Mode for the ScavTrap.
 * 
 * This function enables the Gate Keeper Mode for a ScavTrap instance, 
 * indicating this mode activation through a message printed to the console. 
 * The message includes the name of the ScavTrap instance, dynamically 
 * obtained using RTTI (Run-Time Type Information) to ensure accurate 
 * identification of the object's class.
 */
void ScavTrap::guardGate(void)
{
	std::cout << setColor(className(typeid(*this).name()), FLWHITE, 0) << " "
	<< *this << " is now in Gate Keeper Mode\n";
}