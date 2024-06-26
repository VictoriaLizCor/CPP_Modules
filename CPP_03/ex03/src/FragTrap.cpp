#include "FragTrap.hpp"

unsigned int FragTrap::_MAX_HIT_POINTS = 100;
unsigned int FragTrap::_CLASS_COLOR = FLWHITE;

/**
 * @brief Sets the recovery points for the FragTrap.
 * 
 * This method calculates the recovery points by subtracting the attack damage
 * from the maximum points of the FragTrap and updates the _recoveryPoints
 * member variable with this value.
 */
void FragTrap::setRecoveryPoints(void)
{
	_recoveryPoints = this->getMaxPoints() - this->_attackDamage;
}

/**
 * @brief Initializes the FragTrap instance.
 * 
 * This method sets the initial state of a FragTrap instance by setting its
 * hit points to the maximum points value, initializing energy points to 100,
 * and setting the attack damage to 30.
 */
void FragTrap::initialize()
{
	this->_hitPoints = this->getMaxPoints();
	this->_energyPoints = 100; 
	setAttackDamage(30);
}

/**
 * @brief Constructs a new FragTrap object with default values.
 * 
 * Initializes a new FragTrap object by calling the ClapTrap constructor with
 * default name "DefaultFragTrap" and predefined health, energy, and attack
 * values. It also activates guard mode immediately upon creation.
 */
FragTrap::FragTrap(void):
ClapTrap("Default_FragTrap")
{
	this->initialize();
	highFivesGuys();
	printStatus();
}

/**
 * @brief Constructs a new FragTrap object.
 * 
 * Initializes a new FragTrap object with a custom name by calling the ClapTrap
 * constructor with specified name and predefined health, energy, and attack
 * values. It activates guard mode immediately upon creation.
 * 
 * @param name The name for the FragTrap object.
 */
FragTrap::FragTrap(std::string const& name):
ClapTrap(name)
{
	this->initialize();
	highFivesGuys();
	printStatus();
}

/**
 * @brief Constructs a new FragTrap object.
 * 
 * Initializes a new FragTrap object with a custom name by calling the ClapTrap
 * constructor with specified name and predefined health, energy, and attack
 * values. It activates guard mode immediately upon creation.
 * 
 * @param name The name for the FragTrap object.
 */
FragTrap::FragTrap(std::string const& name, unsigned int attackDamage):
ClapTrap(name, attackDamage)
{
	initialize();
	highFivesGuys();
	printStatus();
}

/**
 * @brief Constructs a new FragTrap object.
 * 
 * Initializes a new FragTrap object with a custom name by calling the ClapTrap
 * constructor with specified name and predefined health, energy, and attack
 * values. It activates guard mode immediately upon creation.
 * 
 * @param name The name for the FragTrap object.
 */
FragTrap::FragTrap(
std::string const& name,
unsigned int hitPoints,
unsigned int energyPoints,
unsigned int attackDamage):
ClapTrap(name, hitPoints , energyPoints , attackDamage)
{
	initialize();
	std::cout << setColor(className(typeid(*this).name()), FLWHITE, 0)<< " " <<
	*this << setColor(" was Created", FGRAY, 0) << std::endl;
	printStatus();
}

/**
 * @brief Assignment operator for FragTrap.
 * 
 * Assigns the values from one FragTrap object to another. If the object being
 * assigned is not the same as the current object, it calls the base class
 * ClapTrap's assignment operator to copy the base class attributes.
 * 
 * @param rhs The FragTrap object to assign from.
 * @return Returns a reference to the current object.
 */
FragTrap&::FragTrap::operator=(ClapTrap const& rhs)
{
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
	}
	printStatus();
	return (*this);
}
/**
 * @brief Copy constructor for FragTrap.
 * 
 * This constructor creates a new FragTrap as a copy of an existing one by
 * invoking the copy constructor of the base class, ClapTrap.
 * 
 * @param rhs The FragTrap instance to copy.
 */
FragTrap::FragTrap(ClapTrap const& rhs): ClapTrap(rhs)
{
	initialize();
	printStatus();
}

/**
 * @brief Constructs a new FragTrap object.
 * 
 * Initializes a new FragTrap object with a custom name by calling the ClapTrap
 * constructor with specified name and predefined health, energy, and attack
 * values. It activates guard mode immediately upon creation.
 * 
 * @param name The name for the FragTrap object.
 */
FragTrap::~FragTrap()
{
	std::cout << setColor(className(typeid(*this).name()), _CLASS_COLOR, 0)<< " " <<
	*this << setColor(" was Destroyed", FGRAY, 0) << std::endl;
}

/**
 * @brief Executes an attack on a target.
 * 
 * This function prints a message to the console indicating that the ScavTrap
 * instance has attacked a target, specifying the target and the amount of
 * damage dealt. It also decrements the energy points of the FragTrap instance
 * by one.
 * 
 * @param target The name of the target being attacked.
 */
void FragTrap::attack(std::string const& target)
{
	std::cout << setColor(className(typeid(*this).name()), _CLASS_COLOR, 0) << " " <<
	*this << " " << setColor("attacks", BRED, 0) << " ⚒️  " << target <<
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
unsigned int FragTrap::getMaxPoints(void){return (_MAX_HIT_POINTS);}

/**
 * @brief Retrieves the class color of the FragTrap.
 * 
 * This function returns the class color of the FragTrap instance, which is
 * stored in the private member variable _CLASS_COLOR.
 * 
 * @return unsigned int The class color of the FragTrap.
 */
unsigned int FragTrap::getClassColor(void)
{
	unsigned int tmp;
	tmp = this->_CLASS_COLOR;
	return (tmp);
}

/**
 * @brief Retrieves the recovery points of the FragTrap.
 * 
 * This function returns the current recovery points of the FragTrap instance.
 * The recovery points are stored in the private member variable _recoveryPoints.
 * 
 * @return unsigned int The current recovery points of the FragTrap.
 */
unsigned int FragTrap::getRecoveryPoints(void)
{
	unsigned int tmp;
	tmp = _recoveryPoints;
	return (tmp);
}

/**
 * @brief Requests high fives from guys.
 * 
 * This method prints a message to the console requesting high fives, 
 * utilizing the class name and the object's current state. The output 
 * is colorized for better visibility.
 */
void FragTrap::highFivesGuys(void)
{
	std::cout << setColor(className(typeid(*this).name()), _CLASS_COLOR, 0) << " "
	<< *this << " says High fives guys! 🙌 🙌 🙏\n";
}