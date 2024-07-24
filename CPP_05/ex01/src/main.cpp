#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Utils.hpp"

static void testBasic()
{
	printTitle("testBasic", 60);
	{
		Form 		f("", 10, 10);
		Bureaucrat	test("Bureaucrat", 11);

		std::cout << "------\n";
		
		test.signForm(f);
		printTitle("BureaucratIncrement", 40);
		test.incrementGrade();

		test.signForm(f);
		test.signForm(f);
		std::cout << "------\n";
	}
	std::cout << "\n\n";
}

static void testManyForms()
{
	printTitle("testManyForms", 60);
	{
		Bureaucrat	test("Bureaucrat", 6);
		Form f1("Anmeldung", 6, 10);
		Form f2("Visa", 2, 5);
		std::cout << "------\n";
		test.signForm(f1);
		std:: cout << "\n";
		printTitle("BureaucratIncrement", 27);
		while (test.getGrade() > f2.getMinimumGradeToSign())
		{
			test.incrementGrade();
			test.signForm(f2);
		}
		std::cout << "------\n";
	}
	std::cout << "\n\n";
}

void	testBureaucratExceptionLow(void)
{
	printTitle("testBureaucratExceptionLow", 60);
	{
		std::cout << std::endl;
		Bureaucrat	Low("Low", 151);
	}
}

static void testExceptionGradeToExecute()
{
	printTitle("testExceptionGradeToExecute", 60);
	{
		Form f2("", 51, 50);
	}
}

static void testLowExceptionGradeSign()
{
	printTitle("testLowExceptionGradeSign", 60);
	{
		Form f2("", 151, 151);
	}
}

static void testHighExceptionGradeSign()
{
	printTitle("testHighExceptionGradeSign", 60);
	{
		Form f2("", 0, 150);
	}
}

static void testExceptionBureaucrat()
{
	printTitle("testExceptionBureaucrat", 60);
	{
		Bureaucrat	test("Bureaucrat", 6);
		Form f2("Visa", 2, 5);
		std::cout << "------\n";
		test.signForm(f2);
		std:: cout << "\n";
		printTitle("BureaucratIncrement", 27);
		while (test.getGrade() >= f2.getMinimumGradeToSign())
		{
			test.incrementGrade();
			test.signForm(f2);
			test.incrementGrade();
		}
		std::cout << "------\n";
	}
	std::cout << "\n\n";
}

static void fill(std::exception const &e, std::ostringstream& os)
{
	if (os.str().empty())
		os << demangle(typeid(e).name()) << ": \n";
	os << e.what();
}

static void orderException(std::exception const &e, std::ostringstream& os)
{
	static std::ostringstream BH;
	static std::ostringstream BL;
	static std::ostringstream FH;
	static std::ostringstream FL;

	std::cerr << e.what() << std::endl;
	if (typeid(e) == typeid(Bureaucrat::GradeTooHighException))
		fill(e, BH);
	else if (typeid(e) == typeid(Bureaucrat::GradeTooLowException))
		fill(e, BL);
	else if (typeid(e) == typeid(Form::GradeTooHighException))
		fill(e, FH);
	else if (typeid(e) == typeid(Form::GradeTooLowException))
		fill(e, FL);
	os.str("");
	os << BH.str() << "\n"
	<< BL.str() << "\n"
	<< FH.str() << "\n"
	<< FL.str() << "\n";
}


void tryCatch(void (*test)(), std::ostringstream& os)
{
	try{ test();}
	catch (std::exception  const &e){orderException(e, os);}
	catch(...) // ...
	{
		std::cerr << error("Problems during what() message formatting\n", 1);
		std::cout << std::endl;
	}
}


int	main(int ac, char* arg[])
{
	std::ostringstream	os;
	bool				jump = false;

	if (ac == 2)
	{
		switch (std::atoi(arg[1]))
		{
			case 1:
				tryCatch(&testBasic, os);
				break;
			case 2:
				tryCatch(&testManyForms, os);
				break;
			case 3:
				tryCatch(&testExceptionGradeToExecute, os);
				break;
			case 4:
				tryCatch(&testExceptionBureaucrat, os);
				break;
			case 5:
				tryCatch(&testHighExceptionGradeSign, os);
				break;
			case 6:
				tryCatch(&testLowExceptionGradeSign, os);
				break;
			case 7:
				tryCatch(&testBureaucratExceptionLow, os);
				break;
			default:
				jump = true;
				break;
		}
	}
	if (jump || ac != 2)
	{
		tryCatch(&testBasic, os);
		tryCatch(&testManyForms, os);
		tryCatch(&testExceptionGradeToExecute, os);
		tryCatch(&testExceptionBureaucrat, os);
		tryCatch(&testHighExceptionGradeSign, os);
		tryCatch(&testLowExceptionGradeSign, os);
		tryCatch(&testBureaucratExceptionLow, os);
	}
	if (!os.str().empty())
	{
		printTitle("MAIN REPORT", 60);
		std::cerr << "\n" << error("Problems during Object creation / handle\n\n", 1)
		<< os.str();

	}
	std::cout << std::endl << std::flush;
	std::cerr << std::flush;
	return (0);
}