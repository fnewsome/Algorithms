#include <iostream>
#include <vector>
using namespace std;

// Purpose: Given N sorted lists containing integers, merge the lists into one list
//

// Name: merge
// 
// Description: Given two lists, merge them, and return the merged list
//
// Arguments: listA - first list to be merged
//            listB - second list to be merged
//
// Returns: A merged list of integers
//
vector<int> merge(vector<int> listA, vector<int> listB){
    if(listA.size() == 0) return listB;

    if(listB.size() == 0) return listA;

    vector<int> merged;
    int v1 = 0, v2 = 0, idx = 0;
    
    // continue until we hit the end of either list
    while(v1 < listA.size() && v2 < listB.size()){
        if(listA[v1] < listB[v2])
            merged.push_back(listA[v1++]);
        else
            merged.push_back(listB[v2++]);
    }
    // copy any left-overs
    while( v1 < listA.size()) merged.push_back(listA[v1++]);
    while( v2 < listB.size()) merged.push_back(listB[v2++]);
 
    return merged;
}


//
// Name: main
//
// Description: Main driver for the program
//
// Returns: Zero if successful
//
int main(void){
 
    vector<int> output;
    vector<vector<int> > list;
    vector<int> list1;
    vector<int> list2;
    vector<int> list3;

    // add items to our 3 lists
    //
    list1.push_back(3); 
    list1.push_back(6); 
    list1.push_back(7);
    list2.push_back(1); 
    list2.push_back(69);
    list3.push_back(9); 
    list3.push_back(11);    

    // add our lists to one collection
    //
    list.push_back(list1); 
    list.push_back(list2);
    list.push_back(list3);

    // loop through the list of vectors
    // and merge the lists
    //
    for(int i=0; i < list.size(); ++i){
       output = merge(output,list[i]);
    }

    // Display the final merged list
    //
    for(int j=0; j < output.size(); ++j)
        cout << output[j] << " ";

    cout << endl;
    return 0;
}
// Output: 1 3 6 7 9 11 69
