#include <algorithm>
#include <vector>
#include <iostream>

#include "mergeSort.h"

using namespace std;

class MergeSortTest
{
	LinkedList<int>* linkedList;
	vector<int> nodeData;

	// Inserts all data from nodeData into the linked list
	void insertNodeData()
	{
		vector<int>::iterator currentInt = nodeData.begin();
		for (vector<int>::iterator currentInt = nodeData.begin(); currentInt != nodeData.end(); ++currentInt)
		{
			linkedList->Insert(*currentInt);

		}
	}

	// Returns length of the linked list
	int getLength(LinkedList<int>& list)
	{
		int length = 0;
		Node<int>* currentNode = list.getHead();
		while (currentNode->getNext() != nullptr)
		{
			currentNode = currentNode->getNext();
			if (currentNode->getNext() != nullptr)
			{
				++length;
			}
		}
		return length;
	}

	void testLesserDataDoesNotExist(LinkedList<int>& list, Node<int>* maxNode)
	{
		Node<int>* head = list.getHead();
		Node<int>* currentNode = head->getNext();
		if (currentNode == nullptr) return;

		int maxData = *(maxNode->getData());
		while (currentNode != nullptr)
		{
			int currentData = *(currentNode->getData());
			if (currentData < maxData)
			{
				cout << "List is not sorted.\n";
			}
			currentNode = currentNode->getNext();
		}
	}

	void testListIsSorted(LinkedList<int>& list)
	{
		Node<int>* head = list.getHead();
		Node<int>* currentNode = head->getNext();
		while (currentNode != nullptr)
		{
			cout << *(currentNode->getData()) << endl;
			testLesserDataDoesNotExist(list, currentNode);
			currentNode = currentNode->getNext();
		}
	}

	void testLength(LinkedList<int>& list)
	{
		int length = getLength(list);
		if (length != nodeData.size())
		{
			cout << "Sorted list does not have expected length.\n";
		}
	}

public:
	// Constructor to instantiate properties
	MergeSortTest(vector<int> nodeData) : nodeData{ nodeData }
	{
		linkedList = new LinkedList<int>{ 0 };
	}

	// Destructor
	~MergeSortTest()
	{
		delete linkedList;
	}

	void runTests()
	{
		insertNodeData();
		LinkedList<int> sortedList = mergeSort(*linkedList);
		testListIsSorted(sortedList);
		testLength(sortedList);
	}
};

void testEmptyList()
{
	vector<int> nodeData{};
	MergeSortTest test{ nodeData };
	test.runTests();
}

void testListWithSingleNode()
{
	vector<int> nodeData{100};
	MergeSortTest test{ nodeData };
	test.runTests();
}

void testListWithEvenNodeNumber()
{
	vector<int> nodeData{ 2, 1 };
	MergeSortTest test{ nodeData };
	test.runTests();
}

void testListWithOddNodeNumber()
{
	vector<int> nodeData{ 3, 2, 9 };
	MergeSortTest test{ nodeData };
	test.runTests();
}

void testListWithLargerDataSet()
{
	vector<int> nodeData{ 100, 98, 383, 2923, 192, 2, 0, 0, -1, 20, 40 };
	MergeSortTest test{ nodeData };
	test.runTests();
}

void runTests()
{
	testEmptyList();
	testListWithSingleNode();
	testListWithEvenNodeNumber();
	testListWithLargerDataSet();
}