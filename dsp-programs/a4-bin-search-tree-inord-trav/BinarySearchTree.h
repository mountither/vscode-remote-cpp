
// COS30008, Problem Set 4, 2021

#pragma once

#include "BNode.h"

template <typename T>
class BinarySearchTreeIterator;

template <typename T>
class BinarySearchTree
{
private:
	BNode<T> *fRoot;

public:
	using Iterator = BinarySearchTreeIterator<T>;
	BinarySearchTree()
	{
		fRoot = &BNode<int>::NIL;
	}

	~BinarySearchTree()
	{
		if (!empty())
		{
			delete fRoot;
		}
	}

	bool empty() const
	{
		return fRoot->empty();
	}

	bool insert(const T &aKey)
	{
		if (empty())
		{
			fRoot = new BNode<T>(aKey);
			return true;
		}
		return fRoot->insert(aKey);
	}

	bool remove(const T &aKey)
	{
		return fRoot->remove(aKey, fRoot);
	}

	size_t height() const
	{
		return fRoot->height();
	}

	Iterator begin() const
	{
		return Iterator(fRoot).begin();
	}
	
	Iterator end() const
	{
		return Iterator(fRoot).end();
	}
};
