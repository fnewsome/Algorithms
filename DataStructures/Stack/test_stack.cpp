#include "Stack.h"
#include <iostream>
#include <cstdlib>

using namespace std;


int main(void){
    typedef Stack<float> FloatStack;

    FloatStack fs(5);
    float f(1.1);

    cout << "Pushing elements onto fs\n";
    while(fs.push(f)){
        cout << f << ' ';
        f += 1.1;
    }
    cout << endl << "Stack is Full." << endl;
    cout << "Popping elements from fs\n";
    while(fs.pop(f)){
        cout << f << ' ';
    } 
    if(fs.isEmpty()) cout << endl << "Stack is Empty" << endl;
    return EXIT_SUCCESS;
}
