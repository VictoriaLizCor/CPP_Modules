#include "Bureaucrat.hpp"
#include "Utils.hpp"

void	testBasic(void)
{
	Bureaucrat	bob("bob", 6);

	std::cout << bob << std::endl;
	bob.downGrade();
	std::cout << bob << std::endl;
	bob.upGrade();
	bob.upGrade();
	bob.upGrade();
	bob.upGrade();
	std::cout << bob << std::endl;
}

void	testExceptionLow(void)
{
	Bureaucrat	bob("Low", 151);
}

void	testExceptionHigh(void)
{
	Bureaucrat	bob("High", 0);
}

void	testUpGrade(void)
{
	Bureaucrat	bob("UpGrade", 2);
	bob.upGrade();
	std::cout << bob << std::endl;
	bob.upGrade();
}

void	testDownGrade(void)
{
	Bureaucrat	bob("DownGrade", 149);
	bob.downGrade();
	std::cout << bob << std::endl;
	bob.downGrade();
}

int main(void)
{
	bool eFlag = 0;
	try{ testBasic();} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		eFlag = 1;
	}

	std::cout << std::endl;
	try{ testExceptionLow();} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		eFlag = 1;
	}

	std::cout << std::endl;
	try{ testExceptionHigh();} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		eFlag = 1;
	}

	std::cout << std::endl;
	try{ testDownGrade();} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		eFlag = 1;
	}

	std::cout << std::endl;
	try{ testUpGrade();} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		eFlag = 1;
	}
	if (eFlag)
		std::cerr << "\n" << error("A problem happened during Object creation\n", 0);
	return (eFlag ?  1 : 0);
}
