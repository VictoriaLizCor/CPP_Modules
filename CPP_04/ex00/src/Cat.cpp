#include "Cat.hpp"

Cat::Cat():Animal()
{
	
}

Cat::~Cat()
{
	std::cout << _type << setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}

