#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <Array.hpp>
#include "Mix.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

template <typename T>
u_int Array<T>::_instanceCount = 0;


template <typename T>
std::string	Array<T>::setColorInstance(std::type_info const& type)
{
	if (type == typeid(int))
		return (getColorShade( 1 + FGRAY));
	else if (type == typeid(float))
		return (getColorShade( 2 + FGRAY));
	else if (type == typeid(double))
		return (getColorShade( 3 + FGRAY));
	else if (type == typeid(char))
		return (getColorShade( 4 + FGRAY));
	else if (type == typeid(std::string))
		return (getColorShade( 5 + FGRAY));
	else if (std::string(type.name()).find("MIX") != std::string::npos)
		return (getColorShade( 6 + FGRAY));
	else
		return (getColorShade( 7 + FGRAY));
}

// getColorShade(FWHITE)/
template <typename T>
Array<T>::Array(u_int const &size) :
_array(NULL),
_size(size),
_instanceId(++_instanceCount),
_colorIdStr(setColorInstance(typeid(T)))
{
	if (_size)
		_array = new T[size];
	for (u_int i = 0; i < _size; ++i)
	{
		_array[i] = T();
	}
	std::cout <<  getInfo() << getColorStr(FGRAY, " was Created\n");
	if (DEBUG > 1)
		display();
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	if (this != &rhs)
	{
		if (_size)
			delete[] _array;
		_size = rhs._size;
		if (_size == 0)
			_array = NULL;
		else
		{
			_array = new T[_size];
			for (u_int i = 0; i < _size; ++i)
				_array[i] = rhs._array[i];
		}
	}
	std::cout << getInfo() << getColorStr(FGRAY, " Copy was Created\n");
	return (*this);
}

template <typename T>
Array<T>::Array(Array<T> const &rhs) :
_array(NULL),
_size(rhs._size),
_instanceId(++_instanceCount),
_colorIdStr(setColorInstance(typeid(T)))
{
	*this = rhs;
}

static void checkBounds(int index, u_int size)
{
	if (static_cast<u_int>(index) >= size)
	{
		std::ostringstream os;
		os << index << "/[0-" << (size - 1) << "] out of bounds";
		throw std::out_of_range(error(os.str(), 0));
	}
}

template <typename T>
T &Array<T>::operator[](int index)
{
	checkBounds(index, _size);
	return (_array[index]);
}

template <typename T>
const T &Array<T>::operator[](int index) const
{
	checkBounds(index, _size);
	return (_array[index]);
}

template <typename T>
Array<T>::~Array(void)
{
	if (DEBUG)
		std::cout << getInfo() << getColorStr(FGRAY, " was Destroyed\n");
	if (_size)
		delete[] _array;
	// _instanceCount--;
}

template <typename T>
u_int Array<T>::size(void) const
{
	return (_size);
}

template <typename T>
void Array<T>::getInstanceCount(void)
{
	std::cout << "Array instances: " << _instanceCount;
	nl(1);
}

template <typename T>
void Array<T>::display(void)
{
	for(u_int i = 0; i < _size; ++i)
	{
		std::cout << "(" << i << ")[" << _array[i] << "] ";
	}
	nl(1);
}

template <typename T>
void Array<T>::init(void)
{
	for(u_int i = 0; i < _size; ++i)
	{
		_array[i] = getRandomVal<T>(1000);
	}
}


template <typename T>
std::string Array<T>::getInfo() const
{
	std::ostringstream os;
	os << _colorIdStr;
	if (DEBUG >= 2)
		os << static_cast<const void*>(_array) << " ";
	os << className(std::string(typeid(*this).name()).substr(0, 12).c_str());
	os << "_" <<_instanceCount;
	os << " ";
	os << C_END;
	return (os.str());
}

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> &rhs)
{
	os << rhs.getInfo();
	return (os);
}

#endif // ARRAY_HPP