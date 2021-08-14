#include <time.h>
#include <iostream>

#include "mergeSort.h"

using namespace std;

const size_t ARRAY_SIZE = 1000;

void insertNumbers(int numbers[], int arraySize, LinkedList<int>& linkedList)
{
	for (int numberIndex = 0; numberIndex < arraySize; ++numberIndex)
	{
		int number = numbers[numberIndex];
		linkedList.Insert(number);
	}
}

void printLinkedList(LinkedList<int>& linkedList)
{
	cout << "Sorted Linked List:\n";
	Node<int>* currentNode = linkedList.getHead()->getNext();
	while (currentNode != linkedList.getTail())
	{
		int currentData = *(currentNode->getData());
		cout << currentData << " ";
		currentNode = currentNode->getNext();
	}
	cout << endl;
}

void logResults(LinkedList<int>& sortedList, clock_t startTime, int arraySize)
{
	clock_t endTime = clock();
	clock_t ticksDifference = startTime - endTime;
	float timeInSeconds = ((float)ticksDifference) / CLOCKS_PER_SEC;
	cout << "Seconds: " << timeInSeconds << endl;
	if (arraySize < 100)
	{
		printLinkedList(sortedList);
	}
}

// From https://www.cplusplus.com/doc/tutorial/arrays/
void timeSort(int numbers[], int arraySize)
{
	LinkedList<int> linkedList{ 0 };
	insertNumbers(numbers, arraySize, linkedList);
	clock_t startTime = clock();
	LinkedList<int> sortedList = mergeSort<int>(linkedList);
	logResults(sortedList, startTime, arraySize);
}

void timeAlgorithm()
{
	int dataSet1[] = {5, 4, 3, 2, 9};
	timeSort(dataSet1, 5);
}