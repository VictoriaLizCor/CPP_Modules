#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Utils.hpp"

// static void testShrubberyBasic()
// {
// 	printTitle("testShrubberyBasic", 60);
// 	ShrubberyCreationForm f;
// 	{
// 		std::cout << "------\n";
// 		Bureaucrat	b1("BureaucratA", 146);
		
// 		b1.signForm(f);
// 		printTitle("BureaucratIncrement", 40);
// 		b1.incrementGrade();
// 		b1.signForm(f);
// 		{
// 			std::cout << "\n";
// 			printTitle("BureaucratB", 40);
// 			Bureaucrat	b2("BureaucratB", 138);
// 			printTitle("BureaucratB_TestGrade", 40);
// 			b2.executeForm(f);
// 		}
// 		{
// 			ShrubberyCreationForm f2;
// 			Bureaucrat	b2("BureaucratB", 1);
// 			printTitle("BureaucratB_TestSign", 40);
// 			b2.executeForm(f2);
// 			printTitle("BureaucratB_Sign", 40);
// 			b2.signForm(f2);
// 			b2.executeForm(f2);
// 			std::cout << "------\n";
// 		}
// 		std::cout << "------\n";
// 	}
// 	std::cout << "\n\n";
// }

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

// void	testBureaucratExceptionLow(void)
// {
// 	printTitle("testBureaucratExceptionLow", 60);
// 	{Bureaucrat	Low("Low", 151);}
// }

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

// static void emptyBureaucrat()
// {
// 	printTitle("emptyBureaucrat", 60);
// 	{Bureaucrat	test;}
// 	std::cout << "------\n";
// 	{Bureaucrat	test("Buro", 30);}
// 	std::cout << "------\n";
// 	{Bureaucrat	test("", 2);}
// 	std::cout << "------\n";
// }


// static void emptyShrubberyForm()
// {
// 	printTitle("emptyForm", 60);
// 	{ShrubberyCreationForm	test;}
// 	std::cout << "------\n";
// 	{ShrubberyCreationForm	test("target");}
// 	std::cout << "------\n";
// 	{ShrubberyCreationForm	test("");}
// 	std::cout << "------\n";
// }

static void testExeShrubbery()
{
	{
		ShrubberyCreationForm f2("home");
		Bureaucrat	b2("BureaucratB", 1);
		std::cout << "------\n";
		printTitle("BureaucratB_TestSign", 40);
		b2.signForm(f2);
		printTitle("BureaucratB_Sign", 40);
		// for (int i = 1; i <= 3 ; ++i)
			b2.executeForm(f2);
		std::cout << "------\n";
	}
}

static void testFile()
{
	{
		nl(1);
		// Files f1("in", std::ios::in);
		// Files f2("inOut", std::ios::in | std::ios::out);
		// Files f3("out", std::ios::out);
		Files f4("test", std::ios::in);
		// std::cout << getColorStr(BGRAY, "PATH:") << "\n";
		// std::cout << " " << f.getPath("home") << std::endl;
		// std::cout << f.getPath("home") << std::endl;
		// std::cout << f.getPath("") << std::endl;
		// f.openFile();
		std::cout << "------\n";
	}
	// {
	// 	nl(1);
	// 	Files f("target");
	// 	std::cout << "------\n";
	// }
	// {
	// 	nl(1);
	// 	Files f1("target", std::ios::out);
	// 	std::cout << "------\n";
	// 	f1.openFile();
	// 	nl(1);
	// 	Files f2("target", std::ios::out);
	// 	std::cout << "------\n";
	// }
	std::cout << "------\n";
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
	else
		fill(e, *os[6]);
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
	//os[BG, BL, FH, FL, NP, FS, default] // (7)
	for (int i = 0; i < 7; ++i)
		os[i] = new std::ostringstream();
}

static void cleanOS(std::ostringstream* os[])
{
	for (int i = 0; i < 7; ++i)
		delete os[i];
}

static void runAllTest(std::ostringstream* os[])
{
	// tryCatch(&testShrubberyBasic, os);
	// tryCatch(&testManyForms, os);
	// tryCatch(&testExceptionGradeToExecute, os);
	// tryCatch(&testExceptionBureaucrat, os);
	// tryCatch(&testHighExceptionGradeSign, os);
	// tryCatch(&testLowExceptionGradeSign, os);
	// tryCatch(&testBureaucratExceptionLow, os);
	// tryCatch(&emptyShrubberyForm, os);
	tryCatch(&testExeShrubbery, os);
	// tryCatch(&testFile, os);
}

static void printExeptions(std::ostringstream* os[])
{
	bool seed = 0;

	for (int i = 0; i < 7; ++i)
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
	std::ostringstream* os[7] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };
	bool				jump = false;

	InitoOS(os);
	if (ac == 2)
	{
		int choice = std::atoi(arg[1]);
		switch (choice)
		{
		// 	case 1: tryCatch(&testShrubberyBasic, os); break;
		// 	// case 2: tryCatch(&testManyForms, os); break;
		// 	// case 3: tryCatch(&testExceptionGradeToExecute, os); break;
		// 	// case 4: tryCatch(&testExceptionBureaucrat, os); break;
		// 	// case 5: tryCatch(&testHighExceptionGradeSign, os); break;
		// 	// case 6: tryCatch(&testLowExceptionGradeSign, os); break;
		// 	case 7: tryCatch(&testBureaucratExceptionLow, os); break;
		// 	case 8: tryCatch(&emptyBureaucrat, os); break;
		// 	case 9: tryCatch(&emptyForm, os); break;
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
