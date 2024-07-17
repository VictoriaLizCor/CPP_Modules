#include "Dog.hpp"

const std::string Dog::_THOUGHTS[_IDEAS] = {
	"Is it time for a walk? I love walks!", // 0
	"Oh boy, oh boy, a new toy!", // 1
	"I wonder if that's food she's holding.", // 2
	"Squirrel!", // 3
	"Why do cats get to sleep all day?", // 4
	"I could really go for a belly rub right now.", // 5
	"Who's at the door? I must protect the house!", // 6
	"That spot on the couch looks perfect for a nap.", // 7
	"Why won't the cat play with me?", // 8
	"I'm bored, time to chew on some shoes.", // 9
	"Is it dinner time yet?", // 10
	"That puddle looks like a great place to roll around.", // 11
	"Why do humans have to leave the house without me?", // 12
	"I wonder what's beyond that fence.", // 13
	"I should bark at that leaf blowing in the wind.", // 14
	"What if I never catch my tail?", // 15
	"These humans are the best; I love them so much!", // 16
	"If there's room on the bed, it means I'm allowed up, right?", // 17
	"The cat's food smells so much better; maybe I should try it.", // 18
	"Why does the vacuum cleaner exist? I hate it." // 19
};

/**
 * @brief Default constructor for the Dog class.
 *
 * This constructor initializes a Dog object with a unique ID, class name, and a
 * brain. It also sets the class icon to "🐶" and assigns random thoughts to the
 * brain.
 *
 * @param None
 * @return None
 */
Dog::Dog():Animal(className(typeid(*this).name())), _Id(Animal::_Id),_CLASS_ICON("🐶") ,_brain(0)
{
	std::cout << *this << getColorStr(FGRAY, " was Created\n");
	_brain = new Brain(this);
	for (size_t i = 0 ; i < Brain::getSize() ; i++)
	{
		if (i < _IDEAS)
			_brain->setIdea(_THOUGHTS[i]);
		else
			_brain->setIdea(_THOUGHTS[_brain->getRandomIdea(_IDEAS)]);
	}
}

/**
 * @brief Assignment operator for Dog class.
 *
 * This operator assigns the values of the right-hand side object to the
 * left-hand side object. It performs a deep copy of the _brain member variable.
 *
 * @param rhs The right-hand side object to be assigned.
 * @return A reference to the left-hand side object after assignment.
 */
Dog&::Dog::operator=(Dog const& rhs)
{
	std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
	if (this != &rhs)
	{
		if (_brain != NULL)
			delete _brain;
		_brain = new Brain(this);
		*_brain = *(rhs._brain);
	} 
	return (*this);
}

/**
 * @brief Constructs a new Dog object by copying another Dog object.
 *
 * @param rhs The Dog object to be copied.
 */
Dog::Dog(Dog const& rhs):Animal(className(typeid(*this).name())), _Id(Animal::_Id), _CLASS_ICON("🐶"),_brain(0)
{
	*this = rhs;
}

/**
 * @brief Destructor for the Dog class.
 *
 * This destructor is responsible for cleaning up the memory allocated for the
 * Dog object. It deletes the _brain object if it exists and prints a message
 * indicating that the Dog object has been destroyed.
 */
Dog::~Dog()
{
	if (_brain)
		delete _brain;
	std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}

/**
 * @brief Makes the dog sound and prints a random idea from its brain.
 *
 * This function prints the dog's icon followed by the message "Barks: " and a
 * random idea from its brain. If the DEBUG flag is not set, a random idea is
 * selected from the brain. If the DEBUG flag is set, the function will cycle
 * through all the ideas in the brain.
 *
 * @note The function assumes that the dog has a brain object associated with
 * it.
 *
 * @return void
 */
void Dog::makeSound(void) const
{
	std::cout << getIcon() + ": Barks: ";
	{
		static size_t i;
		if (DEBUG != 0)
			i = _brain->getRandomIdea(Brain::getSize() + 10);
		else if (i >= _brain->getSize())
			i = 0;
		std::cout << "(" << i << ")- " 
		<< _brain->getIdea(i) << "\n";
		i++;
	}
}

/**
 * @brief Get the icon representation of the Dog class.
 *
 * @return std::string The icon representation of the Dog class.
 */
std::string Dog::getIcon(void) const
{
	return ("[ "+ getClass() + " " + _CLASS_ICON + " ]");
}

/**
 * @brief Get the class name and color of the Dog object.
 *
 * This function returns a string that represents the class name and color of
 * the Dog object. The class name is obtained using the `typeid` operator, and
 * the color is stored in the `_color` member variable.
 *
 * @return std::string The class name and color of the Dog object.
 */
std::string Dog::getClass(void) const
{
	std::ostringstream os;

	os << _color + className(typeid(*this).name()) 
	<< _Id << std::string(C_DEFAULT);
	return (os.str());
}