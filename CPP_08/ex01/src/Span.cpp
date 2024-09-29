#include "Span.hpp"

Span::Span(unsigned int N):_N(N)
{
	if (DEBUG == 1)
		std::cout << className(typeid(*this).name()) << getColorStr(FGRAY, " was Created\n");
}

Span& Span::operator=(Span const& rhs)
{
	if( this != &rhs )
	{
		_N = rhs._N;
		_values = std::deque<int>(rhs._values);
	}
	return (*this);
}

Span::Span(Span const& rhs)
{
	*this = rhs;
}

Span::~Span(void)
{
}

void Span::addNumber(int number)
{
	if (_values.size() >= _N)
		throw std::out_of_range("Cannot add more numbers, Span is full.");
	_values.push_back(number);
}

template <typename InputIterator>
void Span::addRange(InputIterator begin, InputIterator end)
{
	if (std::distance(begin, end) + _values.size() > _N)
		throw std::out_of_range(error("Cannot add more numbers, Span full", 0));
	std::copy(begin, end, std::back_inserter(_values));
}

int Span::shortestSpan(void) const
{
	if (_values.size() < 2)
		throw std::logic_error(error("Not enough numbers to find a span.", 0));

	std::deque<int> sorted(_values);
	std::sort(sorted.begin(), sorted.end());
	if (!std::equal(_values.begin(), _values.end(), sorted.begin()))
	{
		if (DEBUG)
		{
			std::cout << getColorFmt(FGRAY) << "Sorted values:";
			std::for_each(sorted.begin(), sorted.end(), PrintFunctor(std::cout, _values));
			std::cout << C_END;
		}
	}
	nl(1);
	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		int span = sorted[i] - sorted[i - 1];
		if (span < shortest)
			shortest = span;
	}
	return (shortest);
}

int Span::longestSpan() const
{
	if (_values.size() < 2)
		throw std::logic_error(error("Not enough numbers to find a span.", 0));

	int min = *std::min_element(_values.begin(), _values.end());
	int max = *std::max_element(_values.begin(), _values.end());
	if (DEBUG)
		nl(1);
	return (max - min);
}

std::deque<int>& Span::getValues()
{
	return (_values);
}

void Span::osPrint(std::ostream& os, int const& val)
{
	os << val << " ";
}

void Span::getInfo(std::ostream& os)
{
	os << "Size: " << _values.size() << std::endl;
	if (_values.size())
	{
		os << "values: ";
		std::for_each(_values.begin(), _values.end(), PrintFunctor(os, _values));
		os << std::endl;
	}
}
Span::Fill::Fill(Span& s, size_t &max) : _s(s), _max(max)
{}

void Span::Fill::operator()(int& val) const
{
	val = getRandomVal<int>(_max);
	_s.addNumber(val);
}

Span::PrintFunctor::PrintFunctor(std::ostream& os, std::deque<int> const& s): _os(os), _span(s)
{}

void Span::PrintFunctor::operator()(int const& value) const
{
	Span::osPrint(_os, value);
}

std::ostream& operator << (std::ostream& os, Span& rhs)
{
	rhs.getInfo(os);
	return (os);
}
