#include "Bureaucrat.hpp"
#include "Utils.hpp"

void	testBasic(void)
{
	Bureaucrat	test("test", 6);

	std::cout << test << " Grade: " << test.getGrade() << std::endl;
	test.decrementGrade();
	std::cout << test << " Grade: " << test.getGrade() << std::endl;
	test.incrementGrade();
	test.incrementGrade();
	test.incrementGrade();
	test.incrementGrade();
	std::cout << test << " Grade: " << test.getGrade() << std::endl;
}

void	testExceptionLow(void)
{
	Bureaucrat	Low("Low", 151);
}

void	testExceptionHigh(void)
{
	Bureaucrat	High("High", 0);
}

void	testIncrementGrade(void)
{
	Bureaucrat	UpGrade("UpGrade", 2);
	UpGrade.incrementGrade();
	std::cout << UpGrade << " Grade: " << UpGrade.getGrade() << std::endl;
	UpGrade.incrementGrade();
}

void	testDecrementGrade(void)
{
	Bureaucrat	DownGrade("DownGrade", 149);
	DownGrade.decrementGrade();
	std::cout << DownGrade  << " Grade: " << DownGrade.getGrade() << std::endl;
	DownGrade.decrementGrade();
}

int main(void)
{
	std::ostringstream os;
	try{ testBasic();} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		os << e.what();
	}

	std::cout << std::endl;
	try{ testExceptionLow();} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		os << e.what();
	}

	std::cout << std::endl;
	try{ testExceptionHigh();} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		os << e.what();
	}

	std::cout << std::endl;
	try{ testDecrementGrade();} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		os << e.what();
	}

	std::cout << std::endl;
	try{ testIncrementGrade();} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		os << e.what();
	}
	if (!os.str().empty())
	{
		std::cerr << "\n" << error("Problems during Object creation\n", 1) << os.str();

	}
	return (0);
}
