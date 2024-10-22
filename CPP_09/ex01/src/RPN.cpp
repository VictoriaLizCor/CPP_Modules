#include "RPN.hpp"

#include "RPN.hpp"
#include <cmath>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <stack>

RPN::RPN() {}

RPN::RPN(RPN const& src)
{
	*this = src;
}

RPN::~RPN() {}

RPN& RPN::operator=(RPN const& rhs)
{
	(void)rhs;
	return (*this);
}

bool RPN::isOperator(const std::string& token)
{
	if (DEBUG ==2)
		return (token == "+" || token == "-" || token == "*" || token == "/" || token == "^");
	return (token == "+" || token == "-" || token == "*" || token == "/");
}


bool RPN::isValidToken(const std::string& token)
{
	if (token.size() == 1 && (std::isdigit(token[0]) || isOperator(token)))
		return (true);
	return (false);
}

static void printStack(std::stack<Node*> stk)
{
	if (DEBUG == 0)
		return ;
	if(stk.empty())
	{
		std::cout << "Empty Stack" << std::endl;
		return ;
	}
	std::cout << "Stack elements: ";
	while (!stk.empty())
	{
		Node* node = stk.top();
		std::cout << node->value << " ";
		stk.pop();
	}
	std::cout << std::endl;
}


static Node* getRoot(Node* node)
{
	while (node->parent != NULL)
	{
		node = node->parent;
	}
	return node;
}

static void deleteStack(std::stack<Node*>& stk)
{
	while (!stk.empty())
	{
		std::cout << "DELETING " << stk.top()->value << std::endl;
		delete stk.top();
		stk.pop();
	}
	printStack(stk);
}

void RPN::deleteTree(Node* node)
{
	if (node)
	{
		std::cout << "DELETING " << node->value << std::endl;
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}


Node* RPN::buildTree(const std::string& expression)
{
	std::stack<Node*> stk;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (!isValidToken(token))
		{
			if (!stk.empty())
			{
				printStack(stk);
				std::cout << stk.size() << std::endl;
				Node* rootNode = getRoot(stk.top());
				deleteTree(rootNode);
				deleteStack(stk);
			}
			throw std::runtime_error("Error: Invalid token in expression " + error(token, 0));
		}
		std::cout << stk.size() << std::endl;
		Node* node = new Node(token);
		if (isOperator(token))
		{
			if (stk.size() < 2)
			{
				delete node;
				if (!stk.empty())
				{
					Node* rootNode = getRoot(stk.top());
					deleteTree(rootNode);
				}
				throw std::runtime_error("Error: Invalid expression.");			}
			node->right = stk.top();
			node->right->parent = node;
			stk.pop();
			node->left = stk.top();
			node->left->parent = node;
			stk.pop();
		}
		stk.push(node);
		std::cout << error("STACK", 0) << std::endl;
		// printStack(stk);
	}
	return (stk.top());
}


float RPN::performOperation(float a, float b, const std::string& op)
{
	if (DEBUG)
		std::cout  << getColorFmt(FWHITE) << toStr(a) << op << toStr(b) << C_END << std::endl;
	if (op == "+")
		return (a + b);
	if (op == "-")
		return (a - b);
	if (op == "*")
		return (a * b);
	if (op == "/")
	{
		if (a == 0)
			throw std::runtime_error("Error: Division by zero.");
		return (a / b);
	}
	if (DEBUG==2 && op == "^")
		return (static_cast<float>(pow(b, a)));
	throw std::runtime_error("Error: Invalid operator.");
}

float RPN::evaluate(Node* root)
{
	if (!root)
		return (0);

	if (!isOperator(root->value))
		return (static_cast<float>(std::atof(root->value.c_str())));

	float leftVal = evaluate(root->left);
	float rightVal = evaluate(root->right);
	try
	{ 
		float result = performOperation(leftVal, rightVal, root->value);
	
		Node* rootNode = getRoot(root);
		deleteTree(root->left);
		deleteTree(root->right);
		root->left = NULL;
		root->right = NULL;
		root->value = getColorStr(FYELLOW, toStr(result));
		if (DEBUG && !rootNode->left && !rootNode->right)
			std::cout << getColorStr(FCYAN, "RESULT:")<< std::endl;
		printTree(rootNode);
		return (result);
	}
	catch (std::exception const &e)
	{
		Node* rootNode = getRoot(root);
		deleteTree(rootNode);
		throw std::runtime_error(e.what());
	}
}

void RPN::printTree(Node* root, std::string indent, bool last)
{
	if (DEBUG == 0)
		return ;
	if (root != NULL)
	{
		std::cout << indent;
		if (last)
		{
			std::cout << "└──";
			indent += "   ";
		}
		else
		{
			std::cout << "├──";
			indent += "|  ";
		}
		if (!isOperator(root->value))
			std::cout << " ";
		std::cout << root->value << std::endl;
		printTree(root->left, indent, false);
		printTree(root->right, indent, true);
	}
}