#include "PmergeMe.hpp"

#if (DEBUG == 0)
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

PmergeMeDeque::PmergeMeDeque(v_it first, v_it last):sorted(first, last)
{

}

PmergeMeDeque::~PmergeMeDeque()
{}

int PmergeMeDeque::threshold(int size)
{
	int threshold = 0;
	while ((threshold + 1) * (threshold + 1) <= size)
	{
		++threshold;
	}
	return threshold;
}

void PmergeMeDeque::insertionSort(int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int tempVal = sorted[i];
		int j = i - 1;
		while (j >= left && sorted[j] > tempVal)
		{
			sorted[j + 1] = sorted[j];
			--j;
		}
		sorted[j + 1] = tempVal;
	}
}

void PmergeMeDeque::merge(int left, int mid, int right)
{
	d_it first = sorted.begin() + left;
	d_it middle = sorted.begin() + mid + 1;
	d_it last = sorted.begin() + right + 1;

	std::inplace_merge(first, middle, last);
}

void PmergeMeDeque::mergeInsertSort(int left, int right)
{
	if (right - left + 1 <= threshold(right - left + 1))
	{
		insertionSort(left, right);
	} else
	{
		int mid = left + (right - left) / 2;
		mergeInsertSort(left, mid);
		mergeInsertSort(mid + 1, right);
		merge(left, mid, right);
	}
}

void PmergeMeDeque::sort()
{
	if (!sorted.empty())
	{
		mergeInsertSort(0, sorted.size() - 1);
	}
}

//---------------------------------------------------------

PmergeMeVector::PmergeMeVector(std::vector<int> const& v):sorted(v)
{}

PmergeMeVector::PmergeMeVector(const PmergeMeVector& rhs) : sorted(rhs.sorted)
{}

PmergeMeVector& PmergeMeVector::operator=(const PmergeMeVector& rhs)
{
	if (this != &rhs)
	{
		sorted = rhs.sorted;
	}
	return *this;
}

PmergeMeVector::~PmergeMeVector()
{}

int PmergeMeVector::threshold(int size)
{
	int threshold = 0;
	while ((threshold + 1) * (threshold + 1) <= size)
	{
		++threshold;
	}
	return threshold;
}

void PmergeMeVector::insertionSort(int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int tempVal = sorted[i];
		int j = i - 1;
		while (j >= left && sorted[j] > tempVal)
		{
			sorted[j + 1] = sorted[j];
			--j;
		}
		sorted[j + 1] = tempVal;
	}
}

void PmergeMeVector::merge(int left, int mid, int right)
{
	v_it first = sorted.begin() + left;
	v_it middle = sorted.begin() + mid + 1;
	v_it last = sorted.begin() + right + 1;

	std::inplace_merge(first, middle, last);
}

void PmergeMeVector::mergeInsertSort(int left, int right)
{
	if (right - left + 1 <= threshold(right - left + 1))
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