
#ifndef _STACK_
#define _STACK_
#include <iostream>

using namespace std;

template <class T>
class Stack{
    static const int N = 10;
    public:
        Stack();
        Stack(int size);
        ~Stack();

        bool push(const T&);
        bool pop(T&);
        bool isEmpty() const;
        bool isFull() const;
        int getSize() const; 
    private:
        int _size;
        T *_stackPtr;
        int _top;
        
};
#endif

template <class T>
Stack<T>::Stack(){
    _stackPtr = new T[N];
}

template <class T>
bool Stack<T>::isFull() const{
    return _top == _size-1;
}

template <class T>
int Stack<T>::getSize() const{
    return _size;
}

template <class T>
bool Stack<T>::isEmpty() const{
    return _top == -1;
}

template <class T>
bool Stack<T>::push(const T& item){
    bool result = false;
    if(!isFull()){
        _stackPtr[++_top] = item;
        result = true;
    }
    return result;
}

template <class T>
bool Stack<T>::pop(T& item){
    bool result = false;
    if(!isEmpty()){
        item = _stackPtr[_top--];
        result = true;
    }
    return result;
}

template <class T>
Stack<T>::Stack(int size){
    _size = (size > 0 && size < 1000) ? size : N;
    _top = -1;
    _stackPtr = new T[_size];
}

template <class T>
Stack<T>::~Stack(){ 
    delete [] _stackPtr;
}


