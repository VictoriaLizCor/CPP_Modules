#include <iostream>
#include "Span.hpp"
#include "Utils.hpp"

int main(void)
{
	unsigned int size = getRandomVal<unsigned int>(10);
	Span sp(size);

	try
	{
		std::cout << sp << std::endl;
		size_t max = static_cast<size_t>(std::numeric_limits<int>::max());
		max = 10;
		for (unsigned int i = 0; i < size; ++i)
			sp.addNumber(getRandomVal<int>(max));
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}