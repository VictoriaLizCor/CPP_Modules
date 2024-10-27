#include <iostream>
#include "RPN.hpp"
#include "Utils.hpp"

/**
 * @file main.cpp
 * @brief Entry point for the RPN (Reverse Polish Notation) expression evaluator.
 *
 * This program takes a single command-line argument representing an RPN expression,
 * builds an expression tree, evaluates it, and prints the result.
 *
 * Usage: RPN "<expression>"
 *
 * @param argc Number of command-line arguments.
 * @param arg Array of command-line arguments.
 * @return int Exit status of the program.
 *         - 0 on success.
 *         - 1 on error (e.g., incorrect usage or evaluation error).
 */
int main( int argc, char* arg[] )
{
	if( argc != 2 )
	{
		std::cerr << error("Usage: RPN \"<expression>\"", 0) << std::endl;
		return (1);
	}
	std::string expression = arg[1];
	RPN exprTree;
	try
	{
		Node* root = exprTree.buildTree(expression);
		if (DEBUG > 1)
			std::cerr << std::endl << getColorStr(FGREEN, "START: ");
		if (DEBUG > 2)
			std::cerr << root;
		std::cerr << std::endl;
		exprTree.printTree(root);
		float result = exprTree.evaluate(root);
		std::cout << result << std::endl;
		exprTree.deleteTree(root);
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return (0);
}

/**
 * @brief reference
 * https://paodayag.dev/reverse-polish-notation-js-parser/ 
 * 
 * not so good:
 * https://www.rpn-calc.com/
 * https://www.dcode.fr/reverse-polish-notation 
 */