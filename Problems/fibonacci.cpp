#include <iostream>
#include <map>
using namespace std;

std::map<int,int> results;

int fib(int n){
    
    if( n == 0 || n == 1 )
        return 1;

    map<int,int>::iterator *iter = results.find(n);
 
    if( iter != results.end())
        return (*iter).second;
    else
        return results[ n ] = fib( n - 1) + fib( n - 2 );
}

int main(int argc, char *argv[]){

    int N = 10;
    std::cout << "fibonacci value for " << N << " is: " << fib(N);


    return 0;
}
