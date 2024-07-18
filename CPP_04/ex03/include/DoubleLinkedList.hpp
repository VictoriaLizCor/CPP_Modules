#ifndef DOUBLELINKEDLIST_HPP
# define DOUBLELINKEDLIST_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif


template<typename T>
class DoubleLinkedList
{
	private:
		struct Node
		{
			T		dataPtr;
			Node*	prev;
			Node*	next;

			Node() : dataPtr(0), prev(0), next(0) {}
		};
		Node* head;
		Node* tail;

	public:
		DoubleLinkedList();
		~DoubleLinkedList();

		void addNode(T data);
		bool deleteNode(T data);
		void clearList(T data);
		void print() const;
};
template<typename T>
DoubleLinkedList<T>::DoubleLinkedList():head(0), tail(0)
{}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	// clearList();
	std::cout<< getColorStr(FGRAY, "Empty list\n");
}

template<typename T>
void DoubleLinkedList<T>::addNode(T data)
{
	Node* newNode = new Node();
	newNode->dataPtr = data;
	if (!head)
		head = tail = newNode;
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

template <typename T>
bool DoubleLinkedList<T>::deleteNode(T data)
{
	Node* tmp = head;
	Node* prev = NULL;

	if (tmp == NULL)
		return (false);
	print();
	while (tmp != NULL)
	{
		if (tmp->dataPtr == data)
		{
			if (prev == NULL)
			{
				head = tmp->next;
				if (head != NULL)
					head->prev = NULL;
			}
			else
			{
				prev->next = tmp->next;
				if (tmp->next != NULL)
					tmp->next->prev = prev;
			}
			if (tmp == tail)
				tail = prev;
			delete tmp;
			print();
			return (true);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (false);
}

template<typename T>
void DoubleLinkedList<T>::clearList(T data)
{
	Node* tmp = head;
	while (tmp)
	{
		Node* next = tmp->next;
		if (tmp->dataPtr != data)
			delete tmp->dataPtr;
		delete tmp;
		tmp = next;
	}
	head = tail = 0;
}

template<typename T>
void DoubleLinkedList<T>::print() const
{
	Node* tmp = head;
	size_t		i=0;
	std::cout << getColorFmt(FRED) << "\n[LIST] : ";
	std::cout  << C_END;
	while (tmp)
	{
		std::cout << (++i)<< " " << *(tmp->dataPtr);
		tmp = tmp->next;
		if (tmp)
			std::cout << getColorStr(FRED," -> ");
	}
	std::cout << "\n" << std::endl;
}

// std::ostream& operator << (std::ostream& os, DoubleLinkedList const& rhs);

#endif // DOUBLELINKEDLIST_HPP
