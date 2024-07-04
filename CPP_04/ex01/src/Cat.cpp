#include "Cat.hpp"

const std::string Cat::thoughts[20] = {
	"I need to sleep more.",
	"Is that a mouse?",
	"I wonder what's outside.",
	"Time to knock some glasses off.",
	"Why do humans pet me and then stop?",
	"I could go for some fish right now.",
	"I'm the king/queen of this house.",
	"That spot of sunlight looks perfect for a nap.",
	"Why is my human not understanding me?",
	"I'm bored, time to cause some chaos."
	"Is it time for my next meal yet?",
	"That sunbeam looks like a perfect spot for a nap.",
	"Why do humans find it necessary to bother me with their petting?",
	"I wonder what's outside that window.",
	"I should knock that glass off the table to see what happens.",
	"What if I can actually catch my tail this time?",
	"These humans don't appreciate my early morning serenades.",
	"If I fit, I sit.",
	"The dog's bed looks more comfortable; I'll sleep there.",
	"Why does the red dot always elude me?"
};

Cat::Cat():Animal(className(typeid(*this).name())),
_CLASS_ICON("🐱"), _brain(new Brain())
{
	for (size_t i = 0 ; i < 20 ; i++)
		_brain->setIdea(thoughts[i]);
	
	std::cout << *this << getColorStr(FGRAY, " was Created") << std::endl;
}

Cat&::Cat::operator=(Cat const& rhs)
{
	if (this != &rhs)
	{
		_color = setObjColor(++_objectColor);
		*_brain = *(rhs._brain);
	} 
	std::cout << *this << getColorStr(FGRAY, " Copy was Created") << std::endl;
	return (*this);
}

Cat::Cat(Cat const& rhs):Animal(className(typeid(*this).name())), _CLASS_ICON("🐱"), _brain(new Brain())
{
	*this = rhs;
}

Cat::~Cat()
{
	if (_brain)
		delete _brain;
	std::cout << *this << getColorStr(FGRAY, " was Destroyed") << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << this->Animal::getIcon();
	std::cout << "[ "+ _CLASS_ICON + " ]" + " : Meows " + "\n";
}

std::string Cat::getIcon(void) const
{
	return ("[ "+ _CLASS_ICON + " ]");
}

std::string Cat::getClass(void)
{
	return (_color + className(typeid(*this).name()) + std::string(C_DEFAULT));
}