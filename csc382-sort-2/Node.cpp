#include "Node.h"

// Node's constructor.
// Takes a pointer to data and instantiates the data, next, and previous properties.
template <typename Data>
Node<Data>::Node(Data data) : data{ data }, next{ nullptr }, previous{ nullptr }
{

}

// Returns a pointer to the data.
template <typename Data>
Data* Node<Data>::getData()
{
	return &data;
}

// Sets the data using a pointer.
template <typename Data>
void Node<Data>::setData(Data newData)
{
	data = newData;
}

// Gets the next node in the list.
template <typename Data>
Node<Data>* Node<Data>::getNext()
{
	return next;
}

// Sets the next node in the list.
template <typename Data>
void Node<Data>::setNext(Node<Data>* newNode)
{
	next = newNode;
}

// Gets previous node in the list.
template <typename Data>
Node<Data>* Node<Data>::getPrevious()
{
	return previous;
}

// Sets the previous node in the list.
template <typename Data>
void Node<Data>::setPrevious(Node<Data>* newNode)
{
	previous = newNode;
}

template class Node<int>;
template class Node<string>;