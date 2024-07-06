#include "Animal.hpp"

int Animal::_Id = 0;

/**
 * @brief Constructs a new Animal object.
 * 
 * @param type The type of the animal.
 */
Animal::Animal(std::string const& type): _CLASS_ICON("🐾"), _type(type), _color(setObjColor(FGRAY + ++_Id))
{
	std::cout << *this << getColorStr(FGRAY, " was Created\n");
}

/**
 * @brief Assignment operator overload for the Animal class.
 * 
 * @param rhs The Animal object to be assigned.
 * @return A reference to the assigned Animal object.
 */
Animal&::Animal::operator=(Animal const& rhs)
{
	if (this != &rhs)
		_color = setObjColor(FGRAY + (++_Id));
	std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
	return (*this);
}

/**
 * @brief Copy constructor for the Animal class.
 *
 * This constructor creates a new Animal object by copying the contents of another Animal object.
 *
 * @param rhs The Animal object to be copied.
 */
Animal::Animal(Animal const& rhs){*this = rhs;}

/**
 * @brief Destructor for the Animal class.
 *
 * This destructor is responsible for destroying an instance of the Animal
 * class. It decrements the _Id counter and prints a message indicating that the
 * Animal object was destroyed.
 *
 */
Animal::~Animal()
{
	std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
	--_Id;
}

/**
 * @brief Makes a sound.
 *
 * This function prints the sound made by the animal.
 */
void Animal::makeSound(void) const
{
	std::cout << getIcon() + "\t     : ... " + "\n";
}

/**
 * @brief Get the type of the animal.
 * 
 * @return std::string The type of the animal.
 */
std::string Animal::getType(void) const
{
	return (_color + _type + "\t" + getIcon());
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
 * @brief Get the ID of the animal.
 * 
 * @return int The ID of the animal.
 */
int Animal::getId(void) const{return (_Id);}

/**
 * @brief Get the class name and color of the Animal object.
 * 
 * This function returns a string that represents the class name and color of the Animal object.
 * The class name is obtained using the `typeid` operator, and the color is stored in the `_color` member variable.
 * 
 * @return std::string The class name and color of the Animal object.
 */
std::string Animal::getClass(void) const
{
	std::ostringstream os;

	os << _color + className(typeid(*this).name()) 
	<< _Id << std::string(C_DEFAULT);
	return (os.str());
}

/**
 * @brief Overloaded stream insertion operator for Animal objects.
 * 
 * This function allows an Animal object to be printed to an output stream.
 * It prints the class name of the Animal object to the output stream.
 * 
 * @param os The output stream to write to.
 * @param rhs The Animal object to be printed.
 * @return std::ostream& The output stream after printing the Animal object.
 */
std::ostream& operator << (std::ostream& os, Animal const& rhs)
{
	os << rhs.getClass();
	return (os);
}
