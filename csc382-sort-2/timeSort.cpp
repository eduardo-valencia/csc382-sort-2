#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "mergeSort.h"

using namespace std;

///
/// Inserts numbers from an array of numbers into the linked list
///
void insertNumbers(int numbers[], int arraySize, LinkedList<int> &linkedList)
{
	for (int numberIndex = 0; numberIndex < arraySize; ++numberIndex)
	{
		int number = numbers[numberIndex];
		linkedList.Insert(number);
	}
}

///
/// Shows all numbers in a linked list
///
void printLinkedList(LinkedList<int> &linkedList)
{
	cout << "Sorted Linked List:\n";
	Node<int> *currentNode = linkedList.getHead()->getNext();
	while (currentNode != linkedList.getTail())
	{
		int currentData = *(currentNode->getData());
		cout << currentData << " ";
		currentNode = currentNode->getNext();
	}
	cout << endl;
}

///
/// Shows the time the algorithm took and may print the linked list
///
void logResults(LinkedList<int> &sortedList, clock_t startTime, int arraySize)
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

///
/// Times how long the algorithm takes and shows the results
/// From https://www.cplusplus.com/doc/tutorial/arrays/
///
void timeSort(int numbers[], int arraySize)
{
	LinkedList<int> linkedList{0};
	insertNumbers(numbers, arraySize, linkedList);
	clock_t startTime = clock();
	LinkedList<int> sortedList = mergeSort<int>(linkedList);
	logResults(sortedList, startTime, arraySize);
}

///
/// Generates a dataset with random numbers.
///
void generateDataSet(int numbers[], int arraySize)
{
	srand(time(NULL));
	for (int numberIndex = 0; numberIndex < arraySize; ++numberIndex)
	{
		numbers[numberIndex] = rand();
	}
}

///
/// Generates the dataset and times how long the algorithm takes for that dataset.
///
void generateDataSetAndTimeAlgorithm(int dataset[], const int datasetSize)
{
	generateDataSet(dataset, datasetSize);
	timeSort(dataset, datasetSize);
}

void time10Numbers()
{
	const int datasetSize = 10;
	int dataset[datasetSize];
	generateDataSetAndTimeAlgorithm(dataset, datasetSize);
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

///
/// Times the algorithm using all datasets.
///
void timeAlgorithm()
{
	time10Numbers();
	time100Numbers();
	time1000Numbers();
}