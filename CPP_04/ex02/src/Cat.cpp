#include "Cat.hpp"

const std::string Cat::_THOUGHTS[_IDEAS] = {
	"I need to sleep more.", //0
	"Is that a mouse?", //1
	"I wonder what's outside.", //2
	"Time to knock something off.", //3
	"Why do humans pet me and then stop?", //4
	"I could go for some fish right now.", //5
	"I'm the king/queen of this house.", //6
	"That spot of sunlight looks perfect for a nap.", //7
	"Why is my human not understanding me?", //8
	"I'm bored, time to cause some chaos.", //9
	"Is it time for my next meal yet?", //10
	"That sunbeam looks like a perfect spot for a nap.", //11
	"Why do humans find it necessary to bother me with their petting?", //12
	"I wonder what's outside that window.", //13
	"I should knock that glass off the table to see what happens.", //14
	"What if I can actually catch my tail this time?", //15
	"These humans don't appreciate my early morning serenades.", //16
	"If I fit, I sit.", //17
	"The dog's bed looks more comfortable; I'll sleep there.", //18
	"Why does the red dot always elude me?" //19
};

/**
 * @brief Default constructor for the Cat class.
 *
 * This constructor initializes a Cat object with a default name and color. It
 * also creates a new Brain object for the Cat and sets its ideas.
 *
 * @param None
 * @return None
 */
Cat::Cat():Animal(className(typeid(*this).name())), _Id(Animal::_Id), _CLASS_ICON("🐱"),_brain(0)
{	
	std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
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
 * @brief Assignment operator for the Cat class.
 *
 * This operator assigns the values of the right-hand side object to the
 * left-hand side object. It performs a deep copy of the Brain object owned by
 * the Cat. If the left-hand side object is the same as the right-hand side
 * object, no action is taken. If the left-hand side object already owns a Brain
 * object, it is deleted before creating a new one.
 *
 * @param rhs The right-hand side object to assign from.
 * @return A reference to the left-hand side object after assignment.
 */
Cat&::Cat::operator=(Cat const& rhs)
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
 * @brief Constructs a new Cat object by copying another Cat object.
 *
 * @param rhs The Cat object to be copied.
 */
Cat::Cat(Cat const& rhs):Animal(className(typeid(*this).name())), _Id(Animal::_Id),_CLASS_ICON("🐱"), _brain(0)
{
	*this = rhs;
}

/**
 * @brief Destructor for the Cat class.
 *
 * This destructor is responsible for cleaning up the memory allocated for the
 * Cat object. It deletes the _brain object if it exists and prints a message
 * indicating that the Cat object has been destroyed.
 */
Cat::~Cat()
{
	if (_brain)
		delete _brain;
	std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}

/**
 * @brief Makes the cat sound and prints a random idea from its brain.
 *
 * This function prints the cat's icon followed by the sound it makes. If the
 * DEBUG flag is not set, it also prints a random idea from the cat's brain.
 *
 * @note If the DEBUG flag is set, the function will print the ideas in a
 * sequential order.
 *
 * @return void
 */
void Cat::makeSound(void) const
{
	std::cout << getIcon() << ": Meows: ";
	{
		static size_t i;
		if (DEBUG != 0)
			i = _brain->getRandomIdea(Brain::getSize());
		else if (i >= _brain->getSize())
			i = 0;
		std::cout << "(" << i << ")- " 
		<< _brain->getIdea(i) << "\n";
		i++;
	}
}

/**
 * @brief Get the icon representation of the Cat object.
 *
 * This function returns a string that represents the icon of the Cat object.
 * The icon is formatted as "[ <class_name> <class_icon> ]".
 *
 * @return std::string The icon representation of the Cat object.
 */
std::string Cat::getIcon(void) const
{
	return ("[ "+ getClass() + " " + _CLASS_ICON + " ]");
}

/**
 * @brief Get the class name and color of the Cat object.
 *
 * This function returns a string that represents the class name and color of
 * the Cat object. The class name is obtained using the `typeid` operator, and
 * the color is stored in the `_color` member variable.
 *
 * @return std::string The class name and color of the Cat object.
 */
std::string Cat::getClass(void) const
{
	std::ostringstream os;

	os << _color + className(typeid(*this).name()) 
	<< _Id << std::string(C_DEFAULT);
	return (os.str());
}