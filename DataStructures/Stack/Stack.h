
#ifndef _STACK_
#define _STACK_

#include <iostream>

using namespace std;

// Name: Stack
//
// Description: This class implements the notion of a stack.  A stack
// can be thought of like a "stack of plates" for lamens terms.  Only the top most
// item can be retrieved/popped (i.e. via a pop() function ).  The stack follows a FILO
// order which stands for First In Last Out.  This simply means that the "first" item 
// added (i.e. via a push() function) to the stack is the "last" item removed.
//
template <class T>
class Stack{

    // Default size for the stack	
    static const int N = 10;
    public:

        // Name: Stack
	//
        // Description: Default constructor for the class that allocates
	// memory for the stack with the default size.
	//
        Stack();

	// Name: Stack
	// 
	// Description: Constructor that accepts a given size and allocates
	// memory for the stack.
	// 
        Stack(int size = 10);
        
	// Name: ~Stack
	//
	// Description: Default destructor for the class where the 
	// memory for the stack is deallocated.
	//
	~Stack();

	// Name: push
	//
	// Description: Adds an item to the top of the stack.
	//
	// Returns: True if successful, else false.
	//
        bool push(const T&);

	// Name: pop
	//
	// Description: Removes an item from the top of the stack.
	//
	// Returns: True if successful, else false.
        bool pop(T&);

	// Name: isEmpty
	//
	// Description: Determines if the stack is empty.
	//
	// Returns: True if the stack is empty, else false.
	//
        bool isEmpty() const;

	// Name: isFull
	//
	// Description: Determines if the stack is full.
	//
	// Returns: True if the stack is full, else false.
	//
        bool isFull() const;

	// Name: getSize
	//
	// Description: Returns the size of the stack.
	//
	// Returns: The number of items the stack can store.
	//
        int getSize() const; 
    private:
	// store the size of the stack
        int _size;

	// represents the store for the stack items
        T *_stackPtr;

	//
	// index value that tracks the position
	// within the array for the "top most" item (i.e. last item )
	// in the array
	//
        int _top;
        
};
#endif

//
// Name: Stack
// 
template <class T>
Stack<T>::Stack(){
    _stackPtr = new T[N];
}

//
// Name: isFull
//
template <class T>
bool Stack<T>::isFull() const{
    return _top == _size-1;
}

//
// Name: getSize
//
template <class T>
int Stack<T>::getSize() const{
    return _size;
}


// 
// Name: isEmpty
//
template <class T>
bool Stack<T>::isEmpty() const{
    return _top == -1;
}

//
// Name: push
//
template <class T>
bool Stack<T>::push(const T& item){
    bool result = false;
    if(!isFull()){
        _stackPtr[++_top] = item;
        result = true;
    }
    return result;
}

//
// Name: pop
//
template <class T>
bool Stack<T>::pop(T& item){
    bool result = false;
    if(!isEmpty()){
        item = _stackPtr[_top--];
        result = true;
    }
    return result;
}

// 
// Name: Stack
//
template <class T>
Stack<T>::Stack(int size){
    _size = (size > 0 && size < 1000) ? size : N;
    _top = -1;
    _stackPtr = new T[_size];
}

// 
// Name: ~Stack
//
template <class T>
Stack<T>::~Stack(){ 
    delete [] _stackPtr;
}


