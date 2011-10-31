#include "Queue.h"
#include <iostream>

using namespace std;


int main(void){
    
    int N = 10;    

    // instantiate a Queue that stores integers
    //
    Queue<int> *q = new Queue<int>();
     
    for(int i=1; i < N; ++i)
        q->Enqueue(i); 
    q->PrintItems();
    if(q->IsEmpty()) cout << "Queue is empty\n";    

    // Access the front in the Queue
    //
    cout << "Front Item: " << q->Front() << endl;
    cout << "Removing Front Item\n";
    // Remove the front item in the Queue
    q->Dequeue();

    // Print the Items
    q->PrintItems();
    return 0;
}

/* Output:
9 8 7 6 5 4 3 2 1 
Front Item: 9
Removing Front Item
8 7 6 5 4 3 2 1
*/
