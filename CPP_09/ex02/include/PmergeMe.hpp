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
# include <cmath>
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
		void insertionSort(std::size_t left, std::size_t right, bool flag);
		void merge(std::size_t left, std::size_t mid, std::size_t right, bool flag);
		void mergeInsertSort(std::size_t left, std::size_t right, bool flag);

		PmergeMe(const PmergeMe& rhs);
		PmergeMe& operator=(const PmergeMe& rhs);
		T							_cpy;
		std::size_t					_threshold;
	public:
		PmergeMe(std::vector<int> const& numbers);
		~PmergeMe();
		void sort();
		T							sorted;
};

template <typename T>
PmergeMe<T>::PmergeMe(std::vector<int> const& numbers ):_threshold(threshold(numbers.size()))
{
	for(cv_it it = numbers.begin(); it != numbers.end(); ++it )
	{
		sorted.push_back(*it);
		_cpy.push_back(*it);
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
	while (static_cast<std::size_t>(std::pow(threshold + 1, 2)) <= size)
	{
		++threshold;
	}
	return (threshold);
}

template <typename T>
void PmergeMe<T>::insertionSort(std::size_t left, std::size_t right, bool flag)
{
	typename T::value_type tempVal;
	typename T::value_type toCompare = sorted[left + 1];
	for (std::size_t i = left + 1; i <= right; ++i)
	{
		tempVal = sorted[i];
		std::size_t j = i;
		while (j > left && sorted[j - 1] > tempVal)
		{
			sorted[j] = sorted[j - 1];
			if (j == 0) 
				break;
			--j;
		}
		sorted[j] = tempVal;
		if (DEBUG > 1)
			std::cerr << getColorFmt(FLCYAN) << sorted[j] << "* ";
	}
	if (DEBUG > 1)
	{
		nl(1);
		std::cerr << C_END << getColorFmt(FLWHITE);
		std::for_each(_cpy.begin(), _cpy.end(), PrintFunctor< T >(std::cerr, _cpy, _cpy.size(), toCompare));
		nl(1);
		if (flag)
			std::cerr << getColorStr(FBLUE, "INSERT: ");
		else
			std::cerr << getColorStr(FLBLUE, "INSERT: ");
		std::cerr << C_END << getColorFmt(FCYAN);
		std::for_each(sorted.begin(), sorted.end(), PrintFunctor< T >(std::cerr, sorted, sorted.size(), toCompare));
		_cpy.clear();
		std::copy(sorted.begin(), sorted.end(), std::back_inserter(_cpy));
		nl(1);
	}
}

template <typename T>
void PmergeMe<T>::merge(std::size_t left, std::size_t mid, std::size_t right, bool flag)
{
	typedef typename T::iterator ite;
	typedef typename T::difference_type diff_t;
	ite first = sorted.begin() + static_cast<diff_t>(left);
	ite middle = sorted.begin() + static_cast<diff_t>(mid) + 1;
	ite last = sorted.begin() + static_cast<diff_t>(right) + 1;

	std::inplace_merge(first, middle, last);
	if (DEBUG > 1)
	{
		if (flag)
			std::cerr << getColorStr(FRED, "MERGE: ");
		else
			std::cerr << getColorStr(FLRED, "MERGE: ");
		std::cerr << getColorFmt(FWHITE);
		std::for_each(sorted.begin(), sorted.end(), PrintFunctor< T >(std::cerr, sorted, sorted.size()));
		nl(1);
	}
}

template <typename T>
void PmergeMe<T>::mergeInsertSort(std::size_t left, std::size_t right, bool flag)
{
	if (DEBUG > 1)
	{
		std::cerr << getColorStr(FGREEN, "left: ") << left;
		std::cerr << getColorStr(FBLUE, "\t right: ") << right;
		std::cerr << getColorStr(FGRAY, "\t(right - left + 1) :") << (right - left + 1 );
		std::cerr << getColorStr(FYELLOW, "	 threshold: ") << _threshold;
		nl(1);
		if (typeid(T) == typeid(std::vector<int>))
		{
			if (flag)
				std::cerr << getColorFmt(FLMAGENTA);
			else
				std::cerr << getColorFmt(FMAGENTA);
		}
		else
		{
			if (flag)
				std::cerr << FLORANGE;
			else
				std::cerr << FORANGE;
		}
		T cpy(sorted.begin() + static_cast<typename T::difference_type>(left), sorted.begin() + static_cast<typename T::difference_type>(right + 1));
		if (cpy.size())
		{
			std::for_each(cpy.begin(), cpy.end(), PrintFunctor< T >(std::cerr, cpy, cpy.size()));
			nl(1);
		}
	}
	if (right - left + 1 <= _threshold)
	{
		std::cerr << getColorFmt(FLWHITE);
		insertionSort(left, right, flag);
	}
	else
	{
		std::size_t mid = left + (right - left) / 2;
		
		mergeInsertSort(left, mid, 0);
		mergeInsertSort(mid + 1, right, 1);
		merge(left, mid, right, flag);
	}
	std::cerr << C_END;
}

template <typename T>
void PmergeMe<T>::sort()
{
	if (!sorted.empty())
	{
		mergeInsertSort(0, sorted.size() - 1, 0);
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
@in_place_rearrangement:
In-place rearrangement refers to the process of rearranging the elements of a data structure (such as an array or list) within the original data structure itself, without requiring additional storage space proportional to the size of the data structure. This means that the rearrangement is done by modifying the original data structure directly, using only a constant amount of extra space (O(1) space complexity).

### Key Characteristics of In-Place Rearrangement

1. **No Additional Storage**: The algorithm does not use extra space proportional to the size of the input data. It may use a small, constant amount of extra space for variables or temporary storage, but this space does not grow with the size of the input.
2. **Direct Modification**: The elements of the data structure are modified directly within the original data structure. This is in contrast to algorithms that create a copy of the data structure and perform operations on the copy.
3. **Efficiency**: In-place rearrangement is often more space-efficient than algorithms that require additional storage, making it suitable for environments with limited memory.

@threshold:
Using a threshold in the Ford-Johnson algorithm (or any hybrid sorting algorithm) is necessary to determine when to switch from one sorting method to another. The threshold helps to leverage the strengths of different sorting algorithms based on the size of the data being sorted. Here’s why it is important:

1. **Efficiency for Small Arrays**: Insertion sort is very efficient for small arrays due to its low overhead. It has a time complexity of O(n^2) in the worst case, but for small datasets, the constant factors and simplicity make it faster than more complex algorithms like merge sort.

2. **Efficiency for Large Arrays**: Merge sort is more efficient for larger arrays due to its O(n log n) time complexity. However, it has higher overhead due to recursive calls and additional memory usage for merging.

3. **Combining Strengths**: By using a threshold, the algorithm can switch from insertion sort to merge sort when the array size exceeds the threshold. This combines the low overhead of insertion sort for small arrays with the efficiency of merge sort for larger arrays.

In a hybrid sorting algorithm, the threshold is a critical parameter that determines when to switch from one sorting method to another. The threshold is typically chosen based on empirical observations and performance characteristics of the sorting algorithms involved. Here are some common strategies for determining the threshold:

### 1. Empirical Testing
- **Benchmarking**: Run the hybrid algorithm on a variety of datasets with different sizes and measure the performance. Identify the size at which the simpler algorithm (e.g., insertion sort) starts to become less efficient compared to the more complex algorithm (e.g., merge sort).
- **Performance Analysis**: Analyze the time complexity and overhead of both algorithms. For example, insertion sort has a time complexity of O(n^2) but low overhead, making it efficient for small datasets. Merge sort has a time complexity of O(n log n) but higher overhead, making it more efficient for larger datasets.

### 2. Mathematical Heuristics
- **Square Root Heuristic**: A common heuristic is to use the square root of the size of the dataset as the threshold. This is based on the observation that the overhead of the more complex algorithm becomes worthwhile when the dataset size exceeds a certain point.
  ```cpp
  std::size_t threshold(std::size_t size) {
      std::size_t threshold = 0;
      while ((threshold + 1) * (threshold + 1) <= size) {
          ++threshold;
      }
      return threshold;
  }
  ```

### @in_place_optimization:

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