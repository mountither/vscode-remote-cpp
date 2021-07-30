
// COS30008, List, Problem Set 3, 2021

#pragma once

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

#include <stdexcept>

template<typename T>
class List
{
private:
	// auxiliary definition to simplify node usage
	using Node = DoublyLinkedList<T>;

	Node* fRoot;	// the first element in the list
	size_t fCount;	// number of elements in the list

public:
	// auxiliary definition to simplify iterator usage
    using Iterator = DoublyLinkedListIterator<T>;

	~List()                                                             // destructor - frees all nodes
    {
        while ( fRoot != nullptr )
        {
            if ( fRoot != &fRoot->getPrevious() )                       // more than one element
            {
                Node* lTemp = const_cast<Node*>(&fRoot->getPrevious()); // select last
                
                lTemp->isolate();                                       // remove from list
                delete lTemp;                                           // free
            }
            else
            {
                delete fRoot;                                           // free last
                break;                                                  // stop loop
            }
        }
    }

    void remove( const T& aElement )	                                // remove first match from list
    {
        Node* lNode = fRoot;                                            // start at first
        
        while ( lNode != nullptr )                                      // Are there still nodes available?
        {
            if ( **lNode == aElement )                                  // Have we found the node?
            {
                break;                                                  // stop the search
            }

            if ( lNode != &fRoot->getPrevious() )                       // not reached last
            {
                lNode = const_cast<Node*>(&lNode->getNext());           // go to next
            }
            else
            {
                lNode = nullptr;                                        // stop search
            }
        }
        
        // At this point we have either reached the end or found the node.
        if ( lNode != nullptr )                                         // We have found the node.
        {
            if ( fCount != 1 )                                          // not the last element
            {
                if ( lNode == fRoot )
                {
                    fRoot = const_cast<Node*>(&fRoot->getNext());       // make next root
                }
            }
            else
            {
                fRoot = nullptr;                                        // list becomes empty
            }
            
            lNode->isolate();                                           // isolate node
            delete lNode;                                               // release node's memory
            fCount--;                                                   // decrement count
        }
    }

	// PS3 starts here
    
	// P1
    // default constructor
	List() : fRoot(nullptr), fCount(0)
    {}				

	bool isEmpty() const // Is list empty?
    {
        return fRoot == nullptr;
    }                   	

	size_t size() const // list size
    {
        return fCount;
    }

    void push_front(const T &aElement) // adds aElement at front
    {
        Node *lNode = new Node(aElement);
        
        if (fRoot == nullptr)
        {
            fRoot = lNode;
        }
        else
        {
            fRoot->push_front(*lNode);
            fRoot = lNode;
        }
      fCount++;
    }

    Iterator begin() const // return a forward iterator
    {
        return Iterator(fRoot);
    }
    Iterator end() const // return a forward end iterator
    {
        return begin().end();
    }
    Iterator rbegin() const // return a backwards iterator
    {
        return begin().rbegin();
    }
    Iterator rend() const // return a backwards end iterator
    {
        return begin().rend();
    }

	// P2
	void push_back(const T &aElement) // adds aElement at back
    {
        Node *lNode = new Node(aElement);
       
        if (fRoot == nullptr)
        {
            fRoot = lNode;
        }
        else
        {
            Node &lLastNode = const_cast<Node &>(fRoot->getPrevious());
            lLastNode.push_back(*lNode);
        }

        fCount++;
    }

	// P3

	const T &operator[](size_t aIndex) const // list indexer
    {
        if (aIndex < fCount)
        {
            const Node *lNode = fRoot;
            while (aIndex--)
            {
                lNode = &lNode->getNext();
            }
            return **lNode;
        }
        else
        {
            throw std::range_error("Index out of bounds.");
        }
    }
	// P4
	// copy constructor
	List(const List &aOtherList) : fRoot(nullptr), fCount(0)
    {
        for (const auto &n : aOtherList)
        {
            push_back(n);
        }
    }

    List &operator=(const List &aOtherList) // assignment operator
    {
            while (fRoot != nullptr)
            {
                if (fRoot != &fRoot->getPrevious())
                {
                    Node *lTemp = const_cast<Node *>(&fRoot->getPrevious());
                    lTemp->isolate();
                    delete lTemp;
                }
                else
                {
                    delete fRoot;
                    fRoot = nullptr;
                }
            }

            fCount = 0;

            for (const auto &n : aOtherList)
            {
                push_back(n);
            }

        return *this;
    }
  
	// P5X
	// move features
	List(List &&aOtherList) : // move constructor
            fRoot(aOtherList.fRoot),
            fCount(aOtherList.fCount)
    {
        aOtherList.fRoot = nullptr;
    }
    List &operator=(List &&aOtherList) // move assignment operator
    {
        while (fRoot != nullptr)
        {
            if (fRoot != &fRoot->getPrevious())
            {
                Node *lTemp = const_cast<Node *>(&fRoot->getPrevious());
                lTemp->isolate();
                delete lTemp;
            }
            else
            {
                delete fRoot;
                fRoot = nullptr;
            }
        }
        fRoot = aOtherList.fRoot;
        fCount = aOtherList.fCount;
        aOtherList.fRoot = nullptr;
        return *this;
    }
    
    void push_front(T &&aElement) // adds aElement at front
    {
        Node *lNode = new Node(move(aElement));
        if (fRoot == nullptr)
        {
            fRoot = lNode;
        }
        else
        {
            fRoot->push_front(*lNode);
            fRoot = lNode;
        }
        fCount++;
    }
    void push_back(T &&aElement) // adds aElement at back
    {
        Node *lNode = new Node(move(aElement));
        if (fRoot == nullptr)
        {
            fRoot = lNode;
        }
        else {
            Node &lLastNode = const_cast<Node &>(fRoot->getPrevious());
            lLastNode.push_back(*lNode);
        }
        fCount++;
    }
};
