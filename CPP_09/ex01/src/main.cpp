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
	Node* root = NULL;
	try
	{
		root = exprTree.buildTree(expression);
		if (DEBUG)
			std::cout << getColorStr(FGREEN, "START: ") << std::endl;
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
