#include <time.h>
#include <iostream>

#include "mergeSort.h"

using namespace std;

void insertNumbers(int numbers[1000], LinkedList<int>& linkedList)
{
	for ()
}

void timeSort(int numbers[1000])
{
	LinkedList<int> myLinkedList{ 0 };
	clock_t startTime = clock();
	LinkedList<int> sortedList = mergeSort<int>(myLinkedList);
	clock_t endTime = clock();
	clock_t ticksDifference = startTime - endTime;
	// From https://www.cplusplus.com/doc/tutorial/arrays/
	float timeInSeconds = ((float)ticksDifference) / CLOCKS_PER_SEC;
	cout << "Seconds: " << timeInSeconds << endl;
}

void timeAlgorithm()
{
	int dataSet1[1000] = {};
	timeSort(dataSet1);
}