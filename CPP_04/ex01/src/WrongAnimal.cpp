#include "WrongAnimal.hpp"

int WrongAnimal::_Id = FLBLACK;

/**
 * @brief Constructs a new WrongAnimal object with the given type.
 * 
 * @param type The type of the WrongAnimal.
 */
WrongAnimal::WrongAnimal(std::string const& type): _CLASS_ICON("⛔"), _type(type), _color(setObjColor(++_Id))
{
	std::cout << *this << getColorStr(FGRAY, " was Created") << std::endl;
}

/**
 * @brief Assignment operator for the WrongAnimal class.
 * 
 * @param rhs The right-hand side object to assign from.
 * @return Reference to the assigned object.
 */
WrongAnimal&::WrongAnimal::operator=(WrongAnimal const& rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
		_color = setObjColor(++_Id);
	}
	std::cout << *this << getColorStr(FGRAY, " Copy was Created") << std::endl;
	return (*this);
}

/**
 * @brief Copy constructor for the WrongAnimal class.
 * 
 * @param rhs The object to be copied.
 */
WrongAnimal::WrongAnimal(WrongAnimal const& rhs){*this=rhs;}

/**
 * @brief Destructor for the WrongAnimal class.
 * 
 * This destructor is responsible for destroying an instance of the WrongAnimal class.
 * It prints a message indicating that the object has been destroyed.
 */
WrongAnimal::~WrongAnimal()
{
	std::cout << *this << getColorStr(FGRAY, " was Destroyed") << std::endl;
}

/**
 * @brief Makes a sound.
 *
 * This function prints a message indicating that the animal is making a sound.
 */
void WrongAnimal::makeSound(void) const
{
	std::cout << "[ "+ _CLASS_ICON + " ]" + "\t     : ... " + "\n";
}

/**
 * @brief Get the type of the WrongAnimal.
 * 
 * This function returns the type of the WrongAnimal, which is a combination of its color, type, and class icon.
 * 
 * @return std::string The type of the WrongAnimal.
 */
std::string WrongAnimal::getType(void) const
{
	return (_color + _type + std::string(C_DEFAULT) + "\t" + "[ "+ _CLASS_ICON + " ]");
}

/**
 * @brief Get the class name of the WrongAnimal object.
 * 
 * @return std::string The class name of the WrongAnimal object.
 */
std::string WrongAnimal::getClass(void)
{
	return (_color + className(typeid(*this).name()) + std::string(C_DEFAULT));
}

/**
 * @brief Overloaded stream insertion operator for outputting a WrongAnimal object.
 * 
 * @param os The output stream to write to.
 * @param rhs The WrongAnimal object to be outputted.
 * @return std::ostream& The output stream after writing the WrongAnimal object.
 */
std::ostream& operator << (std::ostream& os, WrongAnimal& rhs)
{
	os << rhs.getClass();
	return (os);
}
