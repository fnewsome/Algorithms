#include <iostream>
#include <vector>
using namespace std;

//
// Name: merge
//
// Description: Merges the given list into one list
//
// Arguments: Vector of vectors containing a list of integers 
//
void merge(vector<vector<int> > list ){

    int minVal = 0;
    int minIdx = 0;
    
    do{
       minIdx  = -1;
       for(int i = 0; i < list.size(); ++i){
           if(list[i].size() > 0 ){ 
               if(minIdx == -1 || minVal > list[i][0]){
                   minVal = list[i][0],minIdx = i;
               }
           }
       }
       if(minIdx == -1) break;
       cout << minVal << " ";
       list[minIdx].erase(list[minIdx].begin());
    }while(1);
    cout << endl;
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
    merge(list);

    return 0;
}
