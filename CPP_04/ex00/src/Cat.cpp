#include "Cat.hpp"

/**
 * @brief Default constructor for the Cat class.
 *
 * This constructor initializes a Cat object. It sets the class name using the
 * typeid function, and initializes the _CLASS_ICON member variable with the cat
 * emoji. It also prints a message indicating that a Cat object has been
 * created.
 */
Cat::Cat():Animal(className(typeid(*this).name())),
_CLASS_ICON("🐱")
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) 
	<< setColor(" was Created", FGRAY, 0) << std::endl ;
}

/**
 * @brief Destructor for the Cat class.
 *
 * This destructor is responsible for destroying an instance of the Cat class.
 * It prints a message indicating that the Cat object has been destroyed.
 */
Cat::~Cat()
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) 
	<< setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}

/**
 * @brief Makes the cat sound by printing "Meows" to the console.
 *
 * This function is a member of the `Cat` class and it prints the sound of a
 * cat, which is "Meows", along with the class icon.
 */
void Cat::makeSound(void) const
{
	std::cout << this->Animal::getIcon();
	std::cout << "[ "+ _CLASS_ICON + " ]" + " : Meows " + "\n";
}

/**
 * @brief Get the icon of the Cat.
 * 
 * This function returns the icon of the Cat as a string.
 * The icon is enclosed in square brackets.
 * 
 * @return std::string The icon of the Cat.
 */
std::string Cat::getIcon(void) const
{
	return ("[ "+ _CLASS_ICON + " ]");
}