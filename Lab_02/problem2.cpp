#include <bits/stdc++.h>
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

    // 1. Sequential Search
    auto start = high_resolution_clock::now();
    cout << "Sequential Search - Discounts for orders:\n";
    for(int i=0;i<orders.size();i++){
        if(orders[i].second > 3){
            cout << "Order_ID " << orders[i].first << " gets 50% discount\n";
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "Time: " << duration.count() << " microseconds\n\n";

    // 2. Binary Search
    // Binary search requires the vector to be sorted by order_ID
    sort(orders.begin(), orders.end()); // sort by order_ID

    start = high_resolution_clock::now();
    cout << "Binary Search - Discounts for orders:\n";
    for(int i=0;i<orders.size();i++){
        if(orders[i].second > 3){
            // Search the order_ID using binary search
            int left = 0, right = orders.size()-1, target = orders[i].first;
            while(left <= right){
                int mid = left + (right-left)/2;
                if(orders[mid].first == target){
                    cout << "Order_ID " << orders[mid].first << " gets 50% discount\n";
                    break;
                }
                else if(orders[mid].first < target) left = mid+1;
                else right = mid-1;
            }
        }
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout << "Time: " << duration.count() << " microseconds\n";

    return 0;
}
