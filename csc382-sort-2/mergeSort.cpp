#include "mergeSort.h"

using namespace std;

template <typename Data>
void moveNodeIntoSortedList(LinkedList<Data>& list, LinkedList<Data>& sortedItems, Node<Data>& node)
{
	sortedItems.Insert(node.data);
	list.Delete(&node);
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
	Data defaultNodeValue = leftHead->getData();
}

template <typename Data>
LinkedList<Data> mergeLists(LinkedList<Data>& leftList, LinkedList<Data>& rightList)
{
	Node<Data>* leftHead = leftList.getHead();
	Data defaultNodeValue = getDefaultValue<Data>(leftList);
	LinkedList<Data> sortedItems{ defaultNodeValue };
	Node<Data>* rightHead = rightList.getHead();

	Node<Data>* leftNode = leftHead->getNext();
	Node<Data>* rightNode = rightNode->getNext();

	while (leftNode != nullptr && rightNode != nullptr)
	{
		Data leftData = leftNode->getData();
		Data rightData = rightNode->getData();
		if (leftData < rightData)
		{
			moveNodeIntoSortedList<Data>(leftList, sortedItems, leftNode);
		}
		else
		{
			moveNodeIntoSortedList<Data>(rightList, sortedItems, rightNode);
		}
	}
	moveRemainingElements<Data>(sortedItems, leftList, rightList);
};

template <typename Data>
Node<Data>* getMiddleNode(LinkedList<Data>& list)
{
	Node<Data>* leftNode = list.getHead();
	Node<Data>* rightNode = list.getTail();
	while (leftNode != nullptr && rightNode != nullptr && leftNode != rightNode && leftNode->getNext() != nullptr && rightNode->getPrevious() != nullptr && leftNode->getNext() != rightNode)
	{
		leftNode = leftNode->getNext();
		rightNode = rightNode->getPrevious();
	}
	return leftNode;
};

template <typename Data>
bool getIfListIsSorted(LinkedList<Data>& list)
{
	Node<Data>* listHead = list.getHead();
	Node<Data>* firstNode = listHead->getNext();
	return firstNode == nullptr || firstNode->getNext() == nullptr;
}

template <typename Data>
LinkedList<Data> mergeSort(LinkedList<Data>& list)
{
	boolean isListSorted = getIfListIsSorted<Data>(list);
	if (isListSorted)
	{
		return list;
	}
	Node<Data>* middleNode = getMiddleNode<Data>(list);
	Data defaultNodeValue = getDefaultValue<Data>(list);

	LinkedList<Data> leftList{defaultNodeValue};
	// I may need to use std::move here
	leftList.head = list.head;
	leftList.tail = middleNode->getPrevious();

	LinkedList<Data> rightList{ defaultNodeValue };
	rightList.head = middleNode;
	rightList.tail = list.tail;

	LinkedList<Data> sortedLeft = mergeSort(leftList);
	LinkedList<Data> sortedRight = mergeSort(rightList);

	return mergeLists(sortedLeft, sortedRight);
};

template LinkedList<int> mergeSort(LinkedList<int>& list);