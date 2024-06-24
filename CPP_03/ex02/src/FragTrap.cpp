#include "FragTrap.hpp"

unsigned int FragTrap::_MAX_HIT_POINTS = 100;

/**
 * @brief Constructs a new FragTrap object with default values.
 * 
 * Initializes a new FragTrap object by calling the ClapTrap constructor with
 * default name "DefaultFragTrap" and predefined health, energy, and attack
 * values. It also activates guard mode immediately upon creation.
 */
FragTrap::FragTrap(void):
ClapTrap("DefaultFragTrap", 100, 100 , 30)
{
	highFivesGuys();
};

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
ClapTrap(name, 100, 100 , 30)
{
	highFivesGuys();
};

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
ClapTrap(name, 100 , 100 , attackDamage)
{
	highFivesGuys();
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
	std::cout << setColor(className(typeid(*this).name()), FLWHITE, 0)<< " " <<
	*this << setColor(" was Created", FGRAY, 0) << std::endl;
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
	std::cout << setColor(className(typeid(*this).name()), FLWHITE, 0) << " " 
	<< *this << setColor(" Copy was Created ", FGRAY, 0) << std::endl ;
	return *this;
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
	std::cout << setColor(className(typeid(*this).name()), FLWHITE, 0) << " " 
	<< *this << setColor(" Copy was Created ", FGRAY, 0) << std::endl ;
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
	std::cout << setColor(className(typeid(*this).name()), FLWHITE, 0)<< " " <<
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
unsigned int FragTrap::getMaxPoints(void){return (_MAX_HIT_POINTS);}

/**
 * @brief Requests high fives from guys.
 * 
 * This method prints a message to the console requesting high fives, 
 * utilizing the class name and the object's current state. The output 
 * is colorized for better visibility.
 */
void FragTrap::highFivesGuys(void)
{
	std::cout << setColor(className(typeid(*this).name()), FLWHITE, 0) << " "
	<< *this << " says High fives guys! 🙌 🙌 🙏\n";
}