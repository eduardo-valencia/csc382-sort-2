#pragma once
#include "LinkedList.h"
#include <iostream>

using namespace std;

///
/// The class that allows users to test manually.
///
class DynamicTest
{
private:
	// The name of the test
	string name;

protected:
	// The linked list that users will insert on.
	LinkedList<string> linkedList;

public:
	DynamicTest(string name);

	string prompt(string question);

	void promptUserToInsertDataItem(bool &shouldContinue);

	void promptUserToInsertData();

	// A pure virtual function for running the test.
	void virtual testOperation() = 0;

	Node<string> *promptUserToFindItem();

	void showWhetherItemWasFound(Node<string> *item);

	void startTest();
};