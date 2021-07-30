
// COS30008, Doubly-linked Nodes, 2021

#pragma once

template<typename T>
class DoublyLinkedList
{
private:
    
    T fPayload;													// payload
    DoublyLinkedList* fNext;									// next element
    DoublyLinkedList* fPrevious;								// previous element
    
public:
    // this in fNext & fPrev are pointing to itself. 
	explicit DoublyLinkedList( const T& aPayload ) :			// l-value constructor	 
		fPayload(aPayload),
		fNext(this),
		fPrevious(this)
	{}									
	explicit DoublyLinkedList( T&& aPayload ):				// r-value constructor
		fPayload(move(aPayload)),
		fNext(this),
		fPrevious(this)
	{}		

    // aNode becomes previous of this
	DoublyLinkedList& push_front( DoublyLinkedList& aNode )
	{
		aNode.fNext = this;
		aNode.fPrevious = fPrevious;
		fPrevious->fNext = &aNode;
		fPrevious = &aNode;
		return aNode;

	}
	// aNode becomes next of this   	
	DoublyLinkedList& push_back( DoublyLinkedList& aNode )
	{
		aNode.fPrevious = this;

		aNode.fNext = fNext;
		fNext->fPrevious = &aNode;

		fNext = &aNode;
		return aNode;
	}
	// removes this node		 
	void isolate()
	{
		// unlinking the prev 
		fPrevious->fNext = fNext;
		// unlinking the next
		fNext->fPrevious = fPrevious;
			
		// isolation of node. 
		fNext = this;
		fPrevious = this;
	}	

	// exchange payloads
	void swap( DoublyLinkedList& aNode )
	{
		std::swap(fPayload, aNode.fPayload);
	} 						
	
	// dereference operator, payload
	const T& operator*() const
	{	
		return getPayload();

	}
	// returns constant reference to paylod                  				
	const T& getPayload() const
	{
		return fPayload;
	}
	// returns constant reference to next
    const DoublyLinkedList& getNext() const
	{
		// deref fNext to get the addr of that node. 
		return *fNext;
	}

	// returns constant reference to previous
	const DoublyLinkedList& getPrevious() const
	{
		return *fPrevious;
	}				
};
