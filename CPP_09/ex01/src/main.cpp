#include <iostream>
#include "RPN.hpp"
#include "Utils.hpp"

int main( int argc, char* arg[] )
{
	if( argc != 2 )
	{
		std::cout << "Usage: RPN <expression>\n";
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