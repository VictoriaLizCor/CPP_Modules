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

		void				addNumber(int num);
		template <typename InputIterator>
		void				addRange(InputIterator begin, InputIterator end);
		int					shortestSpan(void) const;
		int					longestSpan(void) const;

		std::deque<int>&	getValues();
		void				getInfo(std::ostream& os);
		struct PrintFunctor
		{
			std::ostream& _os;
			std::deque<int> const& _span;
			PrintFunctor(std::ostream& os, std::deque<int> const& s);
			void operator()(int const& value) const;
		};
		struct Fill
		{
			Span & _s;
			size_t const& _max;

			Fill(Span& s, size_t &max);
			void operator()(int& val) const;
		};
		static void		osPrint(std::ostream& os,int const& value);
	private:
		unsigned int	_N;
		// static 
		std::deque<int>	_values;
};

std::ostream& operator << (std::ostream& os, Span& rhs);

#endif // SPAN_HPP

/**
 * @NOTES: A functor, or function object, is an object that can be
 * called as if it were a function. In C++, this is achieved by
 * defining a class or struct with an `operator()` method. Functors
 * are useful for passing behavior (functions) as arguments to
 * algorithms like `std::for_each`.

    ### How to Define and Use a Functor

    1. **Define a Functor**: Create a class or struct with an
 *     `operator()` method.
    2. **Use the Functor**: Instantiate the functor and pass it to an
 *     algorithm like `std::for_each`.
 *
 */