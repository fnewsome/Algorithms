#include "SLL.h"
#include <iostream>
#include <string>

using namespace std;


int main(){

    SLL<string> *list = new SLL<string>();
    SLL<int> *numbers = new SLL<int>();

    list->InsertFirst("Alex");
    list->InsertLast("Carlos");
    list->PrintList();
    cout << "There are " << list->Length() << " items in the list of strings\n";
    list->Free();

    numbers->InsertSorted(5);
    numbers->InsertSorted(1);
    numbers->InsertLast(10);
    numbers->PrintList();
    cout << "There are " << numbers->Length() << " items in the list of integers\n";    
    
    numbers->Free();    
    return 0;
}
