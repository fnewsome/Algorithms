#include "SLL.h"

#include <iostream>
using namespace std;

template <class T>
class Queue{
 
     public:
         Queue():head(NULL),tail(NULL),list(new SLL<T>()){ 
         }

         ~Queue(){ }

         void Enqueue(const T& item){
              list->InsertFirst(item);    
         }

         Node<T> DeQueue(){
             
         }
         
         Node<T> Front(){
             Node<T> *tmp = head;
             if(tmp)
                 return list->head; 
         } 
    private:
        Node<T> *head,*tail;
        SLL<T>* list;
        
};
