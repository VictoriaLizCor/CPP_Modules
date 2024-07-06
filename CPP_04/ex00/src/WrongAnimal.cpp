#include "WrongAnimal.hpp"

unsigned int WrongAnimal::_objectColor = FLBLACK;

/**
 * @brief Constructs a new WrongAnimal object with the given type.
 * 
 * @param type The type of the WrongAnimal.
 */
WrongAnimal::WrongAnimal(std::string const& type): _CLASS_ICON("⛔"), _type(type), _color(setObjColor(++_objectColor))
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0)
	<< setColor(" was Created", FGRAY, 0) << std::endl ;
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
		_color = setObjColor(++_objectColor);
	}
	std::cout << setColor(className(typeid(*this).name()), _color, 0)
	<< setColor(" Copy was Created", FGRAY, 0) << std::endl ;
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
 * This destructor is responsible for destroying an instance of the WrongAnimal
 * class. It prints a message indicating that the object has been destroyed.
 */
WrongAnimal::~WrongAnimal()
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0)
	<< setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}

/**
 * @brief Makes a sound.
 * 
 * This function prints a sound message to the console.
 * The sound message includes the class icon and a placeholder sound.
 * 
 * @return void
 */
void WrongAnimal::makeSound(void) const
{
	std::cout << "[ "+ _CLASS_ICON + " ]" + "\t     : ... " + "\n";
}

/**
 * @brief Get the type of the WrongAnimal.
 * 
 * @return std::string The type of the WrongAnimal.
 */
std::string WrongAnimal::getType(void) const
{
	return (setColor(_type, _color, 0) + "\t" + "[ "+ _CLASS_ICON + " ]");
}

/**
 * @brief Overloaded stream insertion operator for outputting a WrongAnimal
 * object.
 *
 * This function takes a reference to an ostream object and a reference to a
 * WrongAnimal object. It outputs the type of the WrongAnimal object using the
 * typeid operator.
 *
 * @param os The reference to the ostream object.
 * @param rhs The reference to the WrongAnimal object.
 * @return std::ostream& The reference to the ostream object after outputting
 * the WrongAnimal object.
 */
std::ostream& operator << (std::ostream& os, WrongAnimal& rhs)
{
	os << typeid(rhs).name();
	return (os);
}
