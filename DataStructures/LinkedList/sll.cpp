#include <iostream>
#include <cstdlib>

using namespace std;

// Definition of our Singly Linked list item
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
Node *CreateNode(int data){
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
void InsertNode(Node *head, Node *newNode){
    Node *tmp = head;
    Node *prev = NULL;


    // case1: no elements
    if(!tmp){ root = newNode; return; }

    // case2: at least one element
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
    
    if(!tmp) { 
        cout << "<empty list>\n";
        return;
    }

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

    while(tmp){ 
        ++count; 
        tmp = tmp->next; 
    }
    return count;
}


// Name: RemoveNode
// 
// Description: Removes an item from the list
//
// Arguments: head - start of the list
//            data - data value to delete
//
Node *RemoveNode(Node* head, int data){
    Node *tmp = head;
    Node *prev = NULL;

    if(!tmp){ return NULL; }

    if(!prev){ 
        root = tmp->next; 
        return tmp; 
    }

    while(tmp){
        if(tmp->data == data) 
           break;
        tmp = tmp->next;        
    }
    prev->next = tmp->next;
    return tmp;
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

// Name: ReverseList
//
// Description: Reverses the linked list given
//
//
Node *ReverseList(Node *head){

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr, curr = next;

    }
    return prev;
}

// Name: FreeList
//
// Description: Free the memory allocated to construct the list
//
void FreeList(Node *head){
    Node *tmp = NULL;
    Node *curr = head;
    while(curr){
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }
}

// Name: main
//
// Description: Main driver for the application
//
int main(void){

    Node *list1, *list2;
    InsertNode(root,CreateNode(5));
    cout << "List contains: "; 
    PrintList(root);
    RemoveNode(root,5);
    cout << "List after removing '5': ";
    PrintList(root);
    
    // Create a new list
    InsertNode(root,CreateNode(2));
    InsertNode(root,CreateNode(1));
    InsertNode(root,CreateNode(3));
    InsertNode(root,CreateNode(4));
    InsertNode(root,CreateNode(6));
    InsertNode(root,CreateNode(5));
    
    cout << "New list contains: ";
    PrintList(root);
    Node *reverse = ReverseList(root);
    cout << "Reverse the list: ";
    PrintList(reverse);
    cout << "Split the list in half" << endl;
    SplitLinkedList(reverse,&list1,&list2);
    cout << "Items in the first list: ";
    PrintList(list1);
    cout << "Items in the second list: ";
    PrintList(list2);
    FreeList(root);
    root = NULL;
    list1 = NULL;
    list2 = NULL;
    reverse = NULL;
    return EXIT_SUCCESS;
}
/* Output: 
List contains: 5 
List after removing '5': <empty list>
New list contains: 1 2 3 4 5 6 
Reverse the list: 6 5 4 3 2 1 
Split the list in half
Items in the first list: 6 5 4 
Items in the second list: 3 2 1
*/
