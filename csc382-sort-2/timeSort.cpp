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
		cout << "Array number " << number << endl;
		linkedList.Insert(number);
	}
}

// From https://www.cplusplus.com/doc/tutorial/arrays/
void timeSort(int numbers[], int arraySize)
{
	LinkedList<int> linkedList{ 0 };
	insertNumbers(numbers, arraySize, linkedList);
	clock_t startTime = clock();
	LinkedList<int> sortedList = mergeSort<int>(linkedList);
	clock_t endTime = clock();
	clock_t ticksDifference = startTime - endTime;
	float timeInSeconds = ((float)ticksDifference) / CLOCKS_PER_SEC;
	cout << "Seconds: " << timeInSeconds << endl;
}

void timeAlgorithm()
{
	int dataSet1[] = {1, 2, 3, 4, 5};
	timeSort(dataSet1, 5);
}