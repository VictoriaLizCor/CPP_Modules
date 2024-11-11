#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <algorithm>
# include <deque>
# include <vector>
# include <typeinfo>
# include "Utils.hpp"

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
		void mergeInsertSort(int left, int right);


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
	for(cv_it it = numbers.begin(); it != numbers.end(); ++it )
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
	return (threshold);
}

template <typename T>
void PmergeMe<T>::insertionSort(std::size_t left, std::size_t right)
{
	typename T::value_type tempVal;
	for (std::size_t i = left + 1; i <= right; ++i)
	{
		tempVal = sorted[i];
		std::size_t j = i - 1;
		while (j >= left && sorted[j] > tempVal)
		{
			sorted[j + 1] = sorted[j];
			if (j == 0) 
				break;
			--j;
		}
		sorted[j + 1] = tempVal;
		std::cerr << getColorFmt(FLCYAN) << tempVal << "*";
	}
	std::for_each(sorted.begin(), sorted.end(), PrintFunctor< T >(std::cerr, sorted, sorted.size()));
	nl(1);
	// for (typename T::iterator it = sorted.begin(); it != sorted.end(); ++it)
	// {
	// 	if (*it == tempVal)
	// 		std::cerr << *it << "* ";
	// 	else
	// 		std::cerr << *it << " ";
	// }
	// std::cerr << std::endl;1

}

template <typename T>
void PmergeMe<T>::merge(std::size_t left, std::size_t mid, std::size_t right)
{
	typename T::iterator first = sorted.begin() + static_cast<typename T::difference_type>(left);
	typename T::iterator middle = sorted.begin() + static_cast<typename T::difference_type>(mid) + 1;
	typename T::iterator last = sorted.begin() + static_cast<typename T::difference_type>(right) + 1;

	std::inplace_merge(first, middle, last);
	std::for_each(sorted.begin(), sorted.end(), PrintFunctor< T >(std::cerr, sorted, sorted.size()));
	nl(1);
}

template <typename T>
void PmergeMe<T>::mergeInsertSort(std::size_t left, std::size_t right)
{
	if (DEBUG > 1)
	{
		std::cerr << getColorStr(FGREEN, "left: ") << left;
		std::cerr << getColorStr(FBLUE, "\t right: ") << right;
		std::cerr << getColorStr(FGRAY, "\t(right - left + 1) :") << (right - left + 1);
		std::cerr << getColorStr(FYELLOW, "	 threshold: ") << threshold(right - left + 1);
		nl(1);
		if (typeid(T) == typeid(std::vector<int>))
		{
			std::cerr << getColorFmt(FLMAGENTA);
		}
		else
			std::cerr << FLORANGE;
		T cpy(sorted.begin() + static_cast<typename T::difference_type>(left), sorted.begin() + static_cast<typename T::difference_type>(right));
		if (cpy.size())
		{
			std::for_each(cpy.begin(), cpy.end(), PrintFunctor< T >(std::cerr, cpy, cpy.size()));
			nl(1);
		}
	}
	if (right - left + 1 <= threshold(right - left + 1))
	{
		std::cerr << getColorFmt(FLWHITE);
		insertionSort(left, right);
	}
	else
	{
		std::size_t mid = left + (right - left) / 2;
		mergeInsertSort(left, mid);
		mergeInsertSort(mid + 1, right);
		std::cerr << getColorFmt(FWHITE);
		merge(left, mid, right);
	}
	std::cerr << C_END;
}

template <typename T>
void PmergeMe<T>::sort()
{
	if (!sorted.empty())
	{
		mergeInsertSort(0, sorted.size() - 1);
		std::cerr << getColorFmt(FGRAY);
		std::for_each(sorted.begin(), sorted.end(), PrintFunctor< T >(std::cerr, sorted, sorted.size()));
		std::cerr << C_END;
		nl(1);
	}
}
#endif
#endif // PMERGEME_HPP


/**
 * @NOTES: 
 * The `std::inplace_merge` function in C++ is part of the Standard
   Library and is used to merge two consecutive sorted ranges within a
   container into a single sorted range. The algorithm behind
   `std::inplace_merge` is essentially a combination of the merge step
   of the merge sort algorithm and in-place rearrangement of elements.

### Logic Behind `std::inplace_merge`

1. **Input**:
   - Two consecutive sorted ranges within a container.
   - The first range is `[first, middle)`.
   - The second range is `[middle, last)`.

2. **Output**:
   - A single sorted range `[first, last)` that contains all the
     elements from the two input ranges.

### Steps of the Algorithm

1. **Initialization**:
   - Identify the two ranges to be merged: `[first, middle)` and
     `[middle, last)`.

2. **Merge Process**:
   - Compare the elements from the two ranges and rearrange them in
     place to form a single sorted range.
   - Use a temporary buffer if necessary to facilitate the in-place
     merging.

3. **In-Place Rearrangement**:
   - The algorithm tries to minimize the use of additional memory by
     rearranging elements within the container itself.
   - It may use techniques like block swapping or rotation to achieve
     this.

### Detailed Steps

1. **Identify the Ranges**:

2. **Compare and Merge**:
   - Initialize two pointers, one for each range.
   - Compare the elements pointed to by these pointers.
   - Place the smaller element in the correct position in the merged
     range.
   - Move the pointer forward in the range from which the smaller
     element was taken.

3. **Handle Remaining Elements**:
   - If one of the ranges is exhausted, move the remaining elements
     from the other range to the merged range.

### Example

Consider merging two sorted ranges within a vector:

```cpp
std::vector<int> vec = {1, 3, 5, 2, 4, 6};
std::vector<int>::iterator first = vec.begin();
std::vector<int>::iterator middle = vec.begin() + 3;
std::vector<int>::iterator last = vec.end();

std::inplace_merge(first, middle, last);
```

### Visualization

1. **Initial State**:
   - First range: `[1, 3, 5]`
   - Second range: `[2, 4, 6]`

2. **Merge Process**:
   - Compare `1` and `2`: `1` is smaller, place `1` in the merged
     range.
   - Compare `3` and `2`: `2` is smaller, place `2` in the merged
     range.
   - Compare `3` and `4`: `3` is smaller, place `3` in the merged
     range.
   - Compare `5` and `4`: `4` is smaller, place `4` in the merged
     range.
   - Compare `5` and `6`: `5` is smaller, place `5` in the merged
     range.
   - Place the remaining element `6` in the merged range.

3. **Final State**:
   - Merged range: `[1, 2, 3, 4, 5, 6]`

### Pseudocode

Here is a simplified pseudocode for the `std::inplace_merge`
algorithm:

```
function inplace_merge(first, middle, last):
    buffer = []
    left = first
    right = middle

    while left < middle and right < last:
        if *left <= *right:
            buffer.append(*left)
            left += 1
        else:
            buffer.append(*right)
            right += 1

    while left < middle:
        buffer.append(*left)
        left += 1

    while right < last:
        buffer.append(*right)
        right += 1

    for i in range(len(buffer)):
        first[i] = buffer[i]
```

### In-Place Optimization

The actual implementation of `std::inplace_merge` in the Standard
Library is more complex and optimized to minimize the use of
additional memory. It may use techniques like:

- **Block Swapping**: Swapping blocks of elements to their correct
  positions.
- **Rotation**: Rotating elements within the container to achieve the
  desired order.

These optimizations help achieve the merging in place with minimal
additional memory usage.

### Conclusion

The `std::inplace_merge` function is a powerful tool for merging two
consecutive sorted ranges within a container into a single sorted
range. It combines the logic of the merge step of merge sort with
in-place rearrangement techniques to achieve efficient merging with
minimal additional memory usage.
 * 
 */