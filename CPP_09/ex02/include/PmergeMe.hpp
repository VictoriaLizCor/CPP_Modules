#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <Utils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class PmergeMe
{
	private:

	protected:
		
	public:
		PmergeMe();
		PmergeMe& operator=(PmergeMe const& rhs);
		PmergeMe(PmergeMe const& rhs);
		virtual ~PmergeMe();
};

// std::ostream& operator << (std::ostream& os, PmergeMe& rhs);

#endif // PMERGEME_HPP