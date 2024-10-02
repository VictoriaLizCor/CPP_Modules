#include <iostream>
#include "MutantStack.hpp"
#include "Utils.hpp"

void testCopy()
{
	printTitle("test cpy", 30 ,'=');
	{
		unsigned int size = static_cast<unsigned int>(getRandomVal<size_t>(10));
		size = 10;
		MutantStack<int> sp;

		size_t max = 10000;
		if (DEBUG == 1)
			max = static_cast<size_t>(std::numeric_limits<int>::max());
		
		std::generate_n(std::back_inserter(sp), size, FillFunctor<int>(max));
		std::cout << sp << std::endl;
		MutantStack<int> cpy(sp);
		std::cout << cpy << std::endl;
		cpy.clear();
		std::cout << "After clean: " << std::endl;
		std::cout << cpy << std::endl;
	}
}
void testSubject()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
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
	// tryCatch(&testException, os);
	// tryCatch(&testCopy, os);
	// tryCatch(&testFill, os);
	// tryCatch(&testShort, os);
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
			// case 1: tryCatch(&testException, os); break;
			// case 2: tryCatch(&testCopy, os); break;
			// case 3: tryCatch(&testFill, os); break;
			// case 4: tryCatch(&testSubject, os); break; 
			// case 5: tryCatch(&testShort, os); break; 
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