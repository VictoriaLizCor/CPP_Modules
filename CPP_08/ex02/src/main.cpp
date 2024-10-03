#include <iostream>
#include "MutantStack.hpp"
#include "Utils.hpp"
#include "list"

void testCopy()
{
	printTitle("test cpy", 30 ,'=');
	{
		unsigned int size = static_cast<unsigned int>(getRandomVal<size_t>(10));
		size = 10;
		MutantStack<int> sp;
		size_t max = 10000;

		std::generate_n(std::back_inserter(sp.getContainer()), size, FillFunctor<int>(max));
		std::cout << sp << std::endl;
		MutantStack<int> cpy(sp);
		std::cout << cpy << std::endl;
		nl(1);
		MutantStack<int> cpy2;
		cpy2 = cpy;
		std::cout << cpy2 << std::endl;
		std::cout << getColorStr(FGREEN, "---test push_front vs push----") << std::endl;
		cpy2.getContainer().push_front(100);
		cpy2.push(101);
		std::cout << cpy2 << std::endl;
	}
	nl(1);
}

void testList()
{
	printTitle("test List", 30, '=');
	{
		std::list<int> lst;
		std::cout << "list created" << std::endl;
		lst.push_back(5);
		lst.push_back(17);
		if (DEBUG)
		{
			std::cout << "size: " << lst.size() << std::endl;
			std::cout << "values: ";
			std::for_each(lst.begin(), lst.end(), PrintFunctor < std::list<int> >(std::cout, lst));
			nl(1);
			std::cout << "top & pop:";
		}
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		if (DEBUG)
		{
			std::cout << "size: " << lst.size() << std::endl;
			std::cout << "values: ";
			std::for_each(lst.begin(), lst.end(), PrintFunctor < std::list<int> >(std::cout, lst));
			nl(1);
			std::cout << "size: ";
		}
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it;
			if (DEBUG)
				std::cout << " ";
			else
				std::cout << std::endl;
			++it;
		}
		std::stack<int, std::list<int> > s(lst);
		if (DEBUG)
		{
			nl(1);
			std::cout << "---print stack--" << std::endl;
			while (!s.empty())
			{
				std::cout << s.top() << " ";
				s.pop();
			}
			nl(1);
		}
		nl(1);
	}
}

void testSubject()
{
	printTitle("test subject", 30 ,'=');
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		if (DEBUG)
		{
			std::cout << mstack;
			std::cout << "top & pop:";
		}
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		if (DEBUG)
		{
			std::cout << mstack;
			std::cout << "size: ";
		}
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
			std::cout << *it;
			if (DEBUG)
				std::cout << " ";
			else
				std::cout << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		if (DEBUG)
		{
			nl(1);
			// s.push_front(5);
			std::cout << "---print stack--" << std::endl;
			while (!s.empty())
			{
				std::cout << s.top() << " ";
				s.pop();
			}
			nl(1);
			std::list<int> lst;
			std::copy(mstack.begin(), mstack.end(), std::back_inserter(lst));
			std::for_each(lst.begin(), lst.end(), PrintFunctor < std::list<int> >(std::cout, lst));
		}
	}
	nl(1);
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
	tryCatch(&testCopy, os);
	// tryCatch(&testFill, os);
	// tryCatch(&testShort, os);
	tryCatch(&testSubject, os);
	tryCatch(&testList, os);
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
	return (0);
}