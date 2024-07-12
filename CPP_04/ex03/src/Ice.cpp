#include "Ice.hpp"
#include "ICharacter.hpp"

int		Ice::_iceInstanceCount = 0;
/**
 * @brief Constructs a new instance of the Ice class.
 *
 * @param type The type of the Ice materia.
 */
Ice::Ice(std::string const& type):
AMateria(type),
_instanceId(++_iceInstanceCount)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}


/**
 * @brief Assignment operator for the Ice class.
 *
 * @param rhs The right-hand side Ice object to assign from.
 * @return Ice& A reference to the assigned Ice object.
 */
Ice&::Ice::operator=(Ice const& rhs)
{
	(void)rhs;
	// if (this != &rhs)
	// 	AMateria::operator=(rhs);
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
	return (*this);
}

/**
 * @brief Constructs a new instance of the Ice class.
 *
 * @param rhs The Ice object to be copied.
 */
Ice::Ice(Ice const& rhs):
AMateria(rhs.getType()),
_instanceId(++_iceInstanceCount)
{
	*this = rhs;
}

/**
 * @brief Destructor for the Ice class.
 *
 * This destructor is responsible for destroying an instance of the
 * Ice class. It prints a debug message indicating that the object
 * was destroyed.
 */
Ice::~Ice(void)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
	--_iceInstanceCount;
}


/**
 * @brief Get the type of the Ice object.
 * 
 * @return std::string const& The type of the Ice object.
 */
std::string const& Ice::getType() const{return (_type);}

/**
 * @brief Creates a clone of the Ice object.
 * 
 * This function creates a new instance of the Ice class and initializes it with the same
 * values as the current object. It is used to create a copy of the object.
 * 
 * @return A pointer to the newly created Ice object.
 */
Ice *Ice::clone(void) const
{
	if (DEBUG)
	{
		std::cout << getInfo() << " " + std::string(__func__) + "()"
		<< getColorStr(FGRAY," used\n");
	}
	return (new Ice(*this));
}

/**
 * @brief Uses the Ice spell on a target.
 * 
 * This function shoots an ice bolt at the specified target.
 * 
 * @param target The target character to use the spell on.
 */
void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*\n";
}

/**
 * @brief Get the information about the Ice object.
 *
 * This function returns a string containing information about the Ice
 * object. If the DEBUG flag is enabled, it includes the class name,
 * type, and object ID. Otherwise, it only includes the type.
 *
 * @return std::string The information about the Ice object.
 */
std::string Ice::getInfo(void) const
{
	std::ostringstream os;

	os << _colorIdStr;
	if (DEBUG)
		os << className(typeid(*this).name()) << _iceInstanceCount << "::"
	<< _type << _instanceId;
	else 
		os << _type;
	os << std::string(C_END);

	return (os.str());
}

