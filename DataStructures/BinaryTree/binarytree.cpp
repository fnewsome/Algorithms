#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <queue>

using namespace std;

// Tree Node definition
//
typedef struct Node{
    struct Node *left, *right;
    int data;
}Node;

// Root element
Node *root = NULL;


// Name: insertItem
// 
// Description: Inserts a new item into the Binary Tree
//
// Arguments: root = Root element
//            data - new item to insert
//
void insertItem(Node **root, int data){
 
    Node **tmp = root;
    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode){
        newNode->data = data;
        newNode->left = NULL, newNode->right = NULL;
    }
    
    while(*tmp){
        if( (*tmp)->data > data)
            tmp = (&(*tmp)->left);
        else
            tmp = (&(*tmp)->right);
    }
    // insert the new node at the empty position
    //
    *tmp = newNode;
}


// Name: BFSPrint
//
// Description: Performs a Breadth-first Search print
//
// Arguments: root = Root element
//
void BFSPrint(Node *root){
    queue<Node *>q;
    q.push(root);

    while(!q.empty()){
        int N = q.size();

        for(int i=0; i < N; ++i){
            Node *n = q.front();
            q.pop();
            cout << n->data << " ";
            if(n->left) q.push(n->left);
            if(n->right)q.push(n->right);
        }
        
    }
    cout << endl;  
}


// Name: DFSPrint
//
// Description: Performs a Depth-first Search print
//
// Arguments: root - Root element
//
void DFSPrint(Node *root){

    stack<Node *> s;
    queue<Node *> q;

    q.push(root);
    
    while(!q.empty()){
        Node *n = q.front();
        q.pop();
        s.push(n);
        if(n->right) q.push(n->right);
        if(n->left) q.push(n->left);
    }
    // print the stack
    while(!s.empty()){
        cout << ((Node*)s.top())->data << " ";
        s.pop();
    }
    cout << endl;
}

// Name: main
//
// Description: Main driver of execution
//
int main(void){
  
    insertItem(&root,5);
    insertItem(&root,3);
    insertItem(&root,7);
    insertItem(&root,1);
    insertItem(&root,4);
    insertItem(&root,8);
 
    BFSPrint(root);
    DFSPrint(root);

    return 0;
}
