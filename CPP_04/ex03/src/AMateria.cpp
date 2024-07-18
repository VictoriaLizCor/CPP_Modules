#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "DoubleLinkedList.hpp"

DoubleLinkedList<AMateria*> AMateria::_list;

int AMateria::_instanceCount = 0;

/**
 * @brief Initializes the color of the AMateria object based on its
 * type.
 *
 * The color is determined by the type of the AMateria object. If the
 * type is "cure", the color is set to green. If the type is "ice",
 * the color is set to blue. For any other type, the color is set to
 * white.
 */
void AMateria::initColor(void)
{
	if (_type == "cure")
		_colorIdStr = getColorFmt(FGREEN);
	else if (_type == "ice")
		_colorIdStr = getColorFmt(FBLUE);
}

/**
 * @brief Constructs an instance of the AMateria class.
 * 
 * @param type The type of the materia.
 */
AMateria::AMateria(std::string const & type):
_instanceAMateria (++_instanceCount),
_type(type)
{
	initColor();
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
	_list.addNode(this);
}

/**
 * @brief Assignment operator for AMateria class.
 *
 * @param rhs The AMateria object to assign from.
 * @return AMateria& The reference to the assigned AMateria object.
 */
AMateria&::AMateria::operator=(AMateria const& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
	return (*this);
}

AMateria::AMateria(AMateria const&rhs):
_instanceAMateria(++_instanceCount),
_type(rhs.getType())
{
	_list.addNode(this);
	*this = rhs;
}

/**
 * @brief Destructor for the AMateria class.
 *
 * This destructor is responsible for destroying an instance of the
 * AMateria class. It decrements the _objId counter and prints a debug
 * message if the DEBUG flag is enabled.
 *
 * @return None.
 */
AMateria::~AMateria(void)
{
	if (_list.deleteNode(this))
	{
		std::cout << *this << " node was deleted from "
		<< getColorStr(_colorIdStr, className((typeid(*this).name())))
		<< " list\n";
	}
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
	--_instanceCount;
	if (_instanceCount == 0)
		_list.clearList(this);
}


/**
 * @brief Get the type of the AMateria object.
 * 
 * @return std::string const& The type of the AMateria object.
 */
std::string const& AMateria::getType() const{return (_type);}


/**
 * @brief Uses the AMateria on the specified target.
 *
 * This function prints the type of the AMateria and the name of the
 * target.
 * @param target The target on which the AMateria is used.
 */
void AMateria::use(ICharacter& target)
{
	std::cout << *this << " type use on " << target.getName() << "\n";
}


/**
 * @brief Get the information about the AMateria object.
 * 
 * This function returns a string containing information about the AMateria object.
 * If the DEBUG flag is enabled, it includes the class name, type, and object ID.
 * Otherwise, it only includes the type.
 * 
 * @return std::string The information about the AMateria object.
 */
std::string AMateria::getInfo(void) const
{
	std::ostringstream os;

	os << _colorIdStr;
	if (DEBUG)
	{
		os << className(typeid(*this).name())
		<< _instanceCount << "::" << _type;
	}
	else 
		os << _type;
	os << C_END;

	return (os.str());
}



/**
 * @brief Overloaded stream insertion operator for AMateria objects.
 * 
 * This function allows an AMateria object to be inserted into an output stream.
 * If the DEBUG flag is enabled, it outputs the detailed information of the AMateria object.
 * Otherwise, it outputs the type of the AMateria object.
 * 
 * @param os The output stream to insert the AMateria object into.
 * @param rhs The AMateria object to be inserted into the output stream.
 * @return std::ostream& A reference to the output stream after the insertion.
 */
std::ostream& operator << (std::ostream& os, AMateria& rhs)
{
	os << rhs.getInfo();
	return (os);
}
