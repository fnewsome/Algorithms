#include <iostream>
#include <cstdlib>

using namespace std;

int binarySearch(int a[], int key){
    int mid,midValue;
    int lo = 0;
    int hi = sizeof(a)/sizeof(a[0]);

    while(lo <= hi){
        mid = lo + ((hi-lo)/2);
        midValue = a[mid];
  
        if(key > midValue) 
            lo = mid + 1;
        else if( key < midValue)
            hi = mid - 1;
        else
            return mid;   // found key
    }
    return -(lo + 1);     // key not found
}

void QuickSort(int list[], int left, int right){


}

void quicksort(int list[]){


}



int main(void){

    int list[] = {4,2,53,23,11,3,5,21};
    cout << "value: " << binarySearch(list,5) << endl;
 
    return 0;
}
