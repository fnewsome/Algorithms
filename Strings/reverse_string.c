#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Name: swap
// 
// Description: Swaps the two given characters
//
inline void swap(char *a, char *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}


void ReverseString(char *str){

    int i;
    int N = strlen(str);


    for(i=0; i < N/2; ++i){
        swap(&str[i],&str[N-i-1]);
    }

}


// Name: main
// 
// Description: main driver 
//
int main(void){

    char input[] = "Hello";

    printf("Original String: %s\n", input);
    ReverseString(input); 
    printf("Reverse String: %s\n", input);

    return EXIT_SUCCESS;
}
