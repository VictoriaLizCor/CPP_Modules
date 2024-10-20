#ifndef RPN_HPP
# define RPN_HPP

# include <typeinfo>
# include <iostream>
# include <sstream>
# include <string>
# include <stack>
# include <stdexcept>
# include <cctype>
# include <cmath>
# include <Utils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

struct Node
{
	std::string value;
	Node* left;
	Node* right;

	Node(std::string val) : value(val), left(NULL), right(NULL) {}
};

class RPN
{
	public:
		RPN();
		RPN& operator=(RPN const& rhs);
		RPN(RPN const& rhs);
		virtual ~RPN();

		Node* buildTree(const std::string& postfix);
		float evaluate(Node* root);
		void deleteTree(Node* node);

	private:
		bool isValidToken(const std::string& token);
		bool isOperator(const std::string& token);
		float performOperation(float a, float b, const std::string& op);
		void printDebug(const std::string& message);
		std::string toString(float value);
};

// std::ostream& operator << (std::ostream& os, RPN& rhs);

#endif // RPN_HPP