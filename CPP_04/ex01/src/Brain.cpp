#include "Brain.hpp"

Brain::Brain(): _index(0)
{
	std::cout << *this << getColorStr(FGRAY, " was Created") << std::endl;
}

Brain::Brain(std::string const& animal):_index(0), _animal(animal)
{
	std::cout << *this << getColorStr(FGRAY, " was Created") << std::endl;
}

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

Brain::Brain(Brain const& rhs){*this = rhs;}

Brain::~Brain()
{
	std::cout << *this << getColorStr(FGRAY, " was Destroyed") << std::endl;
}

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

std::string Brain::getIdea(size_t i) const
{
	if (i < getSize())
		return (_ideas[i]);
	else
	{
		size_t idx = getRandomIdea(getSize());
		std::cout << idx << "- " << "Ugh! my mind is blank. Let's think about: ";
		return (_ideas[idx]);
	}
}

size_t Brain::getRandomIdea(size_t size) const
{
	static bool seeded = false;
	if (!seeded)
	{
		srand(static_cast<unsigned int>(time(0)));
		seeded = true;
	}
	if (size > _size)
		size = _size;
	return (static_cast<size_t>(std::rand()) % size);
}

std::string Brain::getClass(void) const
{
	std::string str(getColorStr(FLMAGENTA, "'s " + className(typeid(*this).name())));
	if (_animal.empty())
		return (getColorStr(FLMAGENTA, className(typeid(*this).name())));
	return (_animal + str);
}

std::ostream& operator << (std::ostream& os, Brain& rhs)
{
	os << rhs.getClass();
	return (os);
}

size_t Brain::getSize(){return (_size);}