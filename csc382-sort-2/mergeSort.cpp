#include "mergeSort.h"

using namespace std;

template <typename Data>
void moveNodeIntoSortedList(LinkedList<Data>& list, LinkedList<Data>& sortedItems, Node<Data>* node)
{
	Data nodeData = *(node->getData());
	sortedItems.Insert(nodeData);
	list.Delete(node);
};

template <typename Data>
LinkedList<Data>& getListWithRemainingElements(LinkedList<Data>& leftList, LinkedList<Data>& rightList)
{
	if (leftList.getHead()->getNext() != leftList.getTail())
	{
		return leftList;
	}
	return rightList;
};

template <typename Data>
void moveRemainingElements(LinkedList<Data>& sortedItems, LinkedList<Data>& leftList, LinkedList<Data>& rightList)
{
	LinkedList<Data>& listWithElements = getListWithRemainingElements<Data>(leftList, rightList);

	Node<Data>* tail = sortedItems.getTail();
	Node<Data>* lastSortedElement = tail->getPrevious();
	Node <Data>* firstElementInListWithElements = listWithElements.getHead()->getNext();
	Node<Data>* lastElementInListWithElements = listWithElements.getTail()->getPrevious();

	// Links sorted list's last node with first element
	lastSortedElement->next = firstElementInListWithElements;
	firstElementInListWithElements->previous = lastSortedElement;
	// Link tail node with last element
	lastElementInListWithElements->next = tail;
	tail->previous = lastElementInListWithElements;
};

template <typename Data>
Data getDefaultValue(LinkedList<Data>& leftList)
{
	Node<Data>* leftHead = leftList.getHead();
	// Because linked list requires a default value for head and tail.
	return *(leftHead->getData());
}

template <typename Data>
LinkedList<Data> mergeLists(LinkedList<Data>& leftList, LinkedList<Data>& rightList)
{
	Node<Data>* leftHead = leftList.getHead();
	Data defaultNodeValue = getDefaultValue<Data>(leftList);
	LinkedList<Data> sortedItems{ defaultNodeValue };
	Node<Data>* rightHead = rightList.getHead();

	Node<Data>* leftNode = leftHead->getNext();
	Node<Data>* rightNode = rightHead->getNext();

	while (leftNode != leftList.getTail() && rightNode != rightList.getTail())
	{
		Data leftData = *(leftNode->getData());
		Data rightData = *(rightNode->getData());
		if (leftData < rightData)
		{
			moveNodeIntoSortedList<Data>(leftList, sortedItems, leftNode);
			leftNode = leftHead->getNext();
		}
		else
		{
			moveNodeIntoSortedList<Data>(rightList, sortedItems, rightNode);
			rightNode = rightHead->getNext();
		}
	}
	bool listHasElements = leftList.getHead()->getNext() != leftList.getTail() || rightList.getHead()->getNext() != rightList.getTail();
	if (listHasElements)
	{
		moveRemainingElements<Data>(sortedItems, leftList, rightList);
	}
	
	return sortedItems;
};

template <typename Data>
bool getIfShouldContinueLookingForMiddleNode(LinkedList<Data>& list, Node<Data>* leftNode, Node<Data>* rightNode)
{
	Node<Data>* tail = list.getTail();
	Node<Data>* head = list.getHead();
	bool cursorReachedEndOfList = (leftNode == tail || rightNode == head);
	if (cursorReachedEndOfList)
	{
		return false;
	}
	if (leftNode == rightNode)
	{
		return false;
	}
	bool nodesWillBeAtEndOfList = leftNode->getNext() == tail || rightNode->getPrevious() == head;
	if (nodesWillBeAtEndOfList)
	{
		return false;
	}
	bool nodesAreAdjacent = leftNode->getNext() == rightNode;
	return !nodesAreAdjacent;
}

template <typename Data>
Node<Data>* getMiddleNode(LinkedList<Data>& list)
{
	Node<Data>* leftNode = list.getHead();
	Node<Data>* rightNode = list.getTail();
	bool shouldContinueLookingForMiddleNode = getIfShouldContinueLookingForMiddleNode(list, leftNode, rightNode);
	while (shouldContinueLookingForMiddleNode)
	{
		leftNode = leftNode->getNext();
		rightNode = rightNode->getPrevious();
		shouldContinueLookingForMiddleNode = getIfShouldContinueLookingForMiddleNode(list, leftNode, rightNode);
	}
	return rightNode;
};

template <typename Data>
bool getIfListIsSorted(LinkedList<Data>& list)
{
	Node<Data>* listHead = list.getHead();
	Node<Data>* firstNode = listHead->getNext();
	Node<Data>* listTail = list.getTail();
	return firstNode == listTail || firstNode->getNext() == listTail;
}

template <typename Data>
LinkedList<Data> getLeftList(Data defaultNodeValue, LinkedList<Data>& list, Node<Data>* middleNode)
{
	LinkedList<Data> leftList{ defaultNodeValue };
	leftList.head = list.head;
	Node<Data>* lastNode = middleNode->getPrevious();
	lastNode->next = leftList.tail;
	leftList.tail->previous = lastNode;
	return leftList;
}

template <typename Data>
LinkedList<Data> getRightList(Data defaultNodeValue, LinkedList<Data>& list, Node<Data>* middleNode)
{
	LinkedList<Data> rightList{ defaultNodeValue };
	rightList.head->next = middleNode;
	middleNode->previous = rightList.head;
	rightList.tail = list.tail;
	return rightList;
}

template <typename Data>
LinkedList<Data> mergeSort(LinkedList<Data>& list)
{
	bool isListSorted = getIfListIsSorted<Data>(list);
	if (isListSorted)
	{
		return list;
	}
	Node<Data>* middleNode = getMiddleNode<Data>(list);
	Data defaultNodeValue = getDefaultValue<Data>(list);

	LinkedList<Data> leftList = getLeftList<Data>(defaultNodeValue, list, middleNode);
	LinkedList<Data> rightList = getRightList<Data>(defaultNodeValue, list, middleNode);

	LinkedList<Data> sortedLeft = mergeSort<Data>(leftList);
	LinkedList<Data> sortedRight = mergeSort<Data>(rightList);

	return mergeLists<Data>(sortedLeft, sortedRight);
};

template LinkedList<int> mergeSort(LinkedList<int>& list);
template LinkedList<string> mergeSort(LinkedList<string>& list);