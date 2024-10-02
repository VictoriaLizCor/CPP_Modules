#include "MutantStack.hpp"

template <typename T>
u_int MutantStack<T>::_instanceCount = 0;


template <typename T>
std::ostream& operator << (std::ostream& os, MutantStack<T>& rhs)
{
	rhs.getInfo(os);
	return (os);
}

template <typename T>
MutantStack<T>::MutantStack(std::stack<T> const& s) :
std::stack<T>(s),
_instanceId(++_instanceCount),
_colorIdStr(getRandomColorFmt(1))
{
	if (DEBUG == 1)
		std::cout << getName() << getColorStr(FGRAY, " was Created\n");
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const& rhs) :
std::stack<T>(rhs),
_instanceId(++_instanceCount),
_colorIdStr(getRandomColorFmt(1))
{
	*this = rhs;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> const& rhs)
{
	if (this != &rhs)
		std::stack<T>::operator=(rhs);
	if (DEBUG == 1)
		std::cout << getName() << getColorStr(FGRAY, " copy was Created\n");
	return(*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	if (DEBUG == 1)
		std::cout << getName() << getColorStr(FGRAY, " was Destroyed\n");
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return(std::stack<T>::c.begin());
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const
{
	return(std::stack<T>::c.begin());
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return(std::stack<T>::c.end());
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end() const
{
	return(std::stack<T>::c.end());
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin()
{
	return(std::stack<T>::c.rbegin());
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return(std::stack<T>::c.rbegin());
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend()
{
	return(std::stack<T>::c.rend());
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rend() const
{
	return(std::stack<T>::c.rend());
}

template <typename T>
void MutantStack<T>::clear()
{
	std::stack<T>::c.clear();
}

template <typename T>
std::string MutantStack<T>::getName(void)
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


template <typename T>
void MutantStack<T>::getInfo(std::ostream& os)
{
	os << getName() << " size: " << this->size() << std::endl;
	if (this->size())
	{
		os << "values: ";
		std::for_each(this->begin(), this->end(), PrintFunctor< MutantStack<T> >(os, *this));
		os << std::endl;
	}
}
