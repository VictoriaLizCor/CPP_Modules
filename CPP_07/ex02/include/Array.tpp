#ifndef ARRAY_TPP
#define ARRAY_PP

#include <Array.hpp>

#ifndef DEBUG
#define DEBUG 0
#endif

template <typename T>
u_int Array<T>::_instanceCount = 0;

template <typename T>
Array<T>::Array(u_int const &size) : _array(NULL),
									 _size(size),
									 _instanceId(++_instanceCount),
									 _colorIdStr(setObjColor(static_cast<int>(_instanceId + FGRAY)))
{
	if (_size)
		_array = new T[_size];
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
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
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
	return (*this);
}

template <typename T>
Array<T>::Array(Array<T> const &rhs) : _array(new T[rhs._size]),
									   _size(rhs._size),
									   _instanceId(++_instanceCount),
									   _colorIdStr(setObjColor(static_cast<int>(_instanceId + FGRAY)))
{
	if (_size == 0)
		_array = NULL;
	else
		_array = new T[_size];
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
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
	delete[] _array;
	_instanceCount--;
}

template <typename T>
u_int Array<T>::size(void) const
{
	return _size;
}

template <typename T>
std::string Array<T>::getInfo() const
{
	std::ostringstream os;

	if (DEBUG >= 1)
		os << _colorIdStr << _array << std::endl;
	;
	os << getColorFmt(FLWHITE);
	for (u_int i = 0; i < _size; ++i)
		os << "[" << i << "]-" << _array[i] << " ";
	if (_size)
		os << std::endl;
	os << _colorIdStr;
	os << className(typeid(*this).name());
	if (DEBUG >= 1)
		os << _instanceId;
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