#include <iostream>
#include <map>

using namespace std;

typedef struct Node{
    int data;
    Node *next; 
}Node;

Node *head = NULL;
int numElements = 0;

// Name: PrintList
// 
// Description: Prints the items in the list
//
// Arguments: Root - starting element in the list
//
void PrintList(Node *Root){
    Node *tmp = Root;

    while(tmp){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}


// Name: CreateNode
// 
// Description: Creates a new node
//
// Arguments: data - new item to insert
//
Node * CreateNode(int data ){

    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode){
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

bool DeleteNode(Node *nodeToDelete ){

    Node *nextNode = nodeToDelete->next;
    if(!nodeToDelete || NULL == nodeToDelete->next) return false;

    nodeToDelete->data = nextNode->data;
    nodeToDelete->next = nextNode->next;
    free(nextNode);

    return true;
}

// Name: Insert
// 
// Description: Inserts a new item into the given list
//
// Arguments: Root - head of the list
//            newNode - new node to insert
//
void Insert(Node *Root, Node *newNode){
    Node *tmp = Root;
    Node *prev = NULL;

    if(!tmp){
        head = newNode;
        numElements++;
        return;
    }
    while(tmp){
        if( tmp->data > newNode->data){
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
    numElements++;
}


int main(void){

    for(int i=1; i <= 10; ++i)
        Insert(head, CreateNode(i));
    
    // insert our duplicate item
    Insert(head,CreateNode(1));

    // Remove any duplicates
    // RemoveDuplicates(head);
    RemoveDuplicatesUsingBuffer(head);
    PrintList(head);

    return 0;
}
