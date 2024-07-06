#include "Animal.hpp"

unsigned int Animal::_objectColor = FGRAY;

/**
 * @brief Constructs a new Animal object.
 * 
 * @param type The type of the animal.
 */
Animal::Animal(std::string const& type): 
_CLASS_ICON("🐾"), _type(type), _color(setObjColor(++_objectColor))
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0)
	<< setColor(" was Created", FGRAY, 0) << std::endl ;
}


/**
 * @brief Assignment operator overload for the Animal class.
 * 
 * This function assigns the values of the right-hand side object to the left-hand side object.
 * It checks for self-assignment and updates the type and color of the object.
 * 
 * @param rhs The right-hand side object to assign from.
 * @return A reference to the left-hand side object after assignment.
 */
Animal&::Animal::operator=(Animal const& rhs)
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
 * @brief Copy constructor for the Animal class.
 * 
 * @param rhs The Animal object to be copied.
 */
Animal::Animal(Animal const& rhs){*this=rhs;}

/**
 * @brief Destructor for the Animal class.
 * 
 * This destructor is responsible for destroying an instance of the Animal class.
 * It prints a message indicating that the object has been destroyed.
 */
Animal::~Animal()
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0)
	<< setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}

/**
 * @brief Makes a sound.
 *
 * This function prints a sound message using the _CLASS_ICON variable.
 */
void Animal::makeSound(void) const
{
	std::cout << "[ "+ _CLASS_ICON + " ]" + "\t     : ... " + "\n";
}

/**
 * @brief Get the type of the Animal.
 * 
 * @return std::string The type of the Animal.
 */
std::string Animal::getType(void) const
{
	return (setColor(_type, _color, 0) + "\t" + getIcon());
}

/**
 * @brief Get the icon of the Animal.
 * 
 * @return std::string The icon of the Animal.
 */
std::string Animal::getIcon(void) const
{
	return ("[ "+ _CLASS_ICON + " ]");
}


/**
 * @brief Overloaded stream insertion operator for Animal objects.
 * 
 * This function allows an Animal object to be printed to an output stream.
 * It prints the type of the Animal object using the typeid function.
 * 
 * @param os The output stream to write to.
 * @param rhs The Animal object to be printed.
 * @return std::ostream& The output stream after printing the Animal object.
 */
std::ostream& operator << (std::ostream& os, Animal& rhs)
{
	os << typeid(rhs).name();
	return (os);
}
