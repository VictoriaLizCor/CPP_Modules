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
	if (DEBUG > 0)
		return (token == "+" || token == "-" || token == "*" || token == "/" || token == "^");
	return (token == "+" || token == "-" || token == "*" || token == "/");
}


bool RPN::isValidToken(const std::string& token)
{
	size_t size = 1;

	if (DEBUG)
	{
		size = 2;
		size_t start = 0;
		
		if (token[0] == '+' || token[0] == '-')
			start = 1;
		size_t pos = token.find_first_not_of("0123456789", start);
		if (pos == std::string::npos || isOperator(token))
			return (true);
	}
	else if (token.size() == size && (std::isdigit(token[0]) || isOperator(token)))
		return (true);
	return (false);
}

static Node* getRoot(Node* node)
{
	while (node->parent != NULL)
	{
		node = node->parent;
	}
	return node;
}


void RPN::printStack(std::stack<Node*> stk)
{
	if (DEBUG < 2)
		return ;
	if(stk.empty())
		return ;
	std::cerr << "Stack: " << std::endl;
	while (!stk.empty())
	{
		Node* node = stk.top();
		if (DEBUG > 2)
			std::cerr << node << " ";
		std::cerr  << node->value;
		if (DEBUG > 2)
			std::cerr << std::endl;
		stk.pop();
	}
	std::cerr << std::endl;
}

void RPN::deleteStack(std::stack<Node*>& stk)
{
	while (!stk.empty())
	{
		Node* toDelete = stk.top();
		deleteTree(toDelete);
		stk.pop();
	}
}

void RPN::deleteTree(Node* toDelete)
{
	if (toDelete)
	{
		if (DEBUG > 2)
			std::cerr << "DELETING: " <<FLORANGE << toDelete << C_END << " " << toDelete->value  << std::endl;
		deleteTree(toDelete->left);
		deleteTree(toDelete->right);
		delete toDelete;
	}
}


Node* RPN::buildTree(const std::string& expression)
{
	std::stack<Node*> stk;
	std::istringstream iss(expression);
	std::string token;
	Node* node;

	while (iss >> token)
	{
		if (!isValidToken(token))
		{
			if (!stk.empty())
			{
				printStack(stk);
				deleteStack(stk);
			}
			throw std::runtime_error(error("Invalid token in expression: " + token, 0));
		}
		node = new Node(token);
		if (DEBUG == 3)
			std::cerr << "Node created: " << std::endl;
		if (isOperator(token))
		{
			if (stk.size() < 2)
			{
				stk.push(node);
				printStack(stk);
				deleteStack(stk);
				throw std::runtime_error(error("Invalid expression: Not enough elements to do operation", 0));
			}
			node->right = stk.top();
			node->right->parent = node;
			stk.pop();
			node->left = stk.top();
			node->left->parent = node;
			stk.pop();
		}
		if (DEBUG == 3)
			printTree(node);
		stk.push(node);
	}
	if (stk.size() != 1)
	{
		printStack(stk);
		deleteStack(stk);
		throw std::runtime_error(error("Invalid expression: more than one element remaing", 0));
	}
	return (stk.top());
}


float RPN::performOperation(float a, float b, const std::string& op)
{
	if (DEBUG > 1)
		std::cerr << std::endl << getColorFmt(FWHITE) << toStr(a) << op << toStr(b) << C_END << std::endl;
	if (op == "+")
		return (a + b);
	if (op == "-")
		return (a - b);
	if (op == "*")
		return (a * b);
	if (op == "/")
	{
		float result =  a / b;
		if (std::isinf(result) || std::isnan(result))
			throw std::runtime_error(error("Division by zero.", 0));
		return (result);
	}
	if (DEBUG > 0 && op == "^")
		return (static_cast<float>(pow(a, b)));
	throw std::runtime_error(error("Invalid operator.", 0));
}

float RPN::evaluate(Node* root)
{
	if (!root)
		return (0);
	if (!isOperator(root->value))
	{
		float toFloat = static_cast<float>(std::atof(root->value.c_str()));
		return (toFloat);
	}
	float leftVal = evaluate(root->left);
	float rightVal = evaluate(root->right);
	try
	{ 
		float result = performOperation(leftVal, rightVal, root->value);
	
		Node* rootNode = getRoot(root);
		deleteTree(root->left);
		deleteTree(root->right);
		root->left = root->right = NULL;
		root->value = toStr(result);
		if (DEBUG > 1 && !rootNode->left && !rootNode->right)
			std::cerr << getColorStr(FCYAN, "RESULT:")<< std::endl;
		printTree(rootNode, "", true, root);
		return (result);
	}
	catch (std::exception const &e)
	{
		Node* rootNode = getRoot(root);
		deleteTree(rootNode);
		throw std::runtime_error(e.what());
	}
}

void RPN::printTree(Node* root, std::string indent, bool last, Node* op)
{
	if (DEBUG < 2)
		return ;
	if (root != NULL)
	{
		std::cerr << indent;
		if (last)
		{
			std::cerr << "└──";
			indent += "   ";
		}
		else
		{
			std::cerr << "├──";
			indent += "|  ";
		}
		if (!isOperator(root->value))
			std::cerr << " ";
		if (root == op)
			std::cerr << getColorStr(FYELLOW, root->value);
		else
			std::cerr << root->value;
		if (DEBUG > 2)
			std::cerr << " " <<FLORANGE << root << C_END ;
		std::cerr << std::endl;
		printTree(root->left, indent, false, op);
		printTree(root->right, indent, true, op);
	}
}