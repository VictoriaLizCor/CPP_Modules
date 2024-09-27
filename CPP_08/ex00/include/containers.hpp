#ifndef CONTAINERS_HPP
# define CONTAINERS_HPP

# include <vector>
# include <deque>
# include <list>
# include "easyfind.hpp"
# include "Utils.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

static std::string getType(std::type_info const& type);

template <typename T, int Index>
struct containerSelector;

template <typename T>
struct containerSelector<T, 0>
{
	typedef std::list<T> type;
};

template <typename T>
struct containerSelector<T, 1>
{
	typedef std::vector<T> type;
};

template <typename T>
struct containerSelector<T, 2>
{
	typedef std::deque<T> type;
};

template <typename T>
void getContainer(int index, std::list<T>& con)
{
	if (index == 0)
		con = std::list<T>();
}

template <typename T>
void getContainer(int index, std::vector<T>& con)
{
	if (index == 1)
		con = std::vector<T>();
}

template <typename T>
void getContainer(int index, std::deque<T>& con)
{
	printTitle(getType(typeid(con)), 60, '*');
	if (index == 2)
		con = std::deque<T>();
}
#endif // CONTAINERS_HPP