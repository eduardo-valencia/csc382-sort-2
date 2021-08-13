#include "mergeSort.h"

template <typename Data>
void testLesserDataDoesNotExist(LinkedList<Data>& list, Node<Data>* maxNode)
{
	Node<Data>* head = list.getHead();
	Node<Data>* currentNode = head->getNext();
	if (currentNode == nullptr) return;

	Data maxData = *(maxNode->getData());
	while (currentNode != nullptr)
	{
		Data currentData = *(currentNode->getData());
		if (currentData < maxData)
		{
			throw "List is not sorted.\n";
		}
		currentNode = currentNode->getNext();
	}
}

template <typename Data>
void testListIsSorted(LinkedList<Data>& list)
{
	Node<Data>* head = list.getHead();
	Node<Data>* currentNode = head->getNext();
	while (currentNode != nullptr)
	{
		testLesserDataDoesNotExist(list, currentNode);
		currentNode = currentNode->getNext();
	}
}

void testEmptyList()
{
	LinkedList<int> list{ 0 };
	LinkedList<int> sortedList = mergeSort(list);
	testListIsSorted<int>(sortedList);
}

void runTests()
{
	testEmptyList();
}