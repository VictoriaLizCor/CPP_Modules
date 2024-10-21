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
	Node* parent;

	Node(std::string val) : value(val), left(NULL), right(NULL), parent(NULL) {}
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
		void printTree(Node* root, std::string indent = "", bool last = true);

	private:
		bool isValidToken(const std::string& token);
		bool isOperator(const std::string& token);
		float performOperation(float a, float b, const std::string& op);
};

// std::ostream& operator << (std::ostream& os, RPN& rhs);

#endif // RPN_HPP

/** @NOTES:
 * To print a binary tree in a structured format using C++98, you can
   use a stack to perform a depth-first traversal and print the tree
   structure.

Depth-first traversal (DFT) is a method of exploring a tree or graph
data structure. In depth-first traversal, you start at the root (or an
arbitrary node in the case of a graph) and explore as far as possible
along each branch before backtracking. There are three common types of
depth-first traversal for trees:

1. **Pre-order Traversal:**
   - Visit the root node.
   - Traverse the left subtree.
   - Traverse the right subtree.

2. **In-order Traversal:**
   - Traverse the left subtree.
   - Visit the root node.
   - Traverse the right subtree.

3. **Post-order Traversal:**
   - Traverse the left subtree.
   - Traverse the right subtree.
   - Visit the root node.

### Example

Consider the following binary tree:

```
    A
   / \
  B   C
 / \   \
D   E   F
```

#### Pre-order Traversal

The order of nodes visited in pre-order traversal is: `A, B, D, E, C,
F`.

#### In-order Traversal

The order of nodes visited in in-order traversal is: `D, B, E, A, C,
F`.

#### Post-order Traversal

The order of nodes visited in post-order traversal is: `D, E, B, F, C,
A`.


```
Pre-order Traversal: A B D E C F 
In-order Traversal: D B E A C F 
Post-order Traversal: D E B F C A 
```
*/