#include<bits/stdc++.h>
using namespace std;
using namespace std:: chrono;

int main(){
     vector<pair<int,int>> orders = {
        {102, 2}, {101, 1}, {105, 3}, {104, 2}, {103, 5},
        {110, 1}, {107, 2}, {106, 1}, {108, 4}, {109, 2},
        {115, 1}, {114, 3}, {112, 2}, {113, 1}, {111, 4},
        {120, 1}, {118, 2}, {117, 3}, {116, 2}, {119, 1},
        {125, 1}, {124, 2}, {123, 3}, {122, 2}, {121, 1}
    };

    int n= orders.size();

    //selection sort 

    vector<pair<int,int>>v= orders;

    auto start= high_resolution_clock::now();

    for(int i=0; i<n-1;i++){
        int min=1;
        for(int j=i+1;j<n;j++){
            if(v[j].first<v[min].first){
                min=j;
            }
        }
        if(min!=i){
            swap(v[i],v[min]);
        }
    }
    auto end =high_resolution_clock:: now();
    auto duration = duration_cast<microseconds>(end-start);
    cout<<"selection sort:\n";
    for(int i=0;i<n;i++){
        cout<<"("<<v[i].first<<","<<v[i].second<<")";
    }
    cout<<"\n time :"<<duration.count()<< " microseceonds\n\n\n";
//insertion sort
    
    vector<pair<int,int>>x=orders;

    start=high_resolution_clock::now();
    for(int)



}