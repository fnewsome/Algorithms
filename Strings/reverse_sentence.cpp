#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

inline void swap(char *a, char *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

string ReverseString(string str, int L, int R){
    int N = R;
    cout << "string to reverse: " << str << endl;
    for(int i=L; i < N/2; ++i){
        swap(&str[i],&str[N-i-1]);
    }
    return str;
}

string ReverseWords(string str){

    int i = 0;
    int j = str.size();
    if(j > 1){
        str = ReverseString(str,0,j);

        for(int j=0; j <= str.size(); ++j){

            if( j == str.size() || str[j] == ' '){
                str = ReverseString(str,i,j);
                i = j+1;
            }
        }
    }
    return str;
}

int main(void){

    string str = "hello world";
    str = ReverseWords(str);
    cout << "New String: " << str << endl;
    return 0;
}
