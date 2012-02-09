#include <iostream>

using namespace std;

// Name: sqrt
//
// Description: Utilize a modified binary search to 
// locate the square root value of the given X
//
int sqrt(int x){
    int mid, lo = 0, hi = x / 2 + 1;
    
    while( lo < hi ){
        mid = lo + (hi-lo) / 2;

        if( (mid * mid) == x )
            return mid;
        else if( (mid * mid) > x )
            hi = mid  - 1;
        else if( (mid * mid) < x )
            lo = mid + 1;

    }
    return hi;

}


int main(void){

    int x = 36;

    cout << "sqrt(" << x << ") is: " << sqrt(x) << endl;


    return 0;
}
