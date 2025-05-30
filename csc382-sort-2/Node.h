#pragma once

#include <iostream>

using namespace std;

///
/// A container that stores data.
///
template <typename Data>
class Node
{
private:
	Data data;

public:
	Node *previous;

	Node *next;

	Node(Data data);

	Data *getData();

	void setData(Data data);

	Node *getPrevious();

	void setPrevious(Node *previous);

	Node *getNext();

	void setNext(Node *next);
};