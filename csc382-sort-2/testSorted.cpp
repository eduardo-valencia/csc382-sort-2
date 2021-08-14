#include "testSorted.h"

template <typename Data>
void testGreaterDataDoesNotExist(LinkedList<Data>& list, Node<Data>* maxNode)
{
	Node<Data>* head = list.getHead();
	Node<Data>* tail = list.getTail();
	Node<Data>* currentNode = head->getNext();
	if (currentNode == tail) return;

	Data maxData = *(maxNode->getData());
	while (currentNode != maxNode)
	{
		Data currentData = *(currentNode->getData());
		if (currentData > maxData)
		{
			cout << "List is not sorted.\n";
		}
		currentNode = currentNode->getNext();
	}
}

template <typename Data>
void testListIsSorted(LinkedList<Data>& list)
{
	Node<Data>* head = list.getHead();
	Node<Data>* tail = list.getTail();
	Node<Data>* currentNode = head->getNext();
	while (currentNode != tail)
	{
		testGreaterDataDoesNotExist(list, currentNode);
		currentNode = currentNode->getNext();
	}
}

template void testListIsSorted(LinkedList<int>& list);
template void testListIsSorted(LinkedList<string>& list);