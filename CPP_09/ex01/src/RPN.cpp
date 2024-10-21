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
	return (token == "+" || token == "-" || token == "*" || token == "/" || token == "^");
}

float RPN::performOperation(float a, float b, const std::string& op)
{
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
	if (op == "^")
		return (static_cast<float>(pow(b, a)));
	throw std::runtime_error("Error: Invalid operator.");
}

bool RPN::isValidToken(const std::string& token)
{
	if (token.size() == 1 && (std::isdigit(token[0]) || isOperator(token)))
		return (true);
	return (false);
}

static void printStack(std::stack<Node*> stk)
{
	std::cout << "Stack elements: ";
	while (!stk.empty()) {
		Node* node = stk.top();
		std::cout << node->value << " ";
		stk.pop();
	}
	std::cout << std::endl;
}


Node* RPN::buildTree(const std::string& expression)
{
	std::stack<Node*> stk;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (!isValidToken(token))
			throw std::runtime_error("Error: Invalid token in expression.");
		std::cerr << token << std::endl;
		Node* node = new Node(token);
		if (isOperator(token))
		{
			if (stk.size() < 2)
				throw std::runtime_error("Error: Invalid expression.");
			node->right = stk.top();
			node->right->parent = node;
			stk.pop();
			node->left = stk.top();
			node->left->parent = node;
			stk.pop();
		}
		stk.push(node);
		printStack(stk);
	}

	return (stk.top());
}

static Node* getRoot(Node* node)
{
	while (node->parent != NULL)
	{
		node = node->parent;
	}
	return node;
}

float RPN::evaluate(Node* root)
{
	if (!root)
		return (0);

	if (!isOperator(root->value))
		return (static_cast<float>(std::atof(root->value.c_str())));

	float leftVal = evaluate(root->left);
	float rightVal = evaluate(root->right);
	float result = performOperation(leftVal, rightVal, root->value);
	
	Node* rootNode = getRoot(root);
	deleteTree(root->left);
	deleteTree(root->right);
	root->left = NULL;
	root->right = NULL;
	root->value = toStr(result);
	printTree(rootNode);
	return (result);
}

void RPN::deleteTree(Node* node)
{
	if (node)
	{
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
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