#include <iostream>

using namespace std;

int findSmallestMissingNumber(int arr[], int N){

    // traverse the items in the array
    for(int i=0; i < N; ++i){
        // if the difference between the consecutive pairs > 1 
        // return the previous item (a[i]) + 1
        //
        if( (arr[i+1] - arr[i]) > 1)
            return arr[i] + 1; 
    }

}


int main(void){

    int arr[] = {0,2,3,4,5};
    int arrSize = (size_t)(sizeof(arr)/sizeof(arr[0]));
    cout << "Smallest missing #: " << findSmallestMissingNumber(arr, arrSize) << endl;

    return 0;
}
