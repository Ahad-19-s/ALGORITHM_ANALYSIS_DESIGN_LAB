
`#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main() {
    // Sample orders: pair<order_ID, quantity>
    vector<pair<int,int>> orders = {
        {102, 2}, {101, 1}, {105, 3}, {104, 2}, {103, 5},
        {110, 1}, {107, 2}, {106, 1}, {108, 4}, {109, 2},
        {115, 1}, {114, 3}, {112, 2}, {113, 1}, {111, 4},
        {120, 1}, {118, 2}, {117, 3}, {116, 2}, {119, 1},
        {125, 1}, {124, 2}, {123, 3}, {122, 2}, {121, 1}
    };

    int n = orders.size();
    
    // 1. Selection Sort
    vector<pair<int,int>> v = orders; // copy original orders
    auto start = high_resolution_clock::now();
    for(int i=0;i<n-1;i++){
        int min_idx = i;
        for(int j=i+1;j<n;j++){
            if(v[j].first < v[min_idx].first)
                min_idx = j;
        }
        swap(v[i], v[min_idx]);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    
    cout << "Selection Sort:\n";
    for(int i=0;i<n;i++)
        cout << "(" << v[i].first << "," << v[i].second << ") ";
    cout << "\nTime: " << duration.count() << " microseconds\n\n";

    // 2. Insertion Sort
    v = orders;
    start = high_resolution_clock::now();
    for(int i=1;i<n;i++){
        auto key = v[i];
        int j=i-1;
        while(j>=0 && v[j].first > key.first){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    
    cout << "Insertion Sort:\n";
    for(int i=0;i<n;i++)
        cout << "(" << v[i].first << "," << v[i].second << ") ";
    cout << "\nTime: " << duration.count() << " microseconds\n\n";

    // 3. Bubble Sort
    v = orders;
    start = high_resolution_clock::now();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(v[j].first > v[j+1].first){
                swap(v[j], v[j+1]);
            }
        }
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    
    cout << "Bubble Sort:\n";
    for(int i=0;i<n;i++)
        cout << "(" << v[i].first << "," << v[i].second << ") ";
    cout << "\nTime: " << duration.count() << " microseconds\n";

    return 0;
}
