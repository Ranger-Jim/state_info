#pragma once

#include "BSTInterface.h"
#include "Node.h"
#include "City.h"
#include "Visitor.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename T>

class BST : public BSTInterface<T> {
public:
	BST();
	~BST();

	BST<T>* loadTreeData();
	bool isEmpty() const;
	bool add(const T& newItem);
	bool remove(const T& delItem);
	void clear();
	bool contains(const T& findItem) const;

	void inOrderTraverse() const;
	void preOrderTraverse() const;
	void postOrderTraverse() const;

	void inOrderVisit(Visitor& visitor) const;

private:
	Node<T>* root;
	Node<T>* placeNode(Node<T>* currRoot, Node<T>* newNode);
	bool findNode(Node<T>* currentRoot, const T& toFind) const;

	void inOrder(Node<T>* currRoot) const;
	void preOrder(Node<T>* currRoot) const;
	void postOrder(Node<T>* currRoot) const;

	void deleteTree(Node<T>* currentRoot);

	void inOrderVisitWorker(Node<T>* currRoot, Visitor& visitor) const;

};

template<typename T>
BST<T>::BST()
{
	root = nullptr;
}

template<typename T>
BST<T>::~BST()
{
	//destructor
}

template<typename T>
BST<T>* BST<T>::loadTreeData()
{
	string header;
	string newLine;
	fstream inFS;
	BST<City>* myTree = new BST<City>();

	inFS.open("USCities-100-1.csv");

	if (!inFS.is_open())
	{
		cout << "ERROR: Could not open file..." << endl;
	}
	getline(inFS, header);



	while (!inFS.eof())
	{
		getline(inFS, newLine);
		myTree->add(newLine);
	}

	inFS.close();

	return myTree;
}

template<typename T>
bool BST<T>::isEmpty() const
{
	return (root == nullptr);
}

//---------//
//***ADD***//
//---------//

template<typename T>
bool BST<T>::add(const T& newItem)
{
	Node<T>* newNode = new Node<T>(newItem);
	root = placeNode(root, newNode);

	return true;
}

template<typename T>
Node<T>* BST<T>::placeNode(Node<T>* currRoot, Node<T>* newNode)
{
	if (currRoot == nullptr)
	{
		//cout << newNode->getItem() << endl;
		return newNode;
	}
	else
	{
		if (newNode->getItem() < currRoot->getItem())
		{
			//cout << "GOING LEFT..." << endl;
			Node<T>* tempPtr = placeNode(currRoot->getLeftChild(), newNode);
			currRoot->setLeftChild(tempPtr);
		}
		else
		{
			//cout << "GOING RIGHT..." << endl;
			currRoot->setRightChild(placeNode(currRoot->getRightChild(), newNode));
		}
		return currRoot;
	}
}

template<typename T>
bool BST<T>::remove(const T& delItem)
{
	return false;
}

//-----------//
//***CLEAR***//
//-----------//

template<typename T>
void BST<T>::clear()
{
	deleteTree(root);
}

template<typename T>
void BST<T>::deleteTree(Node<T>* currentRoot)
{
	cout << "DELETING THE TREE..." << endl;
	if (currentRoot == nullptr)
		return;

	deleteTree(currentRoot->getLeftChild());
	deleteTree(currentRoot->getRightChild());
	delete currentRoot;
}

//--------------//
//***CONTAINS***//
//--------------//

template<typename T>
bool BST<T>::contains(const T& findItem) const
{
	return findNode(root, findItem);
}

template<typename T>
bool BST<T>::findNode(Node<T>* currentRoot, const T& toFind) const
{
	if (currentRoot == nullptr)
	{
		return false;
	}
	else if (currentRoot->getItem() == toFind)
	{
		return true;
	}
	else if (toFind < currentRoot->getItem())
	{
		return findNode(currentRoot->getLeftChild(), toFind);
	}
	else
	{
		return findNode(currentRoot->getRightChild(), toFind);
	}

	return false;
}

//----------------------//
//***INORDER TRAVERSE***//
//----------------------//

template<typename T>
void BST<T>::inOrderTraverse() const
{
	if (root == nullptr)
	{
		cout << "THE TREE IS EMPTY..." << endl;
		return;
	}
	inOrder(root);
}

template<typename T>
void BST<T>::inOrder(Node<T>* currRoot) const
{
	if (currRoot != nullptr)
	{
		inOrder(currRoot->getLeftChild());

		T item = currRoot->getItem();
		cout << item;

		inOrder(currRoot->getRightChild());
	}
}

//----------------------//
//***PREODER TRAVERSE***//
//----------------------//

template<typename T>
void BST<T>::preOrderTraverse() const
{
	if (root == nullptr)
	{
		cout << "THE TREE IS EMPTY..." << endl;
		return;
	}
	preOrder(root);
}

template<typename T>
void BST<T>::preOrder(Node<T>* currRoot) const
{
	if (currRoot != nullptr)
	{
		T item = currRoot->getItem();
		cout << item << " ";

		preOrder(currRoot->getLeftChild());
		preOrder(currRoot->getRightChild());
	}
}

//------------------------//
//***POSTORDER TRAVERSE***//
//------------------------//

template<typename T>
void BST<T>::postOrderTraverse() const
{
	if (root == nullptr)
	{
		cout << "THE TREE IS EMPTY..." << endl;
		return;
	}
	postOrder(root);
}

template<typename T>
void BST<T>::postOrder(Node<T>* currRoot) const
{
	if (currRoot != nullptr)
	{
		postOrder(currRoot->getLeftChild());
		postOrder(currRoot->getRightChild());

		T item = currRoot->getItem();
		cout << item << " ";
	}
}

//-------------------//
//***INORDER VISIT***//
//-------------------//

template<typename T>
void BST<T>::inOrderVisit(Visitor& visitor) const
{
	inOrderVisitWorker(root, visitor);
}

template<typename T>
void BST<T>::inOrderVisitWorker(Node<T>* currNode, Visitor& visitor) const
{
	if (currNode != nullptr)
	{
		inOrderVisitWorker(currNode->getLeftChild(), visitor);
		visitor.visit(currNode->getItem());
		inOrderVisitWorker(currNode->getRightChild(), visitor);

	}
}

