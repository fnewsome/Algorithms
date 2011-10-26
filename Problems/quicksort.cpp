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
// Arguments: start - leftmost item in the list
//            end   - rightmost item in the list
//
void QuickSort(int list[], int start, int end){
    int i = start;    // index of left  -> right scan
    int k = end;      // index of right -> left scan

    // ensure that there is at least 2 items to sort
    //
    if( end - start >= 1){
        // set pivot as the first item in the partition
        int pivot = list[start];

        // while the left and right indices 
        // have not met
        //
        while( k > i){
            // from the left, look for the first
            // element greater than the pivot
            while(list[i] <= pivot )
                i++;
    
            // from the right, look for the first
            // element less than the pivot
            //
            while(list[k] > pivot )
                k--;

            // if the left index is smaller than
            // the right index, swap the items
            if( k > i)
                swap(&list[i],&list[k]);
                
        }
        // after indices crossed, swap last element
        // with the pivot
        //
        swap(&list[start],&list[k]);
       
        // quicksort the left partition
        QuickSort(list,start, k-1);
        // quicksort the right partition
        QuickSort(list,k+1,end);
    }
    else{
        return; // array is sorted, so exit
    }
}

// Name: QuickSort
// 
// Description: Calls our QuickSort method
//
// Arguments: list[] - list of items to sort
//            len    - length of the array
//
void QuickSort(int list[], int len){
    QuickSort(list,0,len-1);
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

// Name: main
//
// Description: Main driver for the program
//
int main(void){

    int num[] = {4,5,6,2,10,9,7};
    int N = sizeof(num)/sizeof(num[0]);

    QuickSort(num,N);
    PrintItems(num,N);
    return 0;
}
