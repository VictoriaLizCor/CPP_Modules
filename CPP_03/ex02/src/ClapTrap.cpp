#include "ClapTrap.hpp"
#include <typeinfo>

unsigned int ClapTrap::_MAX_HIT_POINTS = 10;
int ClapTrap::_objectColor = FGRAY;
/**
 * @brief Sets the color name based on the provided color code.
 * 
 * @param color The color code.
 * @return std::string The color name.
 */
static std::string setColorName(int const& color)
{
	if (DEBUG == 0)
		return (setColor("", color, 0));
	else
		return (setRandomColor(1));
}

/**
 * @brief Initializes a ClapTrap object.
 * 
 * @param name The name of the ClapTrap object.
 */
void ClapTrap::initialize(std::string const& name)
{
	if(_name.str.empty())
		_name.color = setColorName(++_objectColor);
	setName(name);
	_hitPoints = 10;
	_energyPoints = 10;
	_recoveryPoints = 0;
	_attackDamage = 0;
}

/**
 * @brief Default constructor for ClapTrap.
 * 
 * Initializes a ClapTrap object with the default name "DefaultClapTrap".
 */
ClapTrap::ClapTrap(void)
{
	initialize("DefaultClapTrap");
	std::cout << setColor(className(typeid(*this).name()), FGRAY, 0) << " " <<
	*this << setColor(" was Created", FGRAY, 0) << std::endl ;
};

/**
 * @brief Construct a new Clap Trap object
 * 
 * @param name The name of the Clap Trap
 * 	_name{name, setName(++_color)}; // not allowed in std98++
 */
ClapTrap::ClapTrap(std::string const& name)
{
	initialize(name);
	std::cout << setColor(className(typeid(*this).name()), FGRAY, 0) << " " <<
	*this << setColor(" was Created", FGRAY, 0) << std::endl ;
};

/**
 * @brief Constructor for ClapTrap.
 * 
 * @param name The name of the ClapTrap object.
 * @param attackDamage The attack damage of the ClapTrap object.
 */
ClapTrap::ClapTrap(std::string const& name, unsigned int attackDamage)
{
	initialize(name);
	setAttackDamage(attackDamage);
	std::cout << setColor(className(typeid(*this).name()), FGRAY, 0) << " " <<
	*this << setColor(" was Created", FGRAY, 0) << std::endl ;
};

/**
 * @brief Constructor for ClapTrap.
 * 
 * @param name The name of the ClapTrap object.
 * @param attackDamage The attack damage of the ClapTrap object.
 */
ClapTrap::ClapTrap(
std::string const& name,
unsigned int hitPoints,
unsigned int energyPoints,
unsigned int attackDamage):
_hitPoints(hitPoints),
_energyPoints(energyPoints)
{
	if(_name.str.empty())
		_name.color = setColorName(++_objectColor);
	setName(name);
	setAttackDamage(attackDamage);
	std::cout << setColor(className(typeid(*this).name()), FGRAY, 0) << " " <<
	*this << setColor(" was Created", FGRAY, 0) << std::endl ;
};

/**
 * @brief Destructor for ClapTrap.
 * 
 * Outputs a message indicating that the ClapTrap object was destroyed.
 */
ClapTrap::~ClapTrap(void)
{
	std::cout << setColor(className(typeid(*this).name()), FGRAY, 0) << " " <<
	*this << setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}

/**
 * @brief Overloads the assignment operator for ClapTrap.
 * 
 * @param rhs The ClapTrap object to assign from.
 * @return ClapTrap& A reference to the assigned ClapTrap object.
 */
ClapTrap&::ClapTrap::operator=(ClapTrap const& rhs)
{
	if (this != &rhs)
	{
		_name.str = rhs._name.str;
		_name.color = setColorName(++_objectColor);
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	std::cout << setColor(className(typeid(*this).name()), FGRAY, 0) << " " 
	<< *this << setColor(" Copy was Created ", FGRAY, 0) << std::endl ;
	return (*this);
}

/**
 * @brief Copy constructor for ClapTrap.
 * 
 * @param rhs The ClapTrap object to copy from.
 */
ClapTrap::ClapTrap(ClapTrap const& rhs){*this = rhs;}