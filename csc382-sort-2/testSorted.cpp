#include "testSorted.h"

///
/// Tests that the previous nodes are not greater than the current node, which would mean the list is not sorted.
///
template <typename Data>
void testGreaterDataDoesNotExist(LinkedList<Data> &list, Node<Data> *maxNode)
{
	Node<Data> *head = list.getHead();
	Node<Data> *tail = list.getTail();
	Node<Data> *currentNode = head->getNext();
	// In case the list is empty
	if (currentNode == tail)
		return;

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

///
/// Tests that the list is sorted.
///
template <typename Data>
void testListIsSorted(LinkedList<Data> &list)
{
	Node<Data> *head = list.getHead();
	Node<Data> *tail = list.getTail();
	Node<Data> *currentNode = head->getNext();
	while (currentNode != tail)
	{
		testGreaterDataDoesNotExist(list, currentNode);
		currentNode = currentNode->getNext();
	}
}

// Define int and string templates for testListIsSorted
template void testListIsSorted(LinkedList<int> &list);
template void testListIsSorted(LinkedList<string> &list);