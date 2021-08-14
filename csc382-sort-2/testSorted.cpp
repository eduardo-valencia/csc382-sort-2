#include "testSorted.h"

void testGreaterDataDoesNotExist(LinkedList<int>& list, Node<int>* maxNode)
{
	Node<int>* head = list.getHead();
	Node<int>* tail = list.getTail();
	Node<int>* currentNode = head->getNext();
	if (currentNode == tail) return;

	int maxData = *(maxNode->getData());
	while (currentNode != maxNode)
	{
		int currentData = *(currentNode->getData());
		if (currentData > maxData)
		{
			cout << "List is not sorted.\n";
		}
		currentNode = currentNode->getNext();
	}
}

void testListIsSorted(LinkedList<int>& list)
{
	Node<int>* head = list.getHead();
	Node<int>* tail = list.getTail();
	Node<int>* currentNode = head->getNext();
	while (currentNode != tail)
	{
		testGreaterDataDoesNotExist(list, currentNode);
		currentNode = currentNode->getNext();
	}
}