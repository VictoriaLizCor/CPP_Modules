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
	private:
		unsigned int		_N;
		std::deque<int>		_values;
		//debug
		static u_int		_instanceCount;
		u_int				_instanceId;
		std::string const	_colorIdStr;
	public:
		explicit Span(unsigned int N = 0);
		Span(Span const& rhs);
		Span& operator=(Span const& rhs);
		virtual ~Span(void);

		void				addNumber(int num);
		template <typename InputIterator>
		void				addRange(InputIterator begin, InputIterator end);
		long int			shortestSpan(void) const;
		long int			longestSpan(void) const;

		std::deque<int>&	getValues(void);
		std::string			getName(void);
		void				getInfo(std::ostream& os);

		template <typename T>
		struct PrintFunctor
		{
			std::ostream& _os;
			T const& _span;
			PrintFunctor(std::ostream& os, T const& s);
			void operator()(int const& value) const;
		};
		static void		osPrint(std::ostream& os,int const& value);
};

template <typename T>
Span::PrintFunctor<T>::PrintFunctor(std::ostream& os, T const& s) : _os(os), _span(s) {}

template <typename T>
void Span::PrintFunctor<T>::operator()(int const& value) const
{
	size_t size = _span.size();
	if (size > 10)
	{
		static size_t limit;
		if (++limit < 5 || limit > size - 5)
			Span::osPrint(_os, value);
		if (limit == 10)
		{
			std::cout << "... ";
		}
		if (limit == size)
			limit = 0;
		else
			return ;
	}
	else
		Span::osPrint(_os, value);
}

template <typename InputIterator>
void Span::addRange(InputIterator begin, InputIterator end)
{
	size_t distance = static_cast<size_t>(std::distance(begin, end));
	if (distance + _values.size() > _N)
		throw std::out_of_range(error("Cannot add more numbers, Span full", 0));
	std::copy(begin, end, std::back_inserter(_values));
}

std::ostream& operator << (std::ostream& os, Span& rhs);

template <typename T>
struct FillFunctor
{
	size_t max;
	FillFunctor(size_t m) : max(m) {}
	T operator()() const
	{
		return getRandomVal<int>(max);
	}
	void operator()(T& value) const
	{
		value = getRandomVal<int>(max);
	}
};

#endif // SPAN_HPP

/**
 * @NOTES: A functor, or function object, is an object that can be
 * called as if it were a function. In C++, this is achieved by
 * defining a class or struct with an `operator()` method. Functors
 * are useful for passing behavior (functions) as arguments to
 * algorithms like `std::for_each`.

	### How to Define and Use a Functor

	1. **Define a Functor**: Create a class or struct with an
 *	 `operator()` method.
	2. **Use the Functor**: Instantiate the functor and pass it to an
 *	 algorithm like `std::for_each`.
 *
 */

/** 
 @NOTES: min_element, max_element
 * The expression `*std::min_element(_values.begin(), _values.end())`
   is not actually a pointer. The `std::min_element` function returns
   an iterator to the smallest element in the range `[first, last)`.
   The `*` operator is used to dereference this iterator to get the
   value of the smallest element.

 */

/**
 * @NOTES:
 * The `std::back_inserter` is used in conjunction with algorithms
   like `std::copy` to insert elements at the end of a container. It
   provides an iterator that, when assigned a value, calls the
   container's `push_back` method to add the value to the end of the
   container.

Here is why you are using `std::back_inserter` instead of
`std::push_back` directly:

### Using `std::back_inserter`
- **Convenience with Algorithms**: `std::back_inserter` is designed to
  work seamlessly with standard algorithms like `std::copy`,
  `std::transform`, etc. It allows you to use these algorithms to
  insert elements into a container without manually writing loops.
- **Iterator Interface**: `std::back_inserter` returns an iterator
  that can be used in any context where an output iterator is
  required. This makes it very flexible and powerful when working with
  algorithms

### Using `std::push_back` Directly
If you were to use `std::push_back` directly, you would need to write
a loop to iterate over the elements and push them into the destination
container. This is more verbose and less idiomatic in C++.

### Summary
- **`std::back_inserter`**: Provides a convenient way to use standard
  algorithms to insert elements into a container.
- **`std::push_back`**: Requires manual loops to insert elements,
  which is more verbose and less idiomatic.

In your case, using `std::back_inserter` with `std::copy` simplifies
the code and leverages the power of the standard library algorithms.
 * 
 * 
 */