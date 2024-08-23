#pragma once

#include <cstddef>
#include <iostream>

template <typename T>

class Node {
public:
	Node();
	~Node();
	Node(const T& newItem, Node<T>* left = nullptr, Node<T>* right = nullptr);
	Node(const Node& orig);

	T getItem() const;
	void setItem(const T& newItem);

	Node<T>* getLeftChild() const;
	Node<T>* getRightChild() const;

	void setLeftChild(Node<T>* left);
	void setRightChild(Node<T>* right);

	bool isLeaf() const;

	T item;
	Node<T>* leftChild;
	Node<T>* rightChild;

};


template <typename T>
Node<T>::Node() {
	leftChild = nullptr;
	rightChild = nullptr;

}

template <typename T>
Node<T>::Node(const T& newItem,
	Node<T>* left, Node<T>* right) {

	item = newItem;
	leftChild = left;
	rightChild = right;
}

template <typename T>
Node<T>::Node(const Node& orig) {
	item = orig.item;
	leftChild = orig.leftChild;
	rightChild = orig.rightChild;
}

template <typename T>
Node<T>::~Node() {
	//destructor
}

template <typename T>
T Node<T>::getItem() const {
	return item;
}

template <typename T>
void Node<T>::setItem(const T& newItem) {
	item = newItem;
}

template <typename T>
Node<T>* Node<T>::getLeftChild() const {
	return leftChild;
}

template <typename T>
Node<T>* Node<T>::getRightChild() const {
	return rightChild;
}

template <typename T>
void Node<T>::setLeftChild(Node<T>* left) {
	leftChild = left;
}

template <typename T>
void Node<T>::setRightChild(Node<T>* right) {
	rightChild = right;
}

template <typename T>
bool Node<T>::isLeaf() const {
	return (leftChild == nullptr && rightChild == nullptr);
}