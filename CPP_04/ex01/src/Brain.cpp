#include "Brain.hpp"


Brain::Brain():_index(0)
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

std::string Brain::getClass(void)
{
	return (getColorStr(FLMAGENTA, className(typeid(*this).name())));
}

void Brain::setIdea(std::string const idea)
{
	if (_index < getSize())
	{
		if (!_ideas[_index].empty())
		{
			std::cout << getColorStr(FLYELLOW, "Warning: ")
			<< _ideas[_index] << " will be replaced by '"
			<< idea << "'\n";
		}
		_ideas[_index++] = idea;
	}
	else
		_index = 0;
}

std::string Brain::getIdea(size_t i) const
{
	if (i > 0 && i < getSize())
		return (_ideas[i]);
	else
	{
		std::cout << "ugh! my mind is blank. Let's think about: ";
		return (getRandomIdea());
	}
}

size_t Brain::getRandomIdea(size_t size) const
{
	static bool seeded = false;
	if (!seeded) {
		srand(static_cast<unsigned int>(time(0)));
		seeded = true;
	}
	return (static_cast<size_t>(std::rand()) % size)
}

std::ostream& operator << (std::ostream& os, Brain& rhs)
{
	os << rhs.getClass();
	return (os);
}

size_t Brain::getSize(){return (_size);}