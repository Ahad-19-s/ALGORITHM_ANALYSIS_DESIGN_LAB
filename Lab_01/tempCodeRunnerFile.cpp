#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

vector<int> dijkstra(int vertex, int start, vector<vector<pair<int,int>>> &adj) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(vertex, INT_MAX);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

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
    int V = 1000; // vertex count (can adjust for faster/slower test)
    
    // ---------------- BEST CASE (Sparse Graph: like a simple chain) ----------------
    vector<vector<pair<int,int>>> best(V + 1);
    for (int i = 1; i < V; i++) {
        best[i].push_back({i + 1, 1});
        best[i + 1].push_back({i, 1});
    }

    auto start1 = high_resolution_clock::now();
    dijkstra(V, 1, best);
    auto end1 = high_resolution_clock::now();
    auto t1 = duration_cast<milliseconds>(end1 - start1).count();

    // ---------------- AVERAGE CASE (Medium dense graph) ----------------
    vector<vector<pair<int,int>>> avg(V + 1);
    
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < 4; j++) { // each node connected to 4 random nodes
            int r = rand() % V + 1;
            if (r != i)
               avg[i].push_back({r, rand() % 10 + 1});
        }
    }

    auto start2 = high_resolution_clock::now();
    dijkstra(V, 1, avg);
    auto end2 = high_resolution_clock::now();
    auto t2 = duration_cast<milliseconds>(end2 - start2).count();

    // ---------------- WORST CASE (Fully connected dense graph) ----------------
    vector<vector<pair<int,int>>> worst(V + 1);
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (i != j)
                worst[i].push_back({j, 1});
        }
    }

    auto start3 = high_resolution_clock::now();
    dijkstra(V, 1, worst);
    auto end3 = high_resolution_clock::now();
    auto t3 = duration_cast<milliseconds>(end3 - start3).count();

    cout << "========= Dijkstra Execution Time =========\n";
    cout << "Best Case (Sparse Graph)   : " << t1 << " ms\n";
    cout << "Average Case (Medium Graph): " << t2 << " ms\n";
    cout << "Worst Case (Dense Graph)   : " << t3 << " ms\n";
}
