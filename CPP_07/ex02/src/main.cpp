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
#include "CT.hpp"
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

std::string getType(std::string type)
{
	if (type == typeid(int).name())
		return (getColorStr(FLGREEN, "int"));
	if (type == typeid(float).name())
		return (getColorStr(FLBLUE, "float"));
	if (type == typeid(double).name())
		return (getColorStr(FLCYAN, "double"));
	if (type == typeid(char).name())
		return (getColorStr(FLMAGENTA, "char"));
	if (type == typeid(std::string).name())
		return (getColorStr(FLYELLOW, "string"));
	return (type);
}

int main(void)
{
	// subject();
	// {
	// 	Array<int> numbers(5);
	// 	numbers.init();
	// 	std::cout << numbers << std::endl;
	// 	numbers.display();
	// }
	{
		Array< CT<int, float> > numbers(5);
		// numbers.init();
		std::cout << numbers << std::endl;
		numbers.display();
	}
	// nl(1);
	// {
	// 	Array<char> numbers(5);
	// 	numbers.init();
	// 	numbers.display();
	// }
	// {
	// 	Array<char>* numbers;
	// 	printTitle("Array Pointer", 30 , '-');
	// 	numbers = new Array<char>(5);
	// 	numbers->init();
	// 	numbers->display();
	// 	delete numbers;
	// }
	// ::runTest<int>();
	// ::runTest<char>();
	// ::runTest<std::string>();
	return (0);
}