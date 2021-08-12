#include "mergeSort.h"

template <typename Data>
void testLesserDataDoesNotExist(LinkedList<Data>& list)
{
	Node<Data>* head = list.getHead();
	Node<Data>* currentNode = head->getNext();
	while (currentNode != nullptr)
	{

	}
}