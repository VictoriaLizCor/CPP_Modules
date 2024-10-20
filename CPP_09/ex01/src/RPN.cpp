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

Node* RPN::buildTree(const std::string& postfix)
{
	std::stack<Node*> stk;
	std::istringstream iss(postfix);
	std::string token;

	while (iss >> token)
	{
		if (!isValidToken(token))
			throw std::runtime_error("Error: Invalid token in expression.");

		Node* node = new Node(token);
		if (isOperator(token))
		{
			if (stk.size() < 2)
				throw std::runtime_error("Error: Invalid expression.");
			node->right = stk.top();
			stk.pop();
			node->left = stk.top();
			stk.pop();
		}
		stk.push(node);
		printDebug("Pushed node with value: " + token);
	}

	return (stk.top());
}

float RPN::evaluate(Node* root)
{
	if (!root)
	{
		return (0);
	}

	if (!isOperator(root->value))
	{
		printDebug("Returning operand: " + root->value);
		return (static_cast<float>(std::atof(root->value.c_str())));
	}

	float leftVal = evaluate(root->left);
	float rightVal = evaluate(root->right);
	float result = performOperation(leftVal, rightVal, root->value);
	printDebug("Performed operation: " + root->value + " with operands " + toStr<float>(leftVal) + " and " + toStr<float>(rightVal) + " resulting in " + toStr<float>(result));
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

void RPN::printDebug(const std::string& message)
{
	if (DEBUG)
	{
		std::cout << message << std::endl;
	}
}
