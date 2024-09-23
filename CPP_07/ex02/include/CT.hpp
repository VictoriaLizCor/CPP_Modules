#ifndef CT_HPP
# define CT_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <Utils.hpp>
# ifndef DEBUG
#  define DEBUG 0
# endif

template<typename T, typename U>
class CT
{
	private:
		T	_a;
		U	_b;

	public:
		explicit CT();
		virtual ~CT();
		T getA() const;
		U getB() const;
};

template<typename T, typename U>
CT<T, U>::CT(void):
_a(getRandomVal<T>(100)), _b(getRandomVal<U>(100))
{

}

template<typename T, typename U>
CT<T, U>::~CT()
{
}

template<typename T, typename U>
T CT<T, U>::getA() const
{
	return (_a);
}

template<typename T, typename U>
U CT<T, U>::getB() const
{
	return (_b);
}

template<typename T, typename U>
std::ostream& operator << (std::ostream& os, CT<T, U>& rhs)
{
	os << rhs.getA() << "," << rhs.getB();
	return (os);
}



#endif // CT_HPP

