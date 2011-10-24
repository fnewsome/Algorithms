#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


void reverse(char *start, char *end){

    char temp;
  
    while(start < end){
        // store start character
        temp = *start;
        *start++ = *end;
        *end-- = temp; 
    }
}

void reverseWords(char *str){

    char *word = str;
    char *tmp = str;

    while(*tmp){
        tmp++;
        if( *tmp == '\0'){
            reverse(word,tmp-1);
        }
        else if( *tmp == ' '){
            reverse(word,tmp-1);
            word = tmp+1;
        }
    }
    reverse(str,tmp-1);
}


int main(void){

    char A[] = "Hello World";

    reverseWords(A);
    cout << "Reversed Words: " << A << endl;

    return 0;
}
