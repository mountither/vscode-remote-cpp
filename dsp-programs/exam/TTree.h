
// COS30008, Final Exam, 2021

#pragma once

#include <stdexcept>
    
template<typename T>
class TTreePostfixIterator;

template<typename T>
class TTree
{
private:
    
    T fKey;
    TTree<T>* fLeft;
    TTree<T>* fMiddle;
    TTree<T>* fRight;
    
    TTree() : fKey(T())     // use default constructor to initialize fKey
    {
        fLeft = &NIL;       // loop-back: The sub-trees of a TTree object with
        fMiddle = &NIL;     //            no children point to NIL.
        fRight = &NIL;
    }
    
    void addSubTree( TTree<T>** aBranch, const TTree<T>& aTTree )
    {
        if ( !(*aBranch)->empty() )
        {
            delete *aBranch;
        }

        *aBranch = const_cast<TTree<T>*>(&aTTree);
    }

public:

    using Iterator = TTreePostfixIterator<T>;
    
    static TTree<T> NIL;    // sentinel

    // getters for subtrees
    const TTree<T>& getLeft() const { return *fLeft; }
    const TTree<T>& getMiddle() const { return *fMiddle; }
    const TTree<T>& getRight() const { return *fRight; }

    // add a subtree
    void addLeft( const TTree<T>& aTTree ) { addSubTree( &fLeft, aTTree ); }
    void addMiddle( const TTree<T>& aTTree ) { addSubTree( &fMiddle, aTTree ); }
    void addRight( const TTree<T>& aTTree ) { addSubTree( &fRight, aTTree ); }
        
    // remove a subtree, may through a domain error
    const TTree<T>& removeLeft() { return removeSubTree( &fLeft ); }
    const TTree<T>& removeMiddle() { return removeSubTree( &fMiddle ); }
    const TTree<T>& removeRight() { return removeSubTree( &fRight ); }

// Problem 1: TTree Basic Infrastructure

private:

	// remove a subtree, may throw a domain error
    const TTree<T>& removeSubTree( TTree<T>** aBranch )
    {   
        if(!(*aBranch)->empty())
        {
            TTree<T>* lRes = *aBranch;   
            *aBranch= &NIL;                          
            return *lRes;                         
        }
        else
        {
            throw std::domain_error( "Illegal subtree operation." );
        }
    }
    
public:
    
    // TTree l-value constructor
	TTree( const T& aKey ): 
        fKey(aKey), 
        fLeft(&NIL), 
        fRight(&NIL), 
        fMiddle(&NIL)
    {}
    
    // destructor (free sub-trees, must not free empty trees)
	~TTree()
    {
        if(fRight != &NIL)
        {
            delete fRight;
        }
        if(fLeft != &NIL)
        {
            delete fLeft;
        }
        if(fMiddle != &NIL)
        {
            delete fMiddle;
        }
    }
    
    // return key value, may throw domain_error if empty
	const T& operator*() const
    {
        if(!empty())
        {
            return fKey;
        }
        else
        {
            throw std::domain_error( "Empty TTree encountered" );
        }
    }

    // returns true if this TTree is empty
	bool empty() const
    {
        return this == &NIL;
    }

    // returns true if this TTree is a leaf
	bool leaf() const
    {
        return fRight->empty() && fMiddle->empty() && fLeft->empty();
    }
    
// Problem 2: TTree Copy Semantics
    
    // copy constructor, must not copy empty TTree
	TTree( const TTree<T>& aOtherTTree ) : TTree()
    {
        // error handle?
        if ( !aOtherTTree.empty() )
        {
            *this = aOtherTTree;
        }
        else
        {
            throw std::domain_error( "Copying NIL" );
        }
    }

    // copy assignment operator, must not copy empty TTree
	TTree<T>& operator=( const TTree<T>& aOtherTTree )
    {
        if ( !aOtherTTree.empty() )
        {
            if ( this != &aOtherTTree )
            {
                fKey = aOtherTTree.fKey;

                if ( fLeft != &NIL )
                {
                    delete fLeft;
                }
                
                fLeft = aOtherTTree.fLeft->empty() ? &NIL : const_cast<TTree<T>&>(aOtherTTree.getLeft()).clone();

                if ( fRight != &NIL )
                {
                    delete fRight;
                }
                    
                fRight =aOtherTTree.fRight->empty() ? &NIL :  const_cast<TTree<T>&>(aOtherTTree.getRight()).clone();

                if ( fMiddle != &NIL )
                {
                    delete fMiddle;
                }
                    
                fMiddle =aOtherTTree.fMiddle->empty() ? &NIL :  const_cast<TTree<T>&>(aOtherTTree.getMiddle()).clone();
            }
            
            return *this;
        }
        else
        {
            throw std::domain_error( "Copying NIL" );
        }
    }
    
    // clone TTree, must not copy empty trees
	TTree<T>* clone() const
    {
        if ( !empty() )
        {
            return new TTree( *this );              
        }
        else
        {
            return const_cast<TTree<T>*>(this);                    
        }
    }

// Problem 3: TTree Move Semantics

    // TTree r-value constructor
	TTree( T&& aKey ) : 
        fKey(std::move(aKey)),
        fLeft(&NIL), 
        fRight(&NIL), 
        fMiddle(&NIL)
    {}

    // move constructor, must not copy empty TTree
	TTree( TTree<T>&& aOtherTTree )
    {
        // error handle?
        if ( !aOtherTTree.empty() )
        {
            *this = std::move(aOtherTTree);
        }
        else
        {
            throw std::domain_error( "Moving NIL" );
        }
    }

    // move assignment operator, must not copy empty TTree
	TTree<T>& operator=( TTree<T>&& aOtherTTree )
    {
        if ( !aOtherTTree.empty() )
        {
            if ( this != &aOtherTTree )
            {
                fKey = std::move(aOtherTTree.fKey);

                if ( !aOtherTTree.getLeft().empty() )
                {
                    fLeft = const_cast<TTree<T>*>(&aOtherTTree.removeLeft());
                }
                else
                {
                    fLeft = &NIL;
                }
                

                if ( !aOtherTTree.getRight().empty() )
                {
                    fRight = const_cast<TTree<T>*>(&aOtherTTree.removeRight());
                }
                else
                {
                    fRight = &NIL;
                }
                    

                if ( !aOtherTTree.getMiddle().empty() )
                {
                    fMiddle = const_cast<TTree<T>*>(&aOtherTTree.removeMiddle());
                }
                else
                {
                    fMiddle = &NIL;
                }
                    
            }
            
            return *this;
        }
        else
        {
            throw std::domain_error( "Moving NIL" );
        }       
    }
    
// Problem 4: TTree Postfix Iterator

    // return TTree iterator positioned at start
	Iterator begin() const
    {
        return Iterator(const_cast<TTree<T>*>(this));
    }

    // return TTree iterator positioned at end
	Iterator end() const
    {
        return begin().end();
    }
};

template<typename T>
TTree<T> TTree<T>::NIL;
