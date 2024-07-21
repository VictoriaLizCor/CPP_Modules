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
		test.incrementGrade();
		test.incrementGrade();
		test.incrementGrade();
		test.incrementGrade();
		std::cout << test << " Grade: " << test.getGrade() << std::endl;
	}
	printTitle("------", 30);
}

void	testExceptionLow(void)
{
	printTitle("testExceptionLow", 60);
	{
		std::cout << std::endl;
		Bureaucrat	Low("Low", 151);
	}
	printTitle("------", 60);
	
}

void	testExceptionHigh(void)
{
	printTitle("testExceptionHigh", 60);
	{
		std::cout << std::endl;
		Bureaucrat	High("High", 0);
	}
	printTitle("------", 60);
}

void	testIncrementGrade(void)
{
	{
		printTitle("testtExceptionAfterIncrement", 60);
		Bureaucrat	UpGrade("UpGrade", 2);
		UpGrade.incrementGrade();
		std::cout << UpGrade << " Grade: " 
		<< UpGrade.getGrade() << std::endl;
		UpGrade.incrementGrade();
	}
	printTitle("------", 60);
}

void	testDecrementGrade(void)
{
	{
		printTitle("testtExceptionAfterDecrement", 60);
		Bureaucrat	DownGrade("DownGrade", 149);
		DownGrade.decrementGrade();
		std::cout << DownGrade  << " Grade: " << DownGrade.getGrade() << std::endl;
		DownGrade.decrementGrade();
	}
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
	else
		jump = true;
	if (jump)
	{
		tryCatch(&testBasic, os);
		tryCatch(&testExceptionLow, os);
		tryCatch(&testExceptionHigh, os);
		tryCatch(&testDecrementGrade, os);
		tryCatch(&testIncrementGrade, os);
		std::cout << std::endl << std::flush;
	}
	if (!os.str().empty())
	{
		std::cerr << "\n" << error("Problems during Object creation\n", 1) << os.str();

	}
	std::cout << std::endl << std::flush;
	return (0);
}