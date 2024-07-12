#include "Cure.hpp"
#include "ICharacter.hpp"


/**
 * @brief Constructs a new instance of the Cure class.
 *
 * @param type The type of the Cure materia.
 */
Cure::Cure(std::string const& type):
AMateria(type)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}


/**
 * @brief Assignment operator for the Cure class.
 *
 * @param rhs The right-hand side Cure object to assign from.
 * @return Cure& A reference to the assigned Cure object.
 */
Cure&::Cure::operator=(Cure const& rhs)
{
	(void)rhs;
	// if (this != &rhs)
	// 	AMateria::operator=(rhs);
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
	return (*this);
}

/**
 * @brief Constructs a new instance of the Cure class.
 *
 * @param rhs The Cure object to be copied.
 */
Cure::Cure(Cure const& rhs): AMateria(rhs.getType()){*this = rhs;}


/**
 * @brief Destructor for the Cure class.
 *
 * This destructor is responsible for destroying an instance of the
 * Cure class. It prints a debug message indicating that the object
 * was destroyed.
 */
Cure::~Cure(void)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}


/**
 * @brief Get the type of the Cure object.
 * 
 * @return std::string const& The type of the Cure object.
 */
std::string const& Cure::getType() const{return (_type);}

/**
 * @brief Creates a clone of the Cure object.
 * 
 * This function creates a new instance of the Cure class and initializes it with the same
 * values as the current object. It is used to create a copy of the object.
 * 
 * @return A pointer to the newly created Cure object.
 */
Cure *Cure::clone(void) const
{
	if (DEBUG)
	{
		std::cout << getInfo() << " " + std::string(__func__) + "()"
		<< getColorStr(FGRAY," used\n");
	}
	return (new Cure(*this));
}

/**
 * @brief Uses the Cure spell on a target.
 * 
 * This function shoots an ice bolt at the specified target.
 * 
 * @param target The target character to use the spell on.
 */
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds*\n";
}

/**
 * @brief Get the information about the Cure object.
 *
 * This function returns a string containing information about the Cure
 * object. If the DEBUG flag is enabled, it includes the class name,
 * type, and object ID. Otherwise, it only includes the type.
 *
 * @return std::string The information about the Cure object.
 */
std::string Cure::getInfo(void) const
{
	std::ostringstream os;

	os << _colorIdStr;
	if (DEBUG)
		os << className(typeid(*this).name()) << "::"
	<< _type << toString(_objId);
	else 
		os << _type;
	os << std::string(C_END);

	return (os.str());
}
