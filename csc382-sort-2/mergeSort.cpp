#include "mergeSort.h"

using namespace std;

// Moves a node from one linked list to another by inserting the node data, then deleting the old node.
template <typename Data>
void moveNodeIntoSortedList(LinkedList<Data> &list, LinkedList<Data> &sortedItems, Node<Data> *node)
{
	Data nodeData = *(node->getData());
	sortedItems.Insert(nodeData);
	list.Delete(node);
};

// Returns the list with remaining elements
template <typename Data>
LinkedList<Data> &getListWithRemainingElements(LinkedList<Data> &leftList, LinkedList<Data> &rightList)
{
	if (leftList.getHead()->getNext() != leftList.getTail())
	{
		return leftList;
	}
	return rightList;
};

// Gets the list that still has nodes, then moves its nodes into the sorted list.
// Assumes there is only 1 list with nodes.
template <typename Data>
void moveRemainingElements(LinkedList<Data> &sortedItems, LinkedList<Data> &leftList, LinkedList<Data> &rightList)
{
	LinkedList<Data> &listWithElements = getListWithRemainingElements<Data>(leftList, rightList);

	Node<Data> *tail = sortedItems.getTail();
	Node<Data> *lastSortedElement = tail->getPrevious();
	Node<Data> *firstElementInListWithElements = listWithElements.getHead()->getNext();
	Node<Data> *lastElementInListWithElements = listWithElements.getTail()->getPrevious();

	// Links sorted list's last node with first element
	lastSortedElement->next = firstElementInListWithElements;
	firstElementInListWithElements->previous = lastSortedElement;
	// Link tail node with last element
	lastElementInListWithElements->next = tail;
	tail->previous = lastElementInListWithElements;
};

// Gets the default value used for the head and tail's value.
template <typename Data>
Data getDefaultValue(LinkedList<Data> &leftList)
{
	Node<Data> *leftHead = leftList.getHead();
	// Because linked list requires a default value for head and tail.
	return *(leftHead->getData());
}

/// Merges and sorts two lists together.
/// \return Sorted linked list
///
template <typename Data>
LinkedList<Data> mergeLists(LinkedList<Data> &leftList, LinkedList<Data> &rightList)
{
	Node<Data> *leftHead = leftList.getHead();
	Data defaultNodeValue = getDefaultValue<Data>(leftList);
	LinkedList<Data> sortedItems{defaultNodeValue};
	Node<Data> *rightHead = rightList.getHead();

	Node<Data> *leftNode = leftHead->getNext();
	Node<Data> *rightNode = rightHead->getNext();

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

// Returns a boolean indicating whether the left and right cursors point to the middle node.
template <typename Data>
bool getIfShouldContinueLookingForMiddleNode(LinkedList<Data> &list, Node<Data> *leftNode, Node<Data> *rightNode)
{
	Node<Data> *tail = list.getTail();
	Node<Data> *head = list.getHead();
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

/// Returns the middle node
/// Assumes the list has a minimum length of 2.
/// \return the middle node
///
template <typename Data>
Node<Data> *getMiddleNode(LinkedList<Data> &list)
{
	Node<Data> *leftNode = list.getHead();
	Node<Data> *rightNode = list.getTail();
	bool shouldContinueLookingForMiddleNode = getIfShouldContinueLookingForMiddleNode(list, leftNode, rightNode);
	while (shouldContinueLookingForMiddleNode)
	{
		leftNode = leftNode->getNext();
		rightNode = rightNode->getPrevious();
		shouldContinueLookingForMiddleNode = getIfShouldContinueLookingForMiddleNode(list, leftNode, rightNode);
	}
	return rightNode;
};

// Returns whether the list's length is either 0 or 1, meaning the list is already sorted.
template <typename Data>
bool getIfListIsSorted(LinkedList<Data> &list)
{
	Node<Data> *listHead = list.getHead();
	Node<Data> *firstNode = listHead->getNext();
	Node<Data> *listTail = list.getTail();
	return firstNode == listTail || firstNode->getNext() == listTail;
}

/// Returns the left half of the list
/// \returns linked list
///
template <typename Data>
LinkedList<Data> getLeftList(Data defaultNodeValue, LinkedList<Data> &list, Node<Data> *middleNode)
{
	LinkedList<Data> leftList{defaultNodeValue};
	leftList.head = list.head;
	Node<Data> *lastNode = middleNode->getPrevious();
	// Updates the pointers
	lastNode->next = leftList.tail;
	leftList.tail->previous = lastNode;
	return leftList;
}

/// Returns the right half of the list
/// \returns linked list
///
template <typename Data>
LinkedList<Data> getRightList(Data defaultNodeValue, LinkedList<Data> &list, Node<Data> *middleNode)
{
	LinkedList<Data> rightList{defaultNodeValue};
	// Updates the pointers
	rightList.head->next = middleNode;
	middleNode->previous = rightList.head;
	rightList.tail = list.tail;
	return rightList;
}

///
/// Sorts a linked list by merging and sorting recursively.
/// \fn LinkedList<Data> mergeSort(LinkedList<Data> &list)
/// @param list the list to sort. May mutate the list.
/// \returns linked list
///
template <typename Data>
LinkedList<Data> mergeSort(LinkedList<Data> &list)
{
	bool isListSorted = getIfListIsSorted<Data>(list);
	if (isListSorted)
	{
		return list;
	}
	// Gets middle node to split list in half
	Node<Data> *middleNode = getMiddleNode<Data>(list);
	Data defaultNodeValue = getDefaultValue<Data>(list);

	// Splits list into left and right half.
	LinkedList<Data> leftList = getLeftList<Data>(defaultNodeValue, list, middleNode);
	LinkedList<Data> rightList = getRightList<Data>(defaultNodeValue, list, middleNode);

	// Sorts the halves recursively.
	LinkedList<Data> sortedLeft = mergeSort<Data>(leftList);
	LinkedList<Data> sortedRight = mergeSort<Data>(rightList);

	// Returns the merged lists.
	return mergeLists<Data>(sortedLeft, sortedRight);
};

// Explicitly creates int and string templates for mergeSort
template LinkedList<int> mergeSort(LinkedList<int> &list);
template LinkedList<string> mergeSort(LinkedList<string> &list);