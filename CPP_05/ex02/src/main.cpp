#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Utils.hpp"

static void testShrubberyBasic()
{
	printTitle("testShrubberyBasic", 60);
	ShrubberyCreationForm f;
	{
		std::cout << "------\n";
		Bureaucrat	b1("BureaucratA", 146);
		
		b1.signForm(f);
		printTitle("BureaucratIncrement", 40);
		b1.incrementGrade();
		b1.signForm(f);
		{
			std::cout << "\n";
			printTitle("BureaucratB", 40);
			Bureaucrat	b2("BureaucratB", 138);
			printTitle("BureaucratB_TestGrade", 40);
			b2.executeForm(f);
		}
		{
			ShrubberyCreationForm f2;
			Bureaucrat	b2("BureaucratB", 1);
			printTitle("BureaucratB_TestSign", 40);
			b2.executeForm(f2);
			printTitle("BureaucratB_Sign", 40);
			b2.signForm(f2);
			b2.executeForm(f2);
			std::cout << "------\n";
		}
		std::cout << "------\n";
	}
	std::cout << "\n\n";
}

void	testBureaucratExceptionLow(void)
{
	printTitle("testBureaucratExceptionLow", 60);
	{Bureaucrat	Low("Low", 151);}
}

void	testBureaucratExceptionHigh(void)
{
	printTitle("testBureaucratExceptionHigh", 60);
	{Bureaucrat	High("High", 0);}
}

static void testExceptionBureaucrat() //4
{
	printTitle("testExceptionBureaucrat", 60);
	{
		Bureaucrat	test("Bureaucrat", 6);
		PresidentialPardonForm f2("Trillian");
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

static void emptyBureaucrat()
{
	printTitle("emptyBureaucrat", 60);
	{Bureaucrat	test;}
	std::cout << "------\n";
	{Bureaucrat	test("Buro", 30);}
	std::cout << "------\n";
	{Bureaucrat	test("", 2);}
	std::cout << "------\n";
}


static void emptyShrubberyForm()
{
	printTitle("emptyForm", 60);
	{ShrubberyCreationForm	test;}
	std::cout << "------\n";
	{ShrubberyCreationForm	test("target");}
	std::cout << "------\n";
	{ShrubberyCreationForm	test("");}
	std::cout << "------\n";
}

static void testExeShrubbery()
{
	printTitle("testExeShrubbery START", 60);
	{
		ShrubberyCreationForm f1("home");
		Bureaucrat	b1("BureaucratB", 1);
		std::cout << "------\n";
		printTitle("BureaucratB_TestSign", 40);
		for (int i = 1; i <= 3 ; ++i)
			b1.signForm(f1);
		printTitle("BureaucratB_EXECUTE", 40);
		for (int i = 1; i <= 3 ; ++i)
			b1.executeForm(f1);
		std::cout << "------\n";
	}
	printTitle("testExeShrubbery DONE", 60);
	nl(2);
	printTitle("testExeShrubbery2 START", 60);
	{
		ShrubberyCreationForm f1("home");
		Bureaucrat	b1("BureaucratB", 1);
		std::cout << "------\n";
		printTitle("BureaucratB_TestExecuteBeforeSign", 40);
		b1.executeForm(f1);
		b1.signForm(f1);
		b1.executeForm(f1);
		std::cout << "------\n";
	}
	printTitle("testExeShrubbery2 DONE", 60);
}

static void testExeRobotomy()
{
	printTitle("testExeRobotomy1 START", 60);
	{
		RobotomyRequestForm f1("Roboto");
		Bureaucrat	b1("BureaucratB", 1);
		std::cout << "------\n";
		printTitle("BureaucratB_TestSign", 40);
		for (int i = 1; i <= 3 ; ++i)
			b1.signForm(f1);
		printTitle("BureaucratB_EXECUTE", 40);
		for (int i = 1; i <= 3 ; ++i)
			b1.executeForm(f1);
		std::cout << "------\n";
	}
	printTitle("testExeRobotomy1 DONE", 60);
	nl(2);
	printTitle("testExeRobotomy2 START", 60);
	{
		RobotomyRequestForm f1("Roboto");
		Bureaucrat	b1("BureaucratB", 73);
		std::cout << "------\n";
		printTitle("BureaucratB_TestExecuteBeforeSign", 40);
		b1.executeForm(f1);
		b1.signForm(f1);
		b1.executeForm(f1);
		std::cout << "------\n";
	}
	printTitle("testExeRobotomy2 DONE", 60);
	nl(2);
	printTitle("testExeRobotomy3 START", 60);
	{
		RobotomyRequestForm f1("Roboto");
		Bureaucrat	b1("BureaucratB", 46);
		std::cout << "------\n";
		printTitle("BureaucratB_TestExecuteBeforeSign", 40);
		b1.executeForm(f1);
		b1.signForm(f1);
		b1.executeForm(f1);
		std::cout << "------\n";
	}
	printTitle("testExeRobotomy3 DONE", 60);
}

static void testExePresi()
{
	printTitle("testExePresi START", 60);
	{
		PresidentialPardonForm f1("Trillian");
		Bureaucrat	b1("BureaucratB", 6);
		std::cout << "------\n";
		printTitle("BureaucratB_TestSign", 40);
		b1.executeForm(f1);
		for (int i = 1; i <= 3 ; ++i)
			b1.signForm(f1);
		printTitle("BureaucratB_EXECUTE", 40);
		b1.executeForm(f1);
		printTitle("BureaucratIncrement", 27);
		b1.incrementGrade();
		for (int i = 1; i <= 3 ; ++i)
			b1.executeForm(f1);
		std::cout << "------\n";
	}
	printTitle("testExePresi DONE", 60);
}
static void testFile()
{
	{
		nl(1);
		Files f1("in", std::ios::in);
		Files f2("inOut", std::ios::in | std::ios::out);
		Files f3("out", std::ios::out);
		Files f4("test", std::ios::in);
		std::cout << getColorStr(BGRAY, "PATH:") << "\n";
		std::cout << f1.getPath("home") << std::endl;
		std::cout << f2.getPath("") << std::endl;
		f1.openFile();
		std::cout << "------\n";
	}
	{
		nl(1);
		Files f("target");
		std::cout << "------\n";
	}
	{
		nl(1);
		Files f1("target", std::ios::out);
		std::cout << "------\n";
		f1.openFile();
		nl(1);
		Files f2("target", std::ios::out);
		std::cout << "------\n";
	}
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
	catch(...)
	{
		std::cerr << error("Problems during what() message formatting\n", 1);
	}
}

static void InitoOS(std::ostringstream* os[])
{
	//os[BG, BL, FH, FL, NP, FS, default] (7)
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
	tryCatch(&testShrubberyBasic, os);
	tryCatch(&testExceptionBureaucrat, os);
	tryCatch(&testBureaucratExceptionLow, os);
	tryCatch(&testBureaucratExceptionHigh, os);
	tryCatch(&emptyShrubberyForm, os);
	tryCatch(&testExeShrubbery, os);
	tryCatch(&testExeRobotomy, os);
	tryCatch(&testExePresi, os);
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
			case 1: tryCatch(&testShrubberyBasic, os); break;
			case 2: tryCatch(&testExceptionBureaucrat, os); break;
			case 3: tryCatch(&testBureaucratExceptionLow, os); break;
			case 4: tryCatch(&testBureaucratExceptionHigh, os); break; 
			case 5: tryCatch(&emptyBureaucrat, os); break;
			case 6: tryCatch(&testExeShrubbery, os); break;
			case 7: tryCatch(&testExeRobotomy, os); break;
			case 8: tryCatch(&testExePresi, os); break;
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
