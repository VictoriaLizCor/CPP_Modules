#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <Utils.hpp>
# include <limits>
# include <algorithm>
# include <stack>
# include <iterator>
# include <deque>

# ifndef DEBUG
#  define DEBUG 0
# endif

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
		//debug
		static u_int		_instanceCount;
		u_int				_instanceId;
		std::string const	_colorIdStr;

	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		explicit MutantStack(std::stack<T> const& s = std::stack<T>());
		MutantStack(MutantStack<T>const& src);
		~MutantStack();
		MutantStack<T>& operator=(MutantStack<T> const& rhs);
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		//debug
		void					clear();
		std::string				getName(std::string name);
		void					getInfo(std::ostream& os);
		std::deque<T>&			getContainer();
};


# include "MutantStack.tpp"


#endif // MUTANTSTACK_HPP