#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <queue>

using namespace std;


typedef struct Node{
    struct Node *left, *right;
    int data;
}Node;

Node *root = NULL;

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
