#include <iostream>
#include "Span.hpp"
#include "Utils.hpp"
#include <vector>

template<typename T>
void fill(T& value, size_t max)
{
	value = getRandomVal<int>(max);
}

template<>
void fill<Span&>(Span& value, size_t max)
{
	value.addNumber(getRandomVal<int>(max));
}

int main(void)
{
	try
	{
		if (DEBUG == 1)
		{
			unsigned int size = static_cast<unsigned int>(getRandomVal<size_t>(10));
			Span sp(size);
			std::cout << sp << std::endl;
			size_t max = static_cast<size_t>(std::numeric_limits<int>::max());
			max = 10;
			{
				std::vector<int> dummy(size);
				// std::for_each(dummy.begin(), dummy.end(), Span::Fill(sp, max));
				std::for_each(dummy.begin(), dummy.end(), fill<int>(sp,max));
			}
			// for (unsigned int i = 0; i < size; ++i)
			// 	sp.addNumber(getRandomVal<int>(max));
			std::cout << sp << std::endl;
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		}
		else if (DEBUG == 2)
		{
			std::deque<int> test(10);
			std::for_each(test.begin(), test.end(), fill<int>);

			std::for_each(test.begin(), test.end(), Span::PrintFunctor(std::cout, test));
			std::cout << std::endl;
		}
		else
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
    std::cout << std::endl;
			std::cout << sp;
			nl(1);
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	nl(1);
		return (0);
}