#include "Dog.hpp"

/**
 * @brief Default constructor for the Dog class.
 *
 * This constructor initializes a Dog object and sets its class name and class
 * icon. It also prints a message indicating that a Dog object has been created.
 */
Dog::Dog():Animal(className(typeid(*this).name())), _CLASS_ICON("🐶")
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0)
	<< setColor(" was Created", FGRAY, 0) << std::endl ;
}

/**
 * @brief Destructor for the Dog class.
 * 
 * This destructor is responsible for destroying an instance of the Dog class.
 * It prints a message indicating that the Dog object has been destroyed.
 */
Dog::~Dog()
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0)
	<< setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}

/**
 * @brief Makes the dog sound by printing its icon and a bark message.
 * 
 * This function prints the icon of the dog followed by a bark message.
 * The icon is obtained from the base class Animal using the `getIcon` function.
 * The bark message is constructed using the `_CLASS_ICON` constant.
 * 
 * @note This function is a const member function, meaning it does not modify the state of the object.
 */
void Dog::makeSound(void) const
{
	std::cout << this->Animal::getIcon();
	std::cout << "[ "+ _CLASS_ICON + " ]" + " : Barks " + "\n";
}

/**
 * @brief Get the icon representation of the Dog.
 * 
 * @return std::string The icon representation of the Dog.
 */
std::string Dog::getIcon(void) const
{
	return ("[ "+ _CLASS_ICON + " ]");
}