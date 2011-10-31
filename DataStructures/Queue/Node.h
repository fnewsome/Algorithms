#include <iostream>

#ifndef _NODE_
#define _NODE_

using namespace std;

template <class T>
class Node{

    public:
        // Item data value
        T item;
 
        // Pointer to the next Node in the list
        Node *next;
};
#endif

