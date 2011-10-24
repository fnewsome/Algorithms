#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline void swap(char *a, char *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

char* reverseString(char *str, int left,int right){
    int i;
    int N = end; //strlen(str);
    char *p = str;
    for(i=0; i < N/2; ++i){
        swap(&p[i],&p[N-i-1]);
    }
    return p;
}

void reverseWords(char *str){

    

}

int main(void){

    char a[] = "Hello World";
    reverseString(a, strlen(a));
    printf("%s\n", a);
    // reverse each word in the sentence
    reverseWord(a);    
        


}
