
// COS30008, Final Exam, 2021

#pragma once

#include "TTree.h"

#include <stack>

template<typename S>
struct TTreeFrontier
{
    size_t stage;                           // frontier stages: 0, 1, 2
    const TTree<S>* node;                   // frontier TTree node
    
    TTreeFrontier( const TTree<S>* aNode ) :
        node(aNode),                        // TTree node
        stage(0)                            // 0 - start right
    {}
};

template<typename T>
class TTreePostfixIterator
{
private:
    const TTree<T>* fTTree;                 // 3-way tree
    std::stack<TTreeFrontier<T>> fStack;    // DFS traversal stack

    using Frontier = TTreeFrontier<T>;

	// push subtree starting with aNode
	void push_nodes( const TTree<T>* aNode )
    {
        Frontier lTemp(aNode);

        // push to right if any
        if(!fTTree->getRight().empty()){
            lTemp.stage = 0;
        }
        else if(!fTTree->getMiddle().empty()){
            lTemp.stage = 1;
        }
        else{
            lTemp.stage = 2;
        }

        fStack.push(lTemp);
        
   }
    
 public:

    using Iterator = TTreePostfixIterator<T>;
    
    Iterator operator++(int)
    {
        Iterator old = *this;

        ++(*this);
        
        return old;
    }
    
    bool operator!=( const Iterator& aOtherIter ) const
    {
        return !(*this == aOtherIter);
    }

	// iterator constructor
	TTreePostfixIterator( const TTree<T>* aTTree ):fTTree(aTTree)
    {
        const TTree<T>* lTree = fTTree;                    
        
        while ( !lTree->empty() )                              
        {
            push_nodes(lTree);                           
            lTree = &lTree->getRight();                                
        }
    }

	// iterator dereference
	const T& operator*() const
    {
        return **fStack.top().node;

    }

    // prefix increment
	Iterator& operator++()
    {
        const TTree<T>* lTree = fStack.top().node->getLeft();

        fStack.pop();  

        if ( !lTree->empty() )                                
        {
            push_nodes(lTree);

            lTree = &lTree->getRight();

            while(!lTree->empty())
            {
                push_nodes(lTree);
                lTree = &lTree->getRight();
            }
        }

        return *this;                                         
    }

	// iterator equivalence
	bool operator==( const Iterator& aOtherIter ) const
    {
         return
            fTTree == aOtherIter.fTTree &&             
            fStack.size() == aOtherIter.fStack.size();         
    }

	// auxiliaries
	Iterator begin() const
    {
        return Iterator(fTTree);
    }
	Iterator end() const
    {
        Iterator lTempIter = *this;                              
        lTempIter.fStack = std::stack<TTreeFrontier<T>>();            
        
        return lTempIter;                                           
    }
};
