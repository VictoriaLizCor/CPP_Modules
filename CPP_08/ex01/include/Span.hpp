#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <deque>
# include <typeinfo>
# include <limits>
# include <algorithm>
# include <Utils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Span
{
	public:
		explicit Span(unsigned int N = 0);
		Span(Span const& rhs);
		Span& operator=(Span const& rhs);
		virtual ~Span(void);

		void		addNumber(int num);
		int			shortestSpan(void) const;
		int			longestSpan(void) const;
		std::string	getInfo();

	private:
		unsigned int	_N;
		std::deque<int>	_values;
};

std::ostream& operator << (std::ostream& os, Span& rhs);

#endif // SPAN_HPP