#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Utils.hpp"

static void testBasic()
{
	Form 		f("", 10, 4);
	Bureaucrat	test("Bureaucrat", 11);

	std::cout << f << std::endl;
	std::cout << test << std::endl;
	
	test.signForm(f);
	printTitle("BureaucratIncrement", 27);
	test.incrementGrade();
	test.signForm(f);
	test.signForm(f);
	std::cout << std::endl << f << std::endl;

}

static void testManyForms()
{
	Bureaucrat	test("Bureaucrat", 11);
	Form f1("Anmeldung", 10, 10);
	Form f2("Visa", 1, 3);

	std::cout << f1 << std::endl;
	std::cout << test << std::endl;
	
	test.signForm(f1);
	printTitle("BureaucratIncrement", 27);
	test.incrementGrade();
	test.signForm(f1);
	printTitle("BureaucratIncrement", 27);
	for (size_t i = 0; i <= 150; ++i)
	{
		test.incrementGrade();
		test.signForm(f2);
	}

}
static void output(std::exception const &e, std::ostringstream& os)
{
	std::cerr << e.what() << std::endl;
	os << className(typeid(e).name())<< "::" << e.what();
}

void tryCatch(void (*test)(), std::ostringstream& os)
{
	try{ test();}
	catch (Bureaucrat::GradeTooHighException const &e){output(e, os);}
	catch (Bureaucrat::GradeTooLowException const &e){output(e, os);}
	catch (Form::GradeTooHighException const &e){output(e, os);}
	catch (Form::GradeTooLowException const &e){output(e, os);}
	catch(...)
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
			default:
				jump = true;
				break;
		}
	}
	if (jump || ac != 2)
	{
		tryCatch(&testBasic, os);
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