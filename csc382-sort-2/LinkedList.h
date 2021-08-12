#pragma once
#include "Node.h"

template <typename Data>
class LinkedList
{
public:
	Node<Data>* head;
	Node<Data>* tail;

	LinkedList(Data defaultValue);

	Node<Data>* getHead();

	void setHead(Node<Data>* newHead);

	Node<Data>* getTail();

	Node<Data>* Find(Data* data);

	void Insert(Data data);

	void Delete(Node<Data>* node);
};