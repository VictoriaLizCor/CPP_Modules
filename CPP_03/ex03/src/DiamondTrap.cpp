#include "DiamondTrap.hpp"

unsigned int DiamondTrap::_MAX_HIT_POINTS = 100;
unsigned int DiamondTrap::_CLASS_COLOR = FWHITE;

/**
 * @brief Sets the name for the DiamondTrap.
 * 
 * This method sets the name for the DiamondTrap instance. It assigns the color
 * from the ClapTrap part of the DiamondTrap to the name's color and sets the
 * name's string to the provided name.
 * 
 * @param name The new name to be set for the DiamondTrap.
 */
void DiamondTrap::setName(std::string const& name)
{
	this->_name.color = ClapTrap::_name.color;
	this->_name.str = name;
}

/**
 * @brief Initializes the DiamondTrap instance.
 * 
 * This method sets the initial state of a DiamondTrap instance. It sets the
 * hit points to the maximum points of a ScavTrap, calculates energy points by
 * combining the modified maximum points of ScavTrap and FragTrap after
 * subtracting their recovery points, and sets the attack damage based on
 * FragTrap's modified maximum points.
 */
void DiamondTrap::initialize()
{
	unsigned int scav;
	unsigned int frag;

	_hitPoints = ScavTrap::getMaxPoints();
	scav = ScavTrap::getMaxPoints() - ScavTrap::getRecoveryPoints();
	frag = FragTrap::getMaxPoints() - FragTrap::getRecoveryPoints();
	_energyPoints = scav + frag;
	setAttackDamage(FragTrap::getMaxPoints() - FragTrap::getRecoveryPoints());
	std::cout << "\n";
}

/**
 * @brief Constructs a new DiamondTrap object with default values.
 * 
 * Initializes a new DiamondTrap object by calling the ClapTrap constructor with
 * default name "DefaultDiamondTrap" and predefined health, energy, and attack
 * values. It also activates guard mode immediately upon creation.
 */
DiamondTrap::DiamondTrap(void):
ClapTrap(std::string("Default_DiamondTrap") + "_clap_name"),ScavTrap(), FragTrap()
{
	setName("Default_DiamondTrap");
	initialize();
	whoAmI();
}

/**
 * @brief Constructs a new DiamondTrap object.
 * 
 * Initializes a new DiamondTrap object with a custom name by calling the ClapTrap
 * constructor with specified name and predefined health, energy, and attack
 * values. It activates guard mode immediately upon creation.
 * 
 * @param name The name for the DiamondTrap object.
 */
DiamondTrap::DiamondTrap(std::string const& name):
ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	setName(name);
	initialize();
	whoAmI();
}

/**
 * @brief Constructs a new DiamondTrap object.
 * 
 * Initializes a new DiamondTrap object with a custom name by calling the ClapTrap
 * constructor with specified name and predefined health, energy, and attack
 * values. It activates guard mode immediately upon creation.
 * 
 * @param name The name for the DiamondTrap object.
 */
DiamondTrap::DiamondTrap(std::string const& name, unsigned int attackDamage):
ClapTrap(name + "_clap_name", attackDamage), ScavTrap(), FragTrap()
{
	setName(name);
	initialize();
	whoAmI();
}

/**
 * @brief Constructs a new DiamondTrap object.
 * 
 * Initializes a new DiamondTrap object with a custom name by calling the ClapTrap
 * constructor with specified name and predefined health, energy, and attack
 * values. It activates guard mode immediately upon creation.
 * 
 * @param name The name for the DiamondTrap object.
 */
DiamondTrap::DiamondTrap(
std::string const& name,
unsigned int hitPoints,
unsigned int energyPoints,
unsigned int attackDamage):
ClapTrap(name, hitPoints , energyPoints , attackDamage), ScavTrap(), FragTrap()
{
	setName(name);
	std::cout << setColor(className(typeid(*this).name()), FWHITE, 0)<< " " <<
	*this << setColor(" was Created", FGRAY, 0) << std::endl;
}

/**
 * @brief Assignment operator for DiamondTrap.
 * 
 * Assigns the values from one DiamondTrap object to another. If the object being
 * assigned is not the same as the current object, it calls the base class
 * ClapTrap's assignment operator to copy the base class attributes.
 * 
 * @param rhs The DiamondTrap object to assign from.
 * @return Returns a reference to the current object.
 */
DiamondTrap&::DiamondTrap::operator=(ClapTrap const& rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	initialize();
	whoAmI();
	return (*this);
}
/**
 * @brief Copy constructor for DiamondTrap.
 * 
 * This constructor creates a new DiamondTrap as a copy of an existing one by
 * invoking the copy constructor of the base class, ClapTrap.
 * 
 * @param rhs The DiamondTrap instance to copy.
 */
DiamondTrap::DiamondTrap(ClapTrap const& rhs): ClapTrap(rhs)
{
	initialize();
	whoAmI();
}

/**
 * @brief Constructs a new DiamondTrap object.
 * 
 * Initializes a new DiamondTrap object with a custom name by calling the ClapTrap
 * constructor with specified name and predefined health, energy, and attack
 * values. It activates guard mode immediately upon creation.
 * 
 * @param name The name for the DiamondTrap object.
 */
DiamondTrap::~DiamondTrap()
{
	std::cout << setColor(className(typeid(*this).name()), FWHITE, 0)<< " " <<
	*this << setColor(" was Destroyed", FGRAY, 0) << std::endl;
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
unsigned int DiamondTrap::getMaxPoints(void){return (_MAX_HIT_POINTS);}

/**
 * @brief Retrieves the class color of the DiamondTrap.
 * 
 * This function returns the class color of the DiamondTrap instance, which is
 * stored in the private member variable _CLASS_COLOR.
 * 
 * @return unsigned int The class color of the DiamondTrap.
 */
unsigned int DiamondTrap::getClassColor(void)
{
	return (_CLASS_COLOR);
}

/**
 * @brief Retrieves the recovery points of the DiamondTrap.
 * 
 * This function returns the current recovery points of the DiamondTrap instance.
 * The recovery points are stored in the private member variable _recoveryPoints.
 * 
 * @return unsigned int The current recovery points of the DiamondTrap.
 */
unsigned int DiamondTrap::getRecoveryPoints(void)
{
	unsigned int tmp;
	tmp = this->_recoveryPoints;
	return (tmp);
}

/**
 * @brief Displays the identity of the DiamondTrap.
 * 
 * This method prints the DiamondTrap's identity by asking itself if it is
 * either its own identity or that of its ClapTrap part. It utilizes the
 * setColor function to format the output color based on the class name and
 * displays both the DiamondTrap's and ClapTrap's names. Finally, it calls
 * printStatus to display the current status of the DiamondTrap.
 */
void DiamondTrap::whoAmI(void)
{
	std::cout << setColor(className(typeid(*this).name()), FWHITE, 0) << " "
	<< "ask itself \"Am I " << *this << " or " << ClapTrap::getName() << "?\"\n";
	printStatus();
}

std::string DiamondTrap::getName(void){return (_name.color + _name.str + C_DEFAULT);}

/**
 * @brief Sets the recovery points for the FragTrap.
 * 
 * This method calculates the recovery points by subtracting the attack damage
 * from the maximum points of the FragTrap and updates the _recoveryPoints
 * member variable with this value.
 */
void DiamondTrap::setRecoveryPoints(void)
{
	_recoveryPoints = this->getMaxPoints() - this->_attackDamage;
}

/**
 * @brief Executes an attack on a target.
 * 
 * This function prints a message to the console indicating that the DiamondTrap
 * instance has attacked a target, specifying the target and the amount of
 * damage dealt. It also decrements the energy points of the ScavTrap instance
 * by one.
 * 
 * @param target The name of the target being attacked.
 */
void DiamondTrap::attack(std::string const& target)
{
	ScavTrap::attack(target);
}
