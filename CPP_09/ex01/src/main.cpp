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
	std::string postfix = arg[1];
	RPN exprTree;

	try
	{
		Node* root = exprTree.buildTree(postfix);
		float result = exprTree.evaluate(root);
		std::cout << "The result is: " << result << std::endl;
		exprTree.deleteTree(root);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return (0);
}
