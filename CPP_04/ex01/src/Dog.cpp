#include "Dog.hpp"

const std::string Dog::thoughts[20] = {
	"Is it time for a walk? I love walks!",
	"Oh boy, oh boy, a new toy!",
	"I wonder if that's food she's holding.",
	"Squirrel!",
	"Why do cats get to sleep all day?",
	"I could really go for a belly rub right now.",
	"Who's at the door? I must protect the house!",
	"That spot on the couch looks perfect for a nap.",
	"Why won't the cat play with me?",
	"I'm bored, time to chew on some shoes.",
	"Is it dinner time yet?",
	"That puddle looks like a great place to roll around.",
	"Why do humans have to leave the house without me?",
	"I wonder what's beyond that fence.",
	"I should bark at that leaf blowing in the wind.",
	"What if I never catch my tail?",
	"These humans are the best; I love them so much!",
	"If there's room on the bed, it means I'm allowed up, right?",
	"The cat's food smells so much better; maybe I should try it.",
	"Why does the vacuum cleaner exist? I hate it."
};

Dog::Dog():Animal(className(typeid(*this).name())), _CLASS_ICON("🐶"), _brain(new Brain())
{
	std::cout << *this << getColorStr(FGRAY, " was Created") << std::endl;
}

Dog&::Dog::operator=(Dog const& rhs)
{
	if (this != &rhs)
	{
		_color = setObjColor(++_objectColor);
		*_brain = *(rhs._brain);
	} 
	std::cout << *this << getColorStr(FGRAY, " Copy was Created") << std::endl;
	return (*this);
}

Dog::Dog(Dog const& rhs):Animal(className(typeid(*this).name())), _CLASS_ICON("🐶"), _brain(new Brain())
{
	*this = rhs;
}

Dog::~Dog()
{
	if (_brain)
		delete _brain;
	std::cout << *this << getColorStr(FGRAY, " was Destroyed") << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << this->Animal::getIcon();
	std::cout << "[ "+ _CLASS_ICON + " ]" + " : Barks " + "\n";
}

std::string Dog::getIcon(void) const
{
	return ("[ "+ _CLASS_ICON + " ]");
}

std::string Dog::getClass(void)
{
	return (_color + className(typeid(*this).name()) + std::string(C_DEFAULT));
}