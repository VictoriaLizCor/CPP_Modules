#include "WrongCat.hpp"


/**
 * @brief Default constructor for the WrongCat class.
 * 
 * This constructor initializes a WrongCat object. It calls the base class constructor
 * to set the animal's class name and initializes the _CLASS_ICON member variable.
 * It also prints a message indicating that a WrongCat object has been created.
 */
WrongCat::WrongCat():WrongAnimal(className(typeid(*this).name())), _CLASS_ICON("🐯")
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0)
	<< setColor(" was Created", FGRAY, 0) << std::endl ;
}

/**
 * @brief Makes the wrong cat sound.
 * 
 * This function prints the sound of the wrong cat, which is "Roars".
 * The sound is printed in the format "[<class icon>] : Roars".
 * 
 * @return void
 */
void WrongCat::makeSound(void) const
{
	std::cout << "[ "+ this->WrongAnimal::_CLASS_ICON + " ]";
	std::cout << "[ "+ _CLASS_ICON + " ]" + " :  Roars " + "\n";
}

/**
 * @brief Destructor for the WrongCat class.
 * 
 * This destructor is responsible for destroying an object of the WrongCat class.
 * It prints a message indicating that the object has been destroyed.
 */
WrongCat::~WrongCat()
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0)
	<< setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}
