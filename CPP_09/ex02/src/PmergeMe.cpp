#include "PmergeMe.hpp"

#if (DEBUG == 0)
/**
 * @brief Copy constructor for PmergeMeDeque.
 * 
 * This constructor creates a new PmergeMeDeque object by copying the sorted
 * member from another PmergeMeDeque object.
 * 
 * @param rhs The PmergeMeDeque object to copy from.
 */
PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque& rhs) : sorted(rhs.sorted)
{}

PmergeMeDeque& PmergeMeDeque::operator=(const PmergeMeDeque& rhs)
{
	if (this != &rhs)
	{
		sorted = rhs.sorted;
	}
	return *this;
}

/**
 * @brief Constructs a PmergeMeDeque object and initializes it with a range of elements.
 * 
 * This constructor takes two iterators, `first` and `last`, and initializes the `sorted`
 * member with the elements in the range [first, last).
 * 
 * @param first Iterator pointing to the first element in the range to be copied.
 * @param last Iterator pointing to one past the last element in the range to be copied.
 */
PmergeMeDeque::PmergeMeDeque(v_it first, v_it last):sorted(first, last)
{

}

PmergeMeDeque::~PmergeMeDeque()
{}

/**
 * @brief Calculates the threshold value for a given size.
 *
 * This function computes the largest integer `threshold` such that 
 * (threshold + 1) * (threshold + 1) is less than or equal to the given size.
 *
 * @param size The size for which the threshold is to be calculated.
 * @return The calculated threshold value.
 */
int PmergeMeDeque::threshold(int size)
{
	int threshold = 0;
	while ((threshold + 1) * (threshold + 1) <= size)
	{
		++threshold;
	}
	return threshold;
}

/**
 * @brief Sorts a portion of the deque using the insertion sort algorithm.
 *
 * This function sorts the elements in the deque from index `left` to index `right`
 * (inclusive) using the insertion sort algorithm. The insertion sort algorithm
 * is a simple sorting algorithm that builds the final sorted array one item at a time.
 * It is much less efficient on large lists than more advanced algorithms such as quicksort,
 * heapsort, or merge sort.
 *
 * @param left The starting index of the portion of the deque to be sorted.
 * @param right The ending index of the portion of the deque to be sorted.
 */
void PmergeMeDeque::insertionSort(int left, int right)
{
	int tempVal;
	for (int i = left + 1; i <= right; ++i)
	{
		tempVal = sorted[i];
		int j = i;
		while (j > left && sorted[j - 1] > tempVal)
		{
			sorted[j] = sorted[j - 1];
			if (j == 0) 
				break;
			--j;
		}
		sorted[j] = tempVal;
	}
}

/**
 * @brief Merges two consecutive sorted subranges within the deque.
 *
 * This function merges two consecutive sorted subranges [left, mid] and [mid+1, right]
 * within the deque `sorted` into a single sorted range [left, right].
 *
 * @param left The starting index of the first sorted subrange.
 * @param mid The ending index of the first sorted subrange and one less than the starting index of the second sorted subrange.
 * @param right The ending index of the second sorted subrange.
 */
void PmergeMeDeque::merge(int left, int mid, int right)
{
	d_it first = sorted.begin() + left;
	d_it middle = sorted.begin() + mid + 1;
	d_it last = sorted.begin() + right + 1;

	std::inplace_merge(first, middle, last);
}

/**
 * @brief Performs a merge-insert sort on a deque.
 *
 * This function sorts the elements in the deque between the indices
 * `left` and `right` using a combination of merge sort and insertion sort.
 * If the number of elements to be sorted is less than or equal to a certain
 * threshold, insertion sort is used. Otherwise, the function recursively
 * divides the deque into two halves, sorts each half, and then merges the
 * sorted halves.
 *
 * @param left The starting index of the range to be sorted.
 * @param right The ending index of the range to be sorted.
 */
{
	if (right - left + 1 <= threshold(sorted.size()))
	{
		insertionSort(left, right);
	}
	else
	{
		int mid = left + (right - left) / 2;
		mergeInsertSort(left, mid);
		mergeInsertSort(mid + 1, right);
		merge(left, mid, right);
	}
}

void PmergeMeVector::sort()
{
	if (!sorted.empty())
	{
		mergeInsertSort(0, sorted.size() - 1);
	}
}

#endif