#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

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
	clock_t ticksDifference = endTime - startTime;
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

void generateDataSet(int numbers[], int arraySize)
{
	srand(time(NULL));
	for (int numberIndex = 0; numberIndex < arraySize; ++numberIndex)
	{
		numbers[numberIndex] = rand();
	}
}

void generateDataSetAndTimeAlgorithm(int dataset[], const int datasetSize)
{
	generateDataSet(dataset, datasetSize);
	timeSort(dataset, datasetSize);
}

void time100Numbers()
{
	const int datasetSize = 100;
	int dataset[datasetSize];
	generateDataSetAndTimeAlgorithm(dataset, datasetSize);
}

void time1000Numbers()
{
	const int datasetSize = 1000;
	int dataset[datasetSize];
	generateDataSetAndTimeAlgorithm(dataset, datasetSize);
}

void time10000Numbers()
{
	const int datasetSize = 10000;
	int dataset[datasetSize];
	generateDataSetAndTimeAlgorithm(dataset, datasetSize);
}

void timeAlgorithm()
{
	time100Numbers();
	time1000Numbers();
	time10000Numbers();
}