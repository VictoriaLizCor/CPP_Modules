/**
 * @file main.cpp
 * @author lilizarr (lilizarr@student.42wolfsburg.de)
 * @brief
 * @version 0.1
 * @date 2024-09-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <Array.hpp>
#include "Mix.hpp"
#define MAX_VAL 5

void subject(void)
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	initSeed();
	for (int i = 0; i < MAX_VAL; ++i)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror; //
}

std::string getType(std::type_info const& type)
{
	if (type == typeid(int))
		return (getColorStr(FGREEN, "int"));
	if (type == typeid(float))
		return (getColorStr(FBLUE, "float"));
	if (type == typeid(double))
		return (getColorStr(FCYAN, "double"));
	if (type == typeid(char))
		return (getColorStr(FMAGENTA, "char"));
	if (type == typeid(std::string))
		return (getColorStr(FYELLOW, "string"));
	if (std::string(type.name()).find("MIX") != std::string::npos)
		return (getColorStr(FWHITE, "MIX"));
	return (type.name());
}

int main(void)
{
	subject();
	::runTest<int>();
	::runTest<char>();
	::runTest<std::string>();
	::runTestMIX< std::string, float >();
	::runTestMIX< char, int >();
	return (0);
}