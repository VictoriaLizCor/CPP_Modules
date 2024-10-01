#include "Span.hpp"

u_int Span::_instanceCount = 0;
Span::Span(unsigned int N):
_N(N),
_instanceId(++_instanceCount),
_colorIdStr(getRandomColorFmt(1))
{
	if (DEBUG == 1)
		std::cout << getName() << getColorStr(FGRAY, " was Created\n");
}

Span& Span::operator=(Span const& rhs)
{
	if( this != &rhs )
	{
		_N = rhs._N;
		_values = std::deque<int>(rhs._values);
	}
	if (DEBUG == 1)
		std::cout << getName() << getColorStr(FGRAY, " copy was Created\n");
	return (*this);
}

Span::Span(Span const& rhs):
_instanceId(++_instanceCount),
_colorIdStr(getRandomColorFmt(1))
{
	*this = rhs;
}

Span::~Span(void)
{
	if (DEBUG == 1)
		std::cout << getName() << getColorStr(FGRAY, " was Destroyed\n");
}

void Span::addNumber(int number)
{
	if (_values.size() >= _N)
		throw std::out_of_range(error("Cannot add more numbers, Span is full.", 0));
	_values.push_back(number);
}


long int Span::shortestSpan(void) const
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
			std::for_each(sorted.begin(), sorted.end(), PrintFunctor< std::deque<int> >(std::cout, _values));
			std::cout << C_END;
		}
	}
	nl(1);
	long int shortest = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		long int span = sorted[i] - sorted[i - 1];
		if (span < shortest)
			shortest = span;
	}
	return (shortest);
}

long int Span::longestSpan() const
{
	if (_values.size() < 2)
		throw std::logic_error(error("Not enough numbers to find a span.", 0));

	long int min = *std::min_element(_values.begin(), _values.end());
	long int max = *std::max_element(_values.begin(), _values.end());
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

std::string Span::getName(void)
{
	std::ostringstream os;

	os << _colorIdStr;
	if (DEBUG >= 1)
		os << className(typeid(*this).name()) << _instanceId;
	else 
		os << className(typeid(*this).name());
	os << C_END;

	return (os.str());
}

void Span::getInfo(std::ostream& os)
{
	os << getName() << " size: " << _values.size() << std::endl;
	if (_values.size())
	{
		os << "values: ";
		std::for_each(_values.begin(), _values.end(), PrintFunctor< std::deque<int> >(os, _values));
		os << std::endl;
	}
}

std::ostream& operator << (std::ostream& os, Span& rhs)
{
	rhs.getInfo(os);
	return (os);
}

