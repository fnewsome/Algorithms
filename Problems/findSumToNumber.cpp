#include <iostream>
#include <cstdlib>

using namespace std;


// Name: swap
// 
// Description: Swaps the items in a list indicated by given indices 
//
// Arguments: a - first item to swap
//            b - second item to swap
//
inline void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Name: QuickSort
//
// Description: Sort the items in the given list using the QuickSort algorithm
//
// Arguments: left    - leftmost item in the list
//            right   - rightmost item in the list
//
void QuickSort(int list[], int left, int right){
    int i = left;       // index used to scan left -> right
    int j = right;      // index used to scan right -> left

    // ensure that there is at least 2 items to sort
    // Note, our array index starts at the value 0
    //
    if( right - left >= 1){
        // first item as the pivot
        // 
        int pivot = list[left];

        // while the left and right indices haven't met
        //
        while( j > i){
            // from the left, look for the first
            // element greater than the pivot
            while(list[i] <= pivot )
                i++;
    
            // from the right, look for the first
            // element less than the pivot
            //
            while(list[j] > pivot )
                j--;

            // if the left index is smaller than
            // the right index, swap the items
            if( j > i)
                swap(&list[i],&list[j]);
                
        }
        // after indices crossed, swap last element
        // with the pivot
        //
        swap(&list[left],&list[j]);
       
        // quicksort the left partition
        QuickSort(list,left, j-1);
        // quicksort the right partition
        QuickSort(list,j+1,right);
    }
    else{
        // the array is sorted, simply return
        return;
    }
}

// Name: QuickSort
// 
// Description: Calls our QuickSort method
//
// Arguments: list[] - list of items to sort
//            length    - length of the array
//
void QuickSort(int list[], int length){
    QuickSort(list,0,length-1);
}

// Name: PrintItems
//
// Description: Prints the items in a given list
//
// Arguments: list - the items in the list
//            size - the number of items in the list
//
void PrintItems(int *list, int size){
   if(size <= 0){
       cout << "No items in the list\n";
       return;
   }

   for(int i=0; i < size; ++i)
       cout << list[i] << " ";

   cout << endl;
}

int binarySearch(int list[], int key, int size){
    int mid = 0, midValue = 0, lo = 0, hi = size;

    while(lo <= hi){
        mid = lo + ((hi-lo)/2);
        midValue = list[mid];

        if(key > midValue)
            lo = mid + 1;
        else if(key < midValue)
            hi = mid -1;
        else
            return mid;
    }
    return -(lo+1);
}

// Name: FindSumToNumber
// 
// Description: Given a list of "sorted" integers, print the number
// pairs that sum to a given value, S
//
void FindSumToNumber(int list[], int S, int size){
        
    int idx = 0;

    // loop through the list of numbers
    for(int i=0; i < size; ++i){
        // use binary search to locate the (S-list_number[i]) in the list, return the index
        // This search performs on average in O(nlogn)
        //
        idx = binarySearch(list,S-list[i],size);
        
        // if we find that the number found + list_number[i] == S, print the pair (x,y)
        if(idx && ((list[i] + list[idx]) == S)){
            cout << "(" << list[i] << "," << list[idx] << ")\n";
            // If we have found the pair (x,y) where x = 4, y = 6
            // we do not want to report (y,x) so let's mark it by removing it from the list
            //
			list[i] = -1; 
        }
    }
}

// Name: main
//
// Description: Main driver for the program
//
int main(void){

    int num[] = {4,1,5,9,8,6,7};
    int N = sizeof(num)/sizeof(num[0]);
    
    // 
    QuickSort(num,N);
    PrintItems(num,N);
    cout << "Testing BinarySearch To Find '5', Item is at index: " << binarySearch(num,5,N) << endl;
    FindSumToNumber(num,13, N);
    return 0;
}
