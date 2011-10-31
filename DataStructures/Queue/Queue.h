#ifndef _QUEUE_
#define _QUEUE_

#include "SLL.h"
#include <iostream>
using namespace std;

template <class T>
class Queue{
 
     public:
         // 
         // Name: Queue
         //
         // Description: Default constructor for the Queue class
         //              that performs initilizations.
         //
         Queue():list(new SLL<T>()){
             head = list->GetHead();
             tail = head;
         }

         // 
         // Name: ~Queue
         //
         // Description: Destructor for the class that reclaims used 
         //              space.
         //
         ~Queue(){ 
             if(!IsEmpty()){
                 list->FreeList();
                 list = NULL, head = NULL, tail = NULL;
             }
         }

         //
         // Name: Enqueue
         //
         // Description: Adds a new item onto the front of the Queue
         //
         void Enqueue(const T& item){
              list->InsertFirst(item); 
         }

         //
         // Name: DeQueue
         // 
         // Description: Removes the item at the front of the Queue
         //
         void Dequeue(){
             head = list->GetHead(); 
             Node<T> *tmp = head;
             if(!IsEmpty()){
                 list->SetHead(head->next);
                 delete tmp;
                 if(NULL == head)
                     tail = NULL;
             }
             else{
                 cerr << "Queue is empty -- can't remove a value\n";
             }             
         }
 
         // 
         // Name: IsEmpty
         //
         // Description: Determines if the Queue is empty
         bool IsEmpty(){
             return list->GetHead() == NULL;
         }
         
         //
         // Name: PrintItems
         //
         // Description: Prints the items in the Queue
         //
         void PrintItems(){
             list->PrintList();
         }
         
         // 
         // Name: Front
         //
         // Description: Return the item in the front of the list
         //
         T Front() const{
             Node<T> *tmp = list->GetHead();
             if(tmp){
                 return tmp->item; 
             }
             else{
                 return NULL;
             }
         } 

    private:
        // Pointers to the front and end of the queue
        Node<T> *head,*tail;

        // represents our Queue
        SLL<T>* list;
        
};
#endif
