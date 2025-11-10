#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <chrono>
using namespace std;
using namespace std::chrono;

vector<int> dijkstra(int vertex, int start, vector<vector<pair<int,int>>>& adj) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(vertex, INT_MAX);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop(); // ✅ fixed

        for (auto it : adj[node]) {
            int adjnode = it.first;
            int adjwt = it.second;
            if (distance + adjwt < dist[adjnode]) {
                dist[adjnode] = distance + adjwt;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }
    return dist;
}

int main() {
    int v = 1000;
    vector<vector<pair<int,int>>> best(v + 1);
    for (int i = 1; i < v; i++) {
        best[i].push_back({i + 1, 1});
        best[i + 1].push_back({i, 1});
    }

    auto start1 = high_resolution_clock::now();
    dijkstra(v + 1, 1, best);
    auto end1 = high_resolution_clock::now();
    auto t1 = duration_cast<milliseconds>(end1 - start1).count();
    cout << "Best Case (Sparse Graph)   : " << t1 << " ms\n";

    //avgrage case time
    
}

// 

// আপনি চাইলে আমি এই কোডের জন্য worst case বা dense graph এর simulation ও টাইমিং যুক্ত করে দিতে পারি। বললেই করে দেব!
