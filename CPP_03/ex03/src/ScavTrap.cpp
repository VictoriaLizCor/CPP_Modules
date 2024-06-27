#include "ScavTrap.hpp"

unsigned int ScavTrap::_MAX_HIT_POINTS = 110;
unsigned int ScavTrap::_CLASS_COLOR = FGRAY;

/**
 * @brief Sets the recovery points for the ScavTrap.
 * 
 * This method calculates the recovery points by subtracting the attack damage
 * from the maximum points of the ScavTrap and updates the _recoveryPoints
 * member variable with this value.
 */
void ScavTrap::setRecoveryPoints(void)
{
	_recoveryPoints = this->getMaxPoints() - _attackDamage;
}

/**
 * @brief Initializes the ScavTrap instance.
 * 
 * This method sets the initial state of a ScavTrap instance by setting its
 * hit points to the maximum points value, initializing energy points to 100,
 * and setting the attack damage to 30.
 */
void ScavTrap::initialize()
{
	this->_hitPoints = getMaxPoints();
	this->_energyPoints = 50;
	setAttackDamage(20);
}

/**
 * @brief Constructs a new ScavTrap object with default values.
 * 
 * Initializes a new ScavTrap object by calling the ClapTrap constructor with
 * default name "DefaultScavTrap" and predefined health, energy, and attack
 * values. It also activates guard mode immediately upon creation.
 */
ScavTrap::ScavTrap(void):
ClapTrap("DefaultScavTrap")
{
	this->initialize();
	guardGate();
	printStatus();
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
ScavTrap::ScavTrap(std::string const& name):
ClapTrap(name)
{
	this->initialize();
	guardGate();
	printStatus();
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
ScavTrap::ScavTrap(std::string const& name, unsigned int attackDamage):
ClapTrap(name, attackDamage)
{
	this->initialize();
	guardGate();
	printStatus();
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
	initialize();
	return (*this);
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
	initialize();
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
	std::cout << setColor(className(typeid(*this).name()), _CLASS_COLOR, 0)<< " " <<
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
	std::cout << setColor(className(typeid(*this).name()), _CLASS_COLOR, 0) << " " <<
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
unsigned int ScavTrap::getMaxPoints(void){return (this->_MAX_HIT_POINTS);}

/**
 * @brief Retrieves the class color of the ScavTrap.
 * 
 * This function returns the class color of the FragTrap instance, which is
 * stored in the private member variable _CLASS_COLOR.
 * 
 * @return unsigned int The class color of the ScavTrap.
 */
unsigned int ScavTrap::getClassColor(void)
{
	unsigned int tmp;
	tmp = this->_CLASS_COLOR;
	return (tmp);
}

/**
 * @brief Retrieves the recovery points of the ScavTrap.
 * 
 * This function returns the current recovery points of the ScavTrap instance.
 * The recovery points are stored in the private member variable _recoveryPoints.
 * 
 * @return unsigned int The current recovery points of the ScavTrap.
 */
unsigned int ScavTrap::getRecoveryPoints(void)
{
	unsigned int tmp;
	tmp = _recoveryPoints;
	return (tmp);
}

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
	std::cout << setColor(className(typeid(*this).name()), _CLASS_COLOR, 0) << " "
	<< *this << " is now in Gate Keeper Mode\n";
}