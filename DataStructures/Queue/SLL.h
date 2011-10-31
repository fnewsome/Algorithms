#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
class SLL{

    public:
        SLL():head(NULL),tail(NULL){}

        ~SLL(){ }    
        
        // 
        // Name: InsertFirst
        // 
        // Description: Inserts a new item at the beginning of the list
        //
        void InsertFirst(const T &item ){
            Node<T> *tmp = head;
            Node<T> *newNode = new Node<T>();

            if(newNode){
                newNode->next = NULL;
                newNode->item = item;
            }
            else {
                return;
            }

            // if the list is empty, insert the item
            //
            if(!tmp){
                head = newNode;
                _size++;
                return;
            }

            // insert the item at the beginning
            newNode->next = head;
            head = newNode;
            _size++;
            
        }

        // 
        // Name: InsertLast
        //
        // Description: Inserts a new item at the end of the list
        //
        void InsertLast( const T &item ){
            Node<T> *tmp = head;
            Node<T> *newNode = new Node<T>();
            
            if(newNode){
                newNode->next = NULL;
                newNode->item = item;
            }

            if(!tmp){
                head = newNode;
                _size++;
                return;
            }

            while(tmp && tmp->next){
                tmp = tmp->next;
            }
            tmp->next = newNode;
            tail = newNode;
            _size++;
        }

        // 
        // Name: InsertSorted
        // 
        // Description: Inserts a new item in sorted order
        //
        void InsertSorted( const T &item){
            Node<T> *tmp = head;
            Node<T> *prev = NULL;
            Node<T> *newNode = new Node<T>();

            if(newNode){
                newNode->next = NULL;
                newNode->item = item;
            }

            // if the list is empty
            //
            if(!tmp){
                head = newNode;
                _size++;
                return;
            }

            while(tmp){
                if(tmp->item > item){
                    break;
                }
                else{
                    prev = tmp;
                    tmp = tmp->next;
                }
            }
            
            if(prev){
                prev->next = newNode;
            }
            else{
                head = newNode; 
            }
            newNode->next = tmp;
            _size++;
        }
 
        // 
        // Name: PrintList
        //
        // Description: Print the items within the current list
        //
        void PrintList(){
            Node<T> *tmp = head;
            
            while(tmp){
                cout << tmp->item << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
        
        //
        // Name: PrintList
        //
        // Description: Prints the items within the list
        // 
        // Arguments: Pointer to the head of the list
        //
        void PrintList(Node<T> *head){
            Node<T> *tmp = head;
            
            while(tmp){
                cout << tmp->item << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }        

        // 
        // Name: Free
        //
        // Description: Free the list and reclaim the allocated space
        //
        void Free(){
            Node<T> *tmp = head;
            Node<T> *curr = NULL;

            while(tmp){
                curr = tmp;
                tmp = tmp->next;
                delete curr;
            }
        }

        //
        // Name: Length
        //
        // Description: Returns the number of items in the list
        //
        // Returns: Number of items in the list
        //
        int Length(){
            return _size;
        }

        //
        // Name: ReverseList
        // 
        // Description: Reverses the items in the list
        //
        Node<T> *ReverseList(){
            Node<T>* tmp = head;
            Node<T>* prev = NULL;
            Node<T>* next = NULL;

            while(tmp){
                next = tmp->next;
                tmp->next = prev;
                prev = tmp;
                tmp = next;    
            }
            return prev;
        }

    private:
        Node<T> *head, *tail;   
        int _size;
        

};

