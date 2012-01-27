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

// Name: RemoveDuplicatesUsingBuffer
//
// Description: Remove duplicates using a buffer
//
// Arguments: Root - starting element in the list
//
// Complexity & Space: O(N) where N is the # of elements in the list
//
void RemoveDuplicatesUsingBuffer(Node *root){
    map<int,int> M;
    Node *tmp = root;
    Node *prev = NULL;
    while(tmp){
        if(M.find(tmp->data) != M.end()){
            // item is in the list
            prev->next = tmp->next;
        }
        else{
            // item is not in the list, so add it to the map
            M[tmp->data]++;
            prev = tmp;
        }
        tmp = tmp->next;
    }

}

// Name: RemoveDuplicates
//
// Description: Removes duplicate items from the list without a buffer
//
// Arguments: root - starting element in the list
//
// Time: O(N^2)
// Space: O(1)
void RemoveDuplicates(Node *root){
    Node *curr = root;

    while(curr){
        Node *peek = curr;
        
        while(peek->next){
            if(peek->next->data == curr->data){
                peek->next = peek->next->next;
            }
            else{
                peek = peek->next;
            }
        }
        curr = curr->next;
    }

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
