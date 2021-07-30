#include <iostream>
#include <string>

using namespace std;

// must acknowledge the type of SLL

#include "SinglyLinkedList.h"

#include "SinglyLinkedListIterator.h"
//#include "SinglyLinkedListIteratorB.h"

//#define InsertAtEnd1
#define InsertAtEnd2

#define prnt(x) cout << x << endl

int main()
{
    using ListOfInt = SinglyLinkedList<int>;
    using IntListIter = SinglyLinkedListIterator<int>;
    // ! created on the stack.
    // a r-value is inputted here
    // ListOfInt Three(3);
    // // the addr of Three is put as an arg
    // // in SLL.h will hold this in a pointer. 
    // ListOfInt Two(2, &Three);
    // ListOfInt One(1, &Two);

    //! created on heap with a pointer to address of that object. 
    ListOfInt* Three = new ListOfInt(3);
    ListOfInt* Two = new ListOfInt(2, Three);
    ListOfInt* One = new ListOfInt(1, Two);

    //* creation of SLL is considered recursion, since the 2nd arg calls the SLL node as next for current node. 

    //! insert at top, mind the loop below. 
    //ListOfInt* NewInt = new ListOfInt(4, Three);

    //! inserting between 2 and 3.
    // ListOfInt* NewInt = new ListOfInt(4);
    // NewInt->fNext = Two;
    // Three->fNext = NewInt;
    
    //! deleting a node (2)
    // making Three's new next equal to One.
    //Three->fNext = Three->fNext->fNext;
    //* limitation of SLL (to be remedied by Doubly Linked List) - 
    //*     deletion of a node at the end of the SLL will require a search from top to the end (last new node) - linear search 

    //! inserting at the end of linked list - Method 1. 
    #ifdef InsertAtEnd1
    // we need to search for the end of Linked list here. 
    // temp is a double pointer to One's pointer address. Initial. 
    ListOfInt** temp = &One;
    // dereference the temp and return the address of One's pointer.
    while(*temp != nullptr)
    {
        //* temp is storing the address of the temp's dereferenced (addr of One, Two or Three) fNext address.
        // e.g for One, the address of Two is stored in temp.
        // for Two, the address of Three is stored in temp.
        // for Three, the address of nullptr is stored in temp (temp will exit the loop after this.).
        temp = &((*temp)->fNext);
    }
    // while loop is exited, 
    // since temp (deref next) is nullptr.
    //* a new SLL value (9 fData, nullptr fNext) is created and is stored in the dereferenced temp (that is addr of fNext SLL at Three).
    //* this address of fNext in Three SLL is now temp's instance (9). same as (Three = new ListOFInt(3, new ListOfInt(9)))
    *temp = new ListOfInt(9);
    //? what Three's next is now. (9)
    //prnt(Three->fNext->fData);
    //* purpose of a double pointer is to store the address of SLL fNext (since it is in the parent SLL) and manipulate it accordingly. 
    #endif

    //! inserting at the end of linked list (With Aliasing)- Method 2. 
    #ifdef InsertAtEnd2
    //* instead we could store the last next pointer in temp value. 
    // must have the head pointer (One) and the tail pointer (Three)
    ListOfInt* NewNode = new ListOfInt(10);

    if(One == nullptr)
        One = NewNode;
    else
        Three->fNext = NewNode;
    
    //* since we added NewNode as fNext for Three (prev last node), the last node now becomes the new node. 
    Three = NewNode;        
    
    //? when we assign new node to Three, who holds the value 3 now? 
 
     //* inserting at the end will perserve the order of list node.

    #endif

    //! a pointer to the addres of Three.
    //ListOfInt* lTop = &One;

    //! further examples
    // int num = 10;
    // int* nPtr = &num;
    // prnt(nPtr);

    // int** nPtr2 = &nPtr;
    // prnt(*nPtr2);

    

    // get next pointer and deref and access fData
    //cout << One->fNext->fData << endl;
    
    // the index var is not init because it is defined above. 
    //for(; lTop !=nullptr; lTop = lTop -> fNext)

    // when using specB iterator, must passed a 
    // l-value reference. that is without the addr
    // ref (&).
    // the addr of One will be managed inside construct

    for(const int& data : IntListIter(One))
    { 
        // deref operator returns the fData
        // increments in body (here) at end of this loop
        prnt("Value: " << data);
    }

    //! free memory
    delete One;
    delete Two;
    delete Three;
    // delete NewInt;
    #ifdef InsertAtEnd1
    delete *temp;
    #endif

    //* should not be used because it was assigned to Three and Three is already freed, above. 
    // #ifdef InsertAtEnd2
    // delete NewNode;
    // #endif

    return 0;
}