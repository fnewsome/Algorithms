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

// Name: main
//
// Description: Main driver for the program
//
int main(void){

    int num[] = {4,5,6,2,10,9,7};
    int N = sizeof(num)/sizeof(num[0]);
    
    // 
    QuickSort(num,N);
    PrintItems(num,N);
    return 0;
}
