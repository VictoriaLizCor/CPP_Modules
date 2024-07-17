#include "Brain.hpp"

/**
 * @brief Default constructor for the Brain class.
 * 
 * This constructor initializes the `_index` member variable to 0.
 * It also outputs a message indicating that a Brain object was created.
 */
Brain::Brain(): _index(0)
{
	std::cout << *this << getColorStr(FGRAY, " was Created") << std::endl;
}

/**
 * @brief Constructs a Brain object with the given animal name.
 * 
 * @param animal The name of the animal.
 */
Brain::Brain(std::string const& animal):_index(0), _animal(animal)
{
	std::cout << *this << getColorStr(FGRAY, " was Created") << std::endl;
}

/**
 * @brief Assignment operator for the Brain class.
 * 
 * @param rhs The Brain object to assign from.
 * @return Brain& A reference to the assigned Brain object.
 */
Brain&::Brain::operator=(Brain const& rhs)
{
	if (this != &rhs)
	{
		for (size_t i = 0; i < rhs.getSize() ; ++i)
		{
			_ideas[i].clear();
			setIdea(rhs.getIdea(i));
		}
		_index = rhs._index;
	}
	return (*this);
}

/**
 * @brief Copy constructor for the Brain class.
 * 
 * @param rhs The Brain object to be copied.
 */
Brain::Brain(Brain const& rhs){*this = rhs;}

/**
 * @brief Destructor for the Brain class.
 * 
 * This destructor is responsible for destroying an instance of the Brain class.
 * It outputs a message indicating that the Brain object has been destroyed.
 */
Brain::~Brain()
{
	std::cout << *this << getColorStr(FGRAY, " was Destroyed") << std::endl;
}

/**
 * @brief Sets the idea at the current index of the Brain's ideas array.
 *
 * If the current index is within the size of the array, the function sets the
 * idea at the current index. If the idea at the current index is not empty, a
 * warning message is printed before replacing the idea. After setting the idea,
 * the index is incremented. If the index exceeds the size of the array, it is
 * reset to 0.
 *
 * @param idea The idea to be set.
 */
void Brain::setIdea(std::string idea)
{
	if (_index < getSize())
	{
		if (!_ideas[_index].empty())
		{
			std::cout << getColorStr(FLYELLOW, "Warning: ")
			<< "'" + _ideas[_index] + "'" 
			<< getColorStr(FLYELLOW, " will be replaced by '")
			<< "' " + idea + "'"<< "'\n";
		}
		_ideas[_index] = idea;
		_index++;
	}
	else
		_index = 0;
}

/**
 * @brief Retrieves the idea at the specified index from the Brain's list of ideas.
 * If the index is within the valid range, the idea at that index is returned.
 * If the index is out of range, a random idea is selected and returned instead.
 * 
 * @param i The index of the idea to retrieve.
 * @return The idea at the specified index, or a random idea if the index is out of range.
 */
std::string Brain::getIdea(size_t i) const
{
	if (i < getSize())
		return (_ideas[i]);
	else
	{
		size_t idx = getRandomIdea(getSize());
		std::cout << "Ugh! my mind is blank... ";
		return (_ideas[idx]);
	}
}

/**
 * @brief Generates a random index within the range of the Brain's ideas.
 * 
 * @param size The upper limit of the range.
 * @return The randomly generated index.
 */
size_t Brain::getRandomIdea(size_t size) const
{
	static bool seeded = false;
	if (!seeded)
	{
		srand(static_cast<unsigned int>(time(0)));
		seeded = true;
	}
	return (static_cast<size_t>(std::rand()) % size);
}

/**
 * @brief Get the class name of the Brain object.
 * 
 * This function returns the class name of the Brain object. If the _animal member variable is not empty,
 * the class name is prefixed with the animal name followed by "'s ". The class name is then colored using
 * the FLMAGENTA color code.
 * 
 * @return std::string The class name of the Brain object.
 */
std::string Brain::getClass(void) const
{
	std::string str(getColorStr(FLMAGENTA, className(typeid(*this).name())));
	if (_animal.empty())
		return (str);
	str = _animal + getColorStr(FGRAY, "'s ") + str;
	return (str);
}

/**
 * @brief Overloaded stream insertion operator for the Brain class.
 *
 * This function allows the Brain object to be inserted into an output stream.
 * It outputs the class of the Brain object to the stream.
 *
 * @param os The output stream to insert the Brain object into.
 * @param rhs The Brain object to be inserted into the output stream.
 * @return std::ostream& The modified output stream.
 */
std::ostream& operator << (std::ostream& os, Brain& rhs)
{
	os << rhs.getClass();
	return (os);
}

/**
 * @brief Get the size of the brain.
 * 
 * @return The size of the brain.
 */
size_t Brain::getSize(){return (_size);}