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

Dog::Dog():Animal(className(typeid(*this).name())), _CLASS_ICON("🐶") ,_brain(0)
{
	std::cout << *this << getColorStr(FGRAY, " was Created\n");
	_brain = new Brain(getClass());
	for (size_t i = 0 ; i < Brain::getSize() ; i++)
	{
		if (i < _IDEAS)
			_brain->setIdea(_THOUGHTS[i]);
		else
			_brain->setIdea(_THOUGHTS[_brain->getRandomIdea(_IDEAS)]);
	}
}

Dog&::Dog::operator=(Dog const& rhs)
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

Dog::Dog(Dog const& rhs):Animal(className(typeid(*this).name())), _CLASS_ICON("🐶"),_brain(0)
{
	*this = rhs;
}

Dog::~Dog()
{
	if (_brain)
		delete _brain;
	std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}

void Dog::makeSound(void) const
{
	std::cout << getIcon() + ": Barks : ";
	{
		size_t i = _brain->getRandomIdea(Brain::getSize());
		std::cout << "(" << i << ")- "<<_brain->getIdea(i);
	}
}

std::string Dog::getIcon(void) const
{
	return ("[ "+ getClass() + " " + _CLASS_ICON + " ]");
}

std::string Dog::getClass(void) const
{
	return (_color + className(typeid(*this).name()) + std::string(C_DEFAULT));
}