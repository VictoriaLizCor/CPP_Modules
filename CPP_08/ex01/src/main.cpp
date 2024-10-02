#include <iostream>
#include "Span.hpp"
#include "Utils.hpp"
#include <vector>

void testException()
{
	printTitle("test exception", 30 ,'=');
	{
		unsigned int size = static_cast<unsigned int>(getRandomVal<size_t>(10));
		size = 10;
		Span sp(size);

		size_t max = 10000;
		if (DEBUG == 1)
			max = static_cast<size_t>(std::numeric_limits<int>::max());

		std::vector<int> test(5);
		std::generate_n(test.begin(), test.size(), FillFunctor<int>(max));
		std::cout << "test size: " << test.size() << std::endl;
		std::cout << "test vector: ";
		std::for_each(test.begin(), test.end(), Span::PrintFunctor < std::vector<int> >(std::cout, test));
		nl(2);
		sp.addRange(test.begin(), test.end());
		std::cout << sp << std::endl;
		for (unsigned int i = 0; i < size; ++i)
			sp.addNumber(getRandomVal<int>(max));
	}
}

void testCopy()
{
	printTitle("test cpy", 30 ,'=');
	{
		unsigned int size = static_cast<unsigned int>(getRandomVal<size_t>(10));
		size = 10;
		Span sp(size);

		size_t max = 10000;
		if (DEBUG == 1)
			max = static_cast<size_t>(std::numeric_limits<int>::max());
		
		std::generate_n(std::back_inserter(sp.getValues()), size, FillFunctor<int>(max));
		std::cout << sp << std::endl;
		Span cpy(sp);
		std::cout << cpy << std::endl;
		cpy.getValues().clear();
		std::cout << "After clean: " << std::endl;
		std::cout << cpy << std::endl;
	}
}

void testFill()
{
	printTitle("test fill", 30 ,'=');
	{
		unsigned int size = static_cast<unsigned int>(getRandomVal<size_t>(10));
		size_t max = 10000;

		if (DEBUG == 1)
		{
			size = static_cast<unsigned int>(getRandomVal<size_t>(10));
			max = static_cast<size_t>(std::numeric_limits<int>::max());
		}
		
		for (int i = 0; i < 2 ; ++i)
		{
			Span cpy;
			size = static_cast<unsigned int>(getRandomVal<size_t>(100));
			nl(1);
			std::cout << "New Size: "<< size << std::endl;
			std::generate_n(std::back_inserter(cpy.getValues()), size, FillFunctor<int>(max));
			std::cout << cpy << std::endl;
			std::cout << "Shortest Span: " << cpy.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << cpy.longestSpan() << std::endl;
		}
	}
}

void testShort()
{
	printTitle("testShort", 30 ,'=');
	unsigned int max = static_cast<unsigned int>(getRandomVal<size_t>(3));

	std::cout << "size: " << max << std::endl;
	{
		Span cpy(max);

		std::generate_n(std::back_inserter(cpy.getValues()), max, FillFunctor<int>(1000));
		std::cout << cpy << std::endl;
		std::cout << "Shortest Span: \n" << cpy.shortestSpan() << std::endl;
		std::cout << "Longest Span: \n" << cpy.longestSpan() << std::endl;
	}
	
}

void testSubject()
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

static void fill(std::exception const &e, std::ostringstream& os)
{
	static int color = FLWHITE;
	if (os.str().empty())
		os << getColorStr(--color, demangle(typeid(e).name()) + ": \n");
	os << e.what();
}


static void orderException(std::exception const &e, std::ostringstream* os[])
{
	std::cerr << e.what() << std::endl;
	if (typeid(e) == typeid(std::logic_error))
		fill(e, *os[0]);
	else if (typeid(e) == typeid(std::out_of_range))
		fill(e, *os[1]);
	else
		fill(e, *os[2]);
}

void tryCatch(void (*test)(), std::ostringstream* os[])
{
	try{ test();}
	catch (std::exception  const &e){orderException(e, os);}
	catch(...)
	{
		std::cerr << error("Problems during what() message formatting\n", 1);
	}
}

static void InitoOS(std::ostringstream* os[], size_t& arraySize)
{
	for (size_t i = 0; i < arraySize; ++i)
		os[i] = new std::ostringstream();
}

static void cleanOS(std::ostringstream* os[], size_t& arraySize)
{
	for (size_t i = 0; i < arraySize; ++i)
		delete os[i];
}

static void runAllTest(std::ostringstream* os[])
{
	tryCatch(&testException, os);
	tryCatch(&testCopy, os);
	tryCatch(&testFill, os);
	tryCatch(&testShort, os);
	tryCatch(&testSubject, os);
}

static void printExeptions(std::ostringstream* os[], size_t& arraySize)
{
	bool seed = 0;

	for (size_t i = 0; i < arraySize; ++i)
	{
		if (!os[i]->str().empty())
		{
			if (seed == 0)
			{
				printTitle("MAIN REPORT", 60);
				std::cerr << "\n" 
				<< error("Problems during Object creation / handle\n\n", 1);
				seed = 1;
			}
			std::cerr << os[i]->str() << "\n";
		}

	}
}

int	main(int ac, char* arg[])
{
	std::ostringstream* os[7] = { NULL, NULL, NULL };
	bool				jump = false;

	size_t arraySize = sizeof(os) / sizeof(os[0]);
	InitoOS(os, arraySize);
	if (ac == 2)
	{
		int choice = std::atoi(arg[1]);
		switch (choice)
		{
			case 1: tryCatch(&testException, os); break;
			case 2: tryCatch(&testCopy, os); break;
			case 3: tryCatch(&testFill, os); break;
			case 4: tryCatch(&testSubject, os); break; 
			case 5: tryCatch(&testShort, os); break; 
			default: jump = true; break;
		}
	}
	if (jump || ac != 2)
		runAllTest(os);
	printExeptions(os, arraySize);
	std::cout << std::endl << std::flush;
	std::cerr << std::flush;
	cleanOS(os, arraySize);
	nl(1);
	return (0);
}