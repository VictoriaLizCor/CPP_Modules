#include "Span.hpp"

Span::Span(unsigned int N):_N(N)
{
	if (DEBUG == 1)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
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


int Span::shortestSpan(void) const
{
	if (_values.size() < 2)
		throw std::logic_error("Not enough numbers to find a span.");

	std::deque<int> sorted(_values);
	std::sort(sorted.begin(), sorted.end());

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
		throw std::logic_error("Not enough numbers to find a span.");

	int min = *std::min_element(_values.begin(), _values.end());
	int max = *std::max_element(_values.begin(), _values.end());
	return (max - min);
}

std::string Span::getInfo()
{
	std::stringstream tmp("Values: \n");
	for (size_t i = 0 ; i < _N ; ++i )
		tmp << _values[i] << " ";
	return (tmp.str());
}

std::ostream& operator << (std::ostream& os, Span& rhs)
{
	os << rhs.getInfo();
	return (os);
}
