#include "RPN.hpp"

#include "RPN.hpp"
#include <cmath>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <stack>

RPN::RPN() {}

/**
 * @brief Copy constructor for the RPN class.
 *
 * This constructor creates a new instance of the RPN class by copying
 * the state of an existing instance.
 *
 * @param src The source RPN object to copy from.
 */
RPN::RPN(RPN const& src)
{
	*this = src;
}

RPN::~RPN() {}

/**
 * @brief Assignment operator overload for the RPN class.
 *
 * This operator overload allows for the assignment of one RPN object
 * to another. It currently does nothing with the right-hand side
 * (rhs) object and simply returns the left-hand side (this) object.
 *
 * @param rhs The right-hand side RPN object to be assigned.
 * @return RPN& A reference to the left-hand side RPN object.
 */
RPN& RPN::operator=(RPN const& rhs)
{
	(void)rhs;
	return (*this);
}

/**
 * @brief Checks if a given token is a valid operator.
 *
 * This function determines if the provided token is one of the valid
 * operators used in Reverse Polish Notation (RPN). The valid
 * operators are "+", "-", "*", and "/". If debugging is enabled
 * (DEBUG > 0), the "^" operator is also considered valid.
 *
 * @param token The token to check.
 * @return true if the token is a valid operator, false otherwise.
 */
bool RPN::isOperator(const std::string& token)
{
	if (DEBUG > 0)
		return (token == "+" || token == "-" || token == "*" || token == "/" || token == "^");
	return (token == "+" || token == "-" || token == "*" || token == "/");
}


/**
 * @brief Validates if a given token is a valid RPN (Reverse Polish
 * Notation) token.
 *
 * This function checks if the provided token is a valid number or
 * operator for RPN calculations. The validation process differs based
 * on the DEBUG flag:
 * - If DEBUG is enabled, the function allows for tokens that are
 *   either valid numbers (including decimals) or operators.
 * - If DEBUG is disabled, the function only allows single-character
 *   tokens that are either digits or operators.
 *
 * @param token The token to be validated.
 * @return true if the token is valid, false otherwise.
 */
bool RPN::isValidToken(const std::string& token)
{
	size_t size = 1;

	if (DEBUG)
	{
		size = 2;
		size_t start = 0;
		
		if (token[0] == '+' || token[0] == '-')
			start = 1;
		size_t pos = token.find_first_not_of(".0123456789", start);
		if (std::count(token.begin(), token.end(), '.') > 1)
			return (false);
		if (pos == std::string::npos || isOperator(token))
			return (true);
	}
	else if (token.size() == size && (std::isdigit(token[0]) || isOperator(token)))
		return (true);
	return (false);
}

/**
 * @brief Retrieves the root node of a given node in a tree structure.
 *
 * This function traverses up the tree from the given node until it
 * reaches the root node, which is identified by having a NULL parent.
 *
 * @param node A pointer to the starting node from which to find the
 * root.
 * @return A pointer to the root node of the tree.
 */
static Node* getRoot(Node* node)
{
	while (node->parent != NULL)
	{
		node = node->parent;
	}
	return node;
}


/**
 * @brief Prints the contents of a stack of Node pointers.
 *
 * This function prints the contents of the provided stack of Node
 * pointers to the standard error stream. The level of detail in the
 * output depends on the value of the DEBUG macro:
 * - If DEBUG < 2, the function returns immediately without printing
 *   anything.
 * - If DEBUG >= 2, the function prints the stack contents.
 * - If DEBUG > 2, the function prints additional details about each
 *   node.
 *
 * @param stk The stack of Node pointers to be printed.
 */
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

/**
 * @brief Deletes all nodes in the given stack.
 *
 * This function iterates through the stack and deletes each node by
 * calling the deleteTree function on the node at the top of the
 * stack. It continues this process until the stack is empty.
 *
 * @param stk A reference to a stack of Node pointers that need to be
 * deleted.
 */
void RPN::deleteStack(std::stack<Node*>& stk)
{
	while (!stk.empty())
	{
		Node* toDelete = stk.top();
		deleteTree(toDelete);
		stk.pop();
	}
}

/**
 * @brief Recursively deletes a binary tree.
 *
 * This function deletes all nodes in a binary tree starting from the
 * given node. It performs a post-order traversal to ensure that child
 * nodes are deleted before their parent node.
 *
 * @param toDelete Pointer to the root node of the tree/subtree to be
 * deleted.
 */
void RPN::deleteTree(Node* toDelete)
{
	if (toDelete)
	{
		if (DEBUG > 2)
			std::cerr << "*DELETING: " <<FLORANGE << toDelete << C_END << " " << toDelete->value  << std::endl;
		deleteTree(toDelete->left);
		deleteTree(toDelete->right);
		delete toDelete;
	}
}

void RPN::errorHandler(std::stack<Node*>& stk, Node* node, std::string const& msg)
{
	if (node)
		stk.push(node);
	printStack(stk);
	deleteStack(stk);
	throw std::runtime_error(error(msg, 0));
}

static void fillNode(std::stack<Node*>& stk, Node* node)
{
	node->right = stk.top();
	node->right->parent = node;
	stk.pop();
	node->left = stk.top();
	node->left->parent = node;
	stk.pop();
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
				errorHandler(stk, NULL, "Invalid token in expression: " + token);
			throw std::runtime_error(error("Invalid token in expression: " + token, 0));
		}
		node = new Node(token);
		if (DEBUG == 3)
			std::cerr << "Node created: " << std::endl;
		if (isOperator(token))
		{
			if (stk.size() < 2)
				errorHandler(stk, node, "Invalid expression: Not enough elements to do operation");
			fillNode(stk, node);
		}
		if (DEBUG == 3)
			printTree(node);
		stk.push(node);
	}
	if (stk.size() != 1)
		errorHandler(stk, NULL, "Invalid expression: more than one element remaing");
	return (stk.top());
}

static float strToFloat(std::string const& strValue)
{
	char* end;
	float value = std::strtof(strValue.c_str(), &end);

	if (*end != '\0' && ((*end != 'f' && *end != 'F') || *(end + 1) != '\0'))
		throw std::invalid_argument(error("Invalid Value input: " + strValue, 0));
	return (value);
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
	try
	{ 
		if (!isOperator(root->value))
		{
			float toFloat = strToFloat(root->value);
			return (toFloat);
		}
		float leftVal = evaluate(root->left);
		float rightVal = evaluate(root->right);
		float result = performOperation(leftVal, rightVal, root->value);
	
		Node* rootNode = getRoot(root);
		deleteTree(root->left);
		deleteTree(root->right);
		root->left = root->right = NULL;
		root->value = toStr(result);
		if (DEBUG > 1 && rootNode && !rootNode->left && !rootNode->right)
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
		if (op && root == op)
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