#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool {false,true}bool;

bool isUnique(char *str){
    
    int checker = 0;
    int i,val = 0;
    int N = strlen(str);

    for(i=0; i < N; ++i){
        val = str[i] - 'a';
  
        if((checker && (1 << val) > 0))
            return false;
        checker |= (1 << val);
    }
    return true;
}


int main(void){
    
    char input[] = "abba";

    if(isUnique(input))
        printf("The given string '%s' is unique\n",input);
    else
        printf("The given string '%s' is not unique\n",input);
    
    
    return EXIT_SUCCESS;
}
