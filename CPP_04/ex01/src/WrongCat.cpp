#include "WrongCat.hpp"


/**
 * @brief Default constructor for the WrongCat class.
 *
 * This constructor initializes a WrongCat object. It calls the base class
 * constructor to initialize the WrongAnimal part of the object. It also sets
 * the _CLASS_ICON member variable to the value "🐯". After the object is
 * created, it prints a message to the console indicating that the object was
 * created.
 */
WrongCat::WrongCat():WrongAnimal(className(typeid(*this).name())), _CLASS_ICON("🐯")
{
	std::cout << *this << getColorStr(FGRAY, " was Created") << std::endl;
}

/**
 * @brief Makes the wrong cat roar.
 *
 * This function prints the sound of the wrong cat, which is a roar.
 */
void WrongCat::makeSound(void) const
{
	std::cout << "[ "+ this->WrongAnimal::_CLASS_ICON + " ]";
	std::cout << "[ "+ _CLASS_ICON + " ]" + " :  Roars " + "\n";
}

/**
 * @brief Destructor for the WrongCat class.
 * 
 * This destructor is responsible for destroying an instance of the WrongCat class.
 * It prints a message indicating that the object is being destroyed.
 */
WrongCat::~WrongCat()
{
	std::cout << *this << getColorStr(FGRAY, " was Destroyed") << std::endl;
}

/**
 * @brief Returns the class name of the WrongCat object.
 * 
 * @return std::string The class name of the WrongCat object.
 */
std::string WrongCat::getClass(void)
{
	return (_color + className(typeid(*this).name()) + std::string(C_DEFAULT));
}
