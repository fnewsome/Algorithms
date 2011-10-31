#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> listA, vector<int> listB){
    if(listA.size() == 0) return listB;

    if(listB.size() == 0) return listA;

    vector<int> merged;
    int v1 = 0, v2 = 0, idx = 0;
    
    // continue until we hit the end of either list
    while(v1 < listA.size() && v2 < listB.size()){
        if(listA[v1] < listB[v2])
            merged[idx++] = listA[v1++];
        else
            merged[idx++] = listB[v2++];
    }
    // copy any left-overs
    while( v1 < listA.size()) merged[idx++] = listA[v1++];
    while( v2 < listB.size()) merged[idx++] = listB[v2++];
 
    return merged;
}

int main(void){
 
    vector<int> output;
    vector<vector<int> > list;
    vector<int> l1;
    l1.push_back(3); 
    l1.push_back(6); 
    l1.push_back(7);
    vector<int> l2; 
    l2.push_back(1); 
    l2.push_back(69);
    vector<int> l3; 
    l3.push_back(9); 
    l3.push_back(11);    

    list.push_back(l1); 
    list.push_back(l2);
    list.push_back(l3);

    output = merge(l1,l2);
    //for(int i=0; i < list.size(); i+=2){
    //   output = merge(list[i],list[i+1]);
    //}
    //for(int j=0; j < output.size(); ++j)
    //    cout << output[j] << " ";

    //cout << endl;
    return 0;
}
