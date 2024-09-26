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

#define CONTAINER_LIST(T) \
	CONTAINER_TYPE(std::vector<T>, 0) \
	CONTAINER_TYPE(std::deque<T>, 1) \
	CONTAINER_TYPE(std::list<T>, 2)


template <std::size_t Index, typename T>
struct RandomContainerSelector;

#define CONTAINER_TYPE(TYPE, INDEX) \
template <typename T> \
struct RandomContainerSelector<INDEX, T> { \
	typedef TYPE type; \
};

CONTAINER_LIST(int)

#undef CONTAINER_TYPE

template <typename T>
struct RandomContainer
{
	static const std::size_t containerCount = 3;
	static std::size_t containerSize;// = getRandomVal<std::size_t>(10);
	typedef typename RandomContainerSelector< 0, T>::type type;
};

template <typename T>
std::size_t  RandomContainer<T>::containerSize = getRandomVal<std::size_t>(10);


#endif // CONTAINERS_HPP