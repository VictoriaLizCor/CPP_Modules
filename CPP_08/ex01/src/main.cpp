#include <iostream>
#include "Span.hpp"
#include "Utils.hpp"
#include <vector>

int main(void)
{
	unsigned int size = static_cast<unsigned int>(getRandomVal<size_t>(10));
	size = 10;
	Span sp(size);
	try
	{
		if (DEBUG >= 1)
			std::cout << sp << std::endl;

		size_t max = static_cast<size_t>(std::numeric_limits<int>::max());
		max = 10000;
		if (DEBUG == 1)
		{
			printTitle("test exception", 30 ,'=');
			{
				std::vector<int> test(5);
				std::generate_n(test.begin(), test.size(), FillFunctor<int>(max));
				std::cout << "test size: " << test.size() << std::endl;
				std::cout << "test vector: ";
				std::for_each(test.begin(), test.end(), Span::PrintFunctor < std::vector<int> >(std::cout, test));
				nl(2);
				sp.addRange(test.begin(), test.end());
			}
			std::cout << sp << std::endl;
			for (unsigned int i = 0; i < size; ++i)
				sp.addNumber(getRandomVal<int>(max));
			std::cout << sp << std::endl;
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		}
		else if (DEBUG == 2)
		{
			{
				printTitle("test cpy", 30 ,'=');
				std::generate_n(std::back_inserter(sp.getValues()), size, FillFunctor<int>(max));
				Span cpy(sp);
				std::cout << cpy << std::endl;
				cpy.getValues().clear();
				std::cout << "After clean: " << std::endl;
				std::cout << cpy << std::endl;
			}
			printTitle("test fill", 30 ,'=');
			for (int i = 0; i < 5 ; ++i)
			{
				Span cpy;
				size = static_cast<unsigned int>(getRandomVal<size_t>(100));
				std::cout << "New Size: "<< size << std::endl;
				std::generate_n(std::back_inserter(cpy.getValues()), size, FillFunctor<int>(max));
				std::cout << cpy << std::endl;
			}
		}
		else
		{
			printTitle("test subject", 30 ,'=');
			Span sp1 = Span(5);
			sp1.addNumber(6);
			sp1.addNumber(3);
			sp1.addNumber(17);
			sp1.addNumber(9);
			sp1.addNumber(11);
	std::cout << std::endl;
			std::cout << sp1;
			nl(1);
			std::cout << "Shortest Span: " << sp1.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp1.longestSpan() << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		if (DEBUG >= 1)
			std::cout << sp;
	}
	nl(1);
		return (0);
}

/*
std::deque<int> test(10);
std::cout << "test size: " << test.size() << std::endl;
std::cout << "test vector: ";
std::for_each(test.begin(), test.end(), FillFunctor<int>(max));

std::for_each(test.begin(), test.end(), Span::PrintFunctor< std::deque<int> >(std::cout, test));
*/