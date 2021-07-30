
// COS30008, Problem Set 4, 2021

#pragma once

#include <stack>

#include "BNode.h"

template <typename T>
class BinarySearchTreeIterator
{
private:
	const BNode<T> *fBNodeTree;			 // binary search tree
	std::stack<const BNode<T> *> fStack; // DFS traversal stack

public:
	using Iterator = BinarySearchTreeIterator<T>;

	BinarySearchTreeIterator(const BNode<T> *aBNodeTree) : fBNodeTree(aBNodeTree)
	{
		const BNode<T> *lCurrNT = fBNodeTree;
		stack<const BNode<T> *> lStack;
		while (!lCurrNT->empty() || !lStack.empty())
		{
			if (!lCurrNT->empty())
			{
				lStack.push(lCurrNT);
				lCurrNT = lCurrNT->right;
			}
			else
			{
				lCurrNT = lStack.top();
				fStack.push(lCurrNT);
				lStack.pop();
				lCurrNT = lCurrNT->left;
			}
		}
	}
	const T &operator*() const
	{
		return fStack.top()->key;
	}
	Iterator &operator++()
	{
		if (!fStack.empty())
		{
			fStack.pop();
		}
		return *this;
	}
	Iterator operator++(int)
	{
		Iterator lTemp = *this;
		++(*this);
		return lTemp;
	}
	bool operator==(const Iterator &aOtherIter) const
	{
		return fStack == aOtherIter.fStack && fBNodeTree == aOtherIter.fBNodeTree;
	}
	bool operator!=(const Iterator &aOtherIter) const
	{
		return !(*this == aOtherIter);
	}

	Iterator begin() const
	{
		return Iterator(fBNodeTree);
	}

	Iterator end() const
	{
		Iterator lE = *this;
		while (!lE.fStack.empty())
		{
			lE.fStack.pop();
		}
		return lE;
	}
};
