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
	"I'm bored, time to cause some chaos." //9
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

Cat::Cat():Animal(className(typeid(*this).name())),
_CLASS_ICON("🐱"),_brain(0)
{	
	std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
	_brain = new Brain(getClass());
	for (size_t i = 0 ; i < Brain::getSize() ; i++)
	{
		if (i < _IDEAS)
			_brain->setIdea(_THOUGHTS[i]);
		else
			_brain->setIdea(_THOUGHTS[_brain->getRandomIdea(_IDEAS)]);
	}
}

Cat&::Cat::operator=(Cat const& rhs)
{
	std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
	if (this != &rhs)
	{
		if (_brain != NULL)
			delete _brain;
		_brain = new Brain(getClass());
		*_brain = *(rhs._brain);
	} 
	return (*this);
}

Cat::Cat(Cat const& rhs):Animal(className(typeid(*this).name())), _CLASS_ICON("🐱"), _brain(0)
{
	*this = rhs;
}

Cat::~Cat()
{
	if (_brain)
		delete _brain;
	std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}

void Cat::makeSound(void) const
{
	std::cout  << getIcon() + " : Meows : ";
	{
		size_t i = _brain->getRandomIdea(Brain::getSize());
		std::cout << "(" << i << ")- "<< _brain->getIdea(i);
	}
}

std::string Cat::getIcon(void) const
{
	return ("[ "+ getClass() + " " + _CLASS_ICON + " ]");
}

std::string Cat::getClass(void) const
{
	return (_color + className(typeid(*this).name()) + std::string(C_DEFAULT));
}