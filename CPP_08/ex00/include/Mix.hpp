#ifndef MIX_HPP
# define MIX_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <Utils.hpp>
# ifndef DEBUG
#  define DEBUG 0
# endif

template<typename T, typename U>
class MIX
{
	private:
		T	_a;
		U	_b;

	public:
		explicit MIX();
		virtual ~MIX();
		T getA() const;
		U getB() const;
};

template<typename T, typename U>
MIX<T, U>::MIX(void):
_a(getRandomVal<T>(100)), _b(getRandomVal<U>(100))
{

}

template<typename T, typename U>
MIX<T, U>::~MIX()
{
}

template<typename T, typename U>
T MIX<T, U>::getA() const
{
	return (_a);
}

template<typename T, typename U>
U MIX<T, U>::getB() const
{
	return (_b);
}

template<typename T, typename U>
std::ostream& operator << (std::ostream& os, MIX<T, U>& rhs)
{
	os << rhs.getA() << "," << rhs.getB();
	return (os);
}


#endif // MIX_HPP

