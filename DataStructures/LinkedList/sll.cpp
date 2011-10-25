#include <iostream>
#include <cstdlib>

using namespace std;

// Definition of our list item
//
typedef struct Node{
    struct Node *next;
    int data;
}Node;

//
// Head of the list
//
Node *root = NULL;

// Name: CreateNode
// 
// Description: Creates a new node
// 
// Arguments: data - value of the item
//
// Returns: Node - pointer to the Node
//
Node* CreateNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
 
    if(newNode){
        newNode->next = NULL;
        newNode->data = data;
    }
    return newNode;
}

// Name: InsertNode
//
// Description: Inserts a new item into the list in a sorted fashion
//
// Arguments: head    - start of the list
//            newNode - new item to add
//
void InsertNode(Node* head, Node *newNode){
    Node *tmp = head;
    Node *prev = NULL;

    if(!tmp){ root = newNode; return; }

    while(tmp){
        if(tmp->data > newNode->data){
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
        root = newNode; 
    }
    newNode->next = tmp;
}

// Name: PrintList
// 
// Description: Prints the list items
//
// Arguments: head - pointer to the start of the list
//
void PrintList(Node *head){
    Node *tmp = head;
    
    while(tmp){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Name: GetLength
// 
// Description: Determine the numbe of items in the list
//
// Arguments: head - the start of the list
//
// Returns: The number of items in the list
//
int GetLength(Node *head){
    Node *tmp = head;
    int count = 0;

    while(tmp){ ++count; tmp = tmp->next; }

    return count;
}

// Name: SplitLinkedList
// 
// Description: Given a linked list, split the list in two
// 
// Arguments: head  - start of the list to split
//            list1 - point to the start of the first list
//            list2 - point to the start of the second list
// 
void SplitLinkedList(Node *head, Node** list1, Node **list2){
    Node *tmp = head;
    Node *prev = NULL;
    int idx = 0;
    
    *list1 = head;
    
    // locate middle of the list
    int midp = GetLength(head)/2;
    
    while(tmp){
        if(idx == midp){
            // we've found the middle
            // so seperate the lists
            //
            prev->next = NULL;
            *list2 = tmp;
            break;
        }
        prev = tmp;
        tmp = tmp->next;
        ++idx;
    }    
}

// Name: main
//
// Description: Main driver for the application
//
int main(void){

    Node *list1, *list2;
    InsertNode(root,CreateNode(5));
    InsertNode(root,CreateNode(2));
    InsertNode(root,CreateNode(1));
    InsertNode(root,CreateNode(3));
    InsertNode(root,CreateNode(4));
    InsertNode(root,CreateNode(6));
    PrintList(root);
    SplitLinkedList(root,&list1,&list2);
    cout << "Start of second list is: " << list2->data << endl;
    cout << "Items in the second list: ";
    PrintList(list2);
    return EXIT_SUCCESS;
}
