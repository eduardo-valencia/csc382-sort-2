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
Node<Data>* getHeadOfListWithRemainingElements(LinkedList<Data>& leftList, LinkedList<Data>& rightList)
{
	if (leftList.getHead() != nullptr)
	{
		return leftList.getHead();
	}
	return rightList.getHead();
};

template <typename Data>
void moveRemainingElements(LinkedList<Data>& sortedItems, LinkedList<Data>& leftList, LinkedList<Data>& rightList)
{
	Node<Data>* headOfListWithElements = getHeadOfListWithRemainingElements(leftList, rightList);
	Node<Data>* tail = sortedItems.getTail();
	Node<Data>* lastElement = tail->getPrevious();
	// This may link to a null pointer
	lastElement->next = headOfListWithElements;
	headOfListWithElements->previous = lastElement;
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
		}
		else
		{
			moveNodeIntoSortedList<Data>(rightList, sortedItems, rightNode);
		}
		leftNode = leftHead->getNext();
		rightNode = rightHead->getNext();
	}
	moveRemainingElements<Data>(sortedItems, leftList, rightList);
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
	rightList.head = middleNode;
	rightList.head->previous = nullptr;
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