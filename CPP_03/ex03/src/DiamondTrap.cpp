#include "DiamondTrap.hpp"

unsigned int DiamondTrap::_MAX_HIT_POINTS = 100;

void DiamondTrap::initialize()
{
	_energyPoints = ScavTrap::getMaxPoints() - ScavTrap::getRecoveryPoints();
	std::cout << FragTrap::getRecoveryPoints() << std::endl;
	std::cout << ScavTrap::getRecoveryPoints() << std::endl;
	std::cout << FragTrap::getMaxPoints() << std::endl;
	std::cout << ScavTrap::getMaxPoints() << std::endl;
	setAttackDamage(FragTrap::getMaxPoints() - FragTrap::getRecoveryPoints());
	// std::cout << FragTrap::_attackDamage << std::endl;
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
 * @brief Requests high fives from guys.
 * 
 * This method prints a message to the console requesting high fives, 
 * utilizing the class name and the object's current state. The output 
 * is colorized for better visibility.
 */
void DiamondTrap::whoAmI(void)
{
	std::cout << setColor(className(typeid(*this).name()), FWHITE, 0) << " "
	<< *this << " has and existential crisis\n";
	printStatus();
}