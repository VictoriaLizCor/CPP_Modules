#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Utils.hpp"

static void testBasic()
{
	printTitle("testBasic", 60);
	{
		ShrubberyCreationForm f;
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

// static void testManyForms()
// {
// 	printTitle("testManyForms", 60);
// 	{
// 		Bureaucrat	test("Bureaucrat", 6);
// 		AForm f1("Anmeldung", 6, 10);
// 		AForm f2("Visa", 2, 5);
// 		std::cout << "------\n";
// 		test.signForm(f1);
// 		std:: cout << "\n";
// 		printTitle("BureaucratIncrement", 27);
// 		while (test.getGrade() > f2.getMinimumGradeToSign())
// 		{
// 			test.incrementGrade();
// 			test.signForm(f2);
// 		}
// 		std::cout << "------\n";
// 	}
// 	std::cout << "\n\n";
// }

void	testBureaucratExceptionLow(void)
{
	printTitle("testBureaucratExceptionLow", 60);
	{Bureaucrat	Low("Low", 151);}
}

// static void testExceptionGradeToExecute()
// {
// 	printTitle("testExceptionGradeToExecute", 60);
// 	{AForm f2("", 51, 50);}
// }

// static void testLowExceptionGradeSign()
// {
// 	printTitle("testLowExceptionGradeSign", 60);
// 	{AForm f2("", 150, 151);}
// }

// static void testHighExceptionGradeSign()
// {
// 	printTitle("testHighExceptionGradeSign", 60);
// 	{AForm f2("", 0, 150);}
// }

// static void testExceptionBureaucrat() //4
// {
// 	printTitle("testExceptionBureaucrat", 60);
// 	{
// 		Bureaucrat	test("Bureaucrat", 6);
// 		AForm f2("Visa", 2, 5);
// 		std::cout << "------\n";
// 		test.signForm(f2);
// 		std:: cout << "\n";
// 		printTitle("BureaucratIncrement", 27);
// 		while (test.getGrade() >= f2.getMinimumGradeToSign())
// 		{
// 			test.incrementGrade();
// 			test.signForm(f2);
// 			test.incrementGrade();
// 		}
// 		std::cout << "------\n";
// 	}
// 	std::cout << "\n\n";
// }

static void emptyBureaucrat()
{
	printTitle("emptyBureaucrat", 60);
	{Bureaucrat	test;}
	{Bureaucrat	test("Buro", 30);}
	{Bureaucrat	test("", 2);}
}


static void emptyForm()
{
	printTitle("emptyForm", 60);
	{ShrubberyCreationForm	test;}
	{ShrubberyCreationForm	test("target");}
	{ShrubberyCreationForm	test("");}
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
	if (typeid(e) == typeid(Bureaucrat::GradeTooHighException))
		fill(e, *os[0]);
	else if (typeid(e) == typeid(Bureaucrat::GradeTooLowException))
		fill(e, *os[1]);
	else if (typeid(e) == typeid(AForm::GradeTooHighException))
		fill(e, *os[2]);
	else if (typeid(e) == typeid(AForm::GradeTooLowException))
		fill(e, *os[3]);
	else if (typeid(e) == typeid(AForm::NoPrivilege))
		fill(e, *os[4]);
	else if (typeid(e) == typeid(AForm::FormStatus))
		fill(e, *os[5]);
}

void tryCatch(void (*test)(), std::ostringstream* os[])
{
	try{ test();}
	catch (std::exception  const &e){orderException(e, os);}
	catch(...) // ...
	{
		std::cerr << error("Problems during what() message formatting\n", 1);
	}
}

static void InitoOS(std::ostringstream* os[])
{
	//os[BG, BL, FH, FL, NP, FS] // (6)
	for (int i = 0; i < 6; ++i)
		os[i] = new std::ostringstream();
}

static void cleanOS(std::ostringstream* os[])
{
	for (int i = 0; i < 6; ++i)
		delete os[i];
}

static void runAllTest(std::ostringstream* os[])
{
	tryCatch(&testBasic, os);
	// tryCatch(&testManyForms, os);
	// tryCatch(&testExceptionGradeToExecute, os);
	// tryCatch(&testExceptionBureaucrat, os);
	// tryCatch(&testHighExceptionGradeSign, os);
	// tryCatch(&testLowExceptionGradeSign, os);
	tryCatch(&testBureaucratExceptionLow, os);
	tryCatch(&emptyForm, os);
}

static void printExeptions(std::ostringstream* os[6])
{
	bool seed = 0;

	for (int i = 0; i < 6; ++i)
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
	std::ostringstream* os[6] = { NULL, NULL, NULL, NULL, NULL, NULL };
	bool				jump = false;

	InitoOS(os);
	if (ac == 2)
	{
		int choice = std::atoi(arg[1]);
		switch (choice)
		{
			case 1: tryCatch(&testBasic, os); break;
			// case 2: tryCatch(&testManyForms, os); break;
			// case 3: tryCatch(&testExceptionGradeToExecute, os); break;
			// case 4: tryCatch(&testExceptionBureaucrat, os); break;
			// case 5: tryCatch(&testHighExceptionGradeSign, os); break;
			// case 6: tryCatch(&testLowExceptionGradeSign, os); break;
			case 7: tryCatch(&testBureaucratExceptionLow, os); break;
			case 8: tryCatch(&emptyBureaucrat, os); break;
			case 9: tryCatch(&emptyForm, os); break;
			default: jump = true; break;
		}
	}
	if (jump || ac != 2)
		runAllTest(os);
	printExeptions(os);
	std::cout << std::endl << std::flush;
	std::cerr << std::flush;
	cleanOS(os);
	return (0);
}
