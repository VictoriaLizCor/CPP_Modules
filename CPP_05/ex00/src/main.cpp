#include "Bureaucrat.hpp"
#include "Utils.hpp"

void	testBasic(void)
{
	{
		printTitle("testBasic", 60);
		Bureaucrat	test("test", 6);

		printTitle("Decrement", 20);
		std::cout << test << " Grade: " << test.getGrade() << std::endl;
		test.decrementGrade();
		std::cout << test << " Grade: " << test.getGrade() << std::endl;
		printTitle("Increment", 20);
		for (int i = 6; i > 0; --i)
		{
			test.incrementGrade();
			std::cout << test << " Grade: " << test.getGrade() << std::endl;
		}
	}
}

void	testExceptionLow(void)
{
	printTitle("testExceptionLow", 60);
	{
		std::cout << std::endl;
		Bureaucrat	Low("Low", 151);
	}
}

void	testExceptionHigh(void)
{
	printTitle("testExceptionHigh", 60);
	{
		std::cout << std::endl;
		Bureaucrat	High("High", 0);
	}
}


void	testDecrementGrade(void)
{
	{
		printTitle("testExceptionAfterDecrement", 60);
		Bureaucrat	downGrade("DownGrade", 149);
		std::cout << downGrade << " Grade: " 
		<< downGrade.getGrade() << std::endl;
		printTitle("Decrement", 20);
		for (int i = 6; i > 0; --i)
		{
			std::cout << downGrade << " Grade: " 
			<< downGrade.getGrade() << std::endl;
			downGrade.decrementGrade();
		}
	}
}

void	testIncrementGrade(void)
{
	{
		printTitle("testExceptionAfterIncrement", 60);
		Bureaucrat	upGrade("UpGrade", 2);
		std::cout << upGrade << " Grade: " 
		<< upGrade.getGrade() << std::endl;
		printTitle("Increment", 20);
		for (int i = 6; i > 0; --i)
		{
			std::cout << upGrade << " Grade: " 
			<< upGrade.getGrade() << std::endl;
			upGrade.incrementGrade();
		}
	}
	printTitle("------", 60);
}

void tryCatch(void (*test)(), std::ostringstream& os)
{
	try{ test();} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		os << e.what();
	}
	std::cout << std::endl;
}


int	main(int ac, char* arg[])
{
	std::ostringstream	os;
	bool				jump = false;

	if (DEBUG)
		std::cout << "ac : " << ac;
	if (ac == 2)
	{
		if (DEBUG)
			std::cout <<" | arg[1] : " << arg[1] << std::endl;
		switch (std::atoi(arg[1]))
		{
			case 1:
				tryCatch(&testBasic, os);
				break;
			case 2:
				tryCatch(&testExceptionLow, os);
				break;
			case 3:
				tryCatch(&testExceptionHigh, os);
				break;
			case 4:
				tryCatch(&testDecrementGrade, os);
				break;
			case 5:
				tryCatch(&testIncrementGrade, os);
				break;
			default:
				jump = true;
				break;
		}
	}
	if (jump || ac != 2)
	{
		tryCatch(&testBasic, os);
		tryCatch(&testExceptionLow, os);
		tryCatch(&testExceptionHigh, os);
		tryCatch(&testDecrementGrade, os);
		tryCatch(&testIncrementGrade, os);
		std::cout << std::flush;
	}
	if (!os.str().empty())
	{
		std::cerr << error("Problems during Object creation / handle\n\n", 1)
		<< os.str();

	}
	std::cout << std::endl << std::flush;
	return (0);
}