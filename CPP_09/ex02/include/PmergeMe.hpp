#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <Utils.hpp>
#include <algorithm>
#include <deque>
#include <vector>


# ifndef DEBUG
#  define DEBUG 0
# endif

typedef std::deque<int>::iterator d_it;
typedef std::vector<int>::iterator v_it;
typedef std::vector<int>::const_iterator cv_it;

#if (DEBUG == 0)
class PmergeMeDeque
{
	private:
		std::deque<int> sorted;
		int threshold(int size);
		void insertionSort(int left, int right);
		void merge(int left, int mid, int right);
		void mergeInsertSort(int left, int right);

		PmergeMeDeque(const PmergeMeDeque& rhs);
		PmergeMeDeque& operator=(const PmergeMeDeque& rhs);
	public:
		PmergeMeDeque(v_it first, v_it last);
		~PmergeMeDeque();
		void sort();

};


class PmergeMeVector
{
	private:

		int threshold(int size);
		void insertionSort(int left, int right);
		void merge(int left, int mid, int right);
		void mergeInsertSort(int left
		, int right);


		PmergeMeVector(const PmergeMeVector& rhs);
		PmergeMeVector& operator=(const PmergeMeVector& rhs);
	public:
		PmergeMeVector(std::vector<int> const& v);
		virtual ~PmergeMeVector();

		void sort();
		std::vector<int> sorted;
};
#else

template <typename T>
class PmergeMe
{
	private:
		
		typedef typename T::const_iterator ite;

		std::size_t threshold(std::size_t size);
		void insertionSort(std::size_t left, std::size_t right);
		void merge(std::size_t left, std::size_t mid, std::size_t right);
		void mergeInsertSort(std::size_t left, std::size_t right);

		PmergeMe(const PmergeMe& rhs);
		PmergeMe& operator=(const PmergeMe& rhs);
	public:
		PmergeMe(std::vector<int> const& numbers);
		~PmergeMe();
		void sort();
		T							sorted;
};

template <typename T>
PmergeMe<T>::PmergeMe(std::vector<int> const& numbers )
{
	for( cv_it it = numbers.begin(); it != numbers.end(); ++it )
	{
		sorted.push_back(*it);
	}
}
template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
PmergeMe<T>& PmergeMe<T>::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
	{
		sorted = rhs.sorted;
	}
	return *this;
}
template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& rhs) : sorted(rhs.sorted) {}

template <typename T>
std::size_t PmergeMe<T>::threshold(std::size_t size)
{
	std::size_t threshold = 0;
	while ((threshold + 1) * (threshold + 1) <= size)
	{
		++threshold;
	}
	return threshold;
}

template <typename T>
void PmergeMe<T>::insertionSort(std::size_t left, std::size_t right)
{
	for (std::size_t i = left + 1; i <= right; ++i)
	{
		typename T::value_type tempVal = sorted[i];
		std::size_t j = i - 1;
		while (j >= left && sorted[j] > tempVal)
		{
			sorted[j + 1] = sorted[j];
			if (j == 0) break; // Prevent underflow
			--j;
		}
		sorted[j + 1] = tempVal;
	}
}

template <typename T>
void PmergeMe<T>::merge(std::size_t left, std::size_t mid, std::size_t right)
{
	 typename T::iterator first = sorted.begin() + static_cast<typename T::difference_type>(left);
	typename T::iterator middle = sorted.begin() + static_cast<typename T::difference_type>(mid) + 1;
	typename T::iterator last = sorted.begin() + static_cast<typename T::difference_type>(right) + 1;

	std::inplace_merge(first, middle, last);
}

template <typename T>
void PmergeMe<T>::mergeInsertSort(std::size_t left, std::size_t right)
{
	if (right - left + 1 <= threshold(right - left + 1))
	{
		insertionSort(left, right);
	}
	else
	{
		std::size_t mid = left + (right - left) / 2;
		mergeInsertSort(left, mid);
		mergeInsertSort(mid + 1, right);
		merge(left, mid, right);
	}
}

template <typename T>
void PmergeMe<T>::sort()
{
	if (!sorted.empty())
	{
		mergeInsertSort(0, sorted.size() - 1);
	}
}
#endif
#endif // PMERGEME_HPP