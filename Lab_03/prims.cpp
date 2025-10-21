#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    map<char, vector<pair<char, int>>> adj;  // adjacency list

    void addEdge(char u, char v, int w, bool undirected = true) {
        adj[u].push_back({v, w});
        if (undirected) adj[v].push_back({u, w});
    }

    void prims(char start) {
        map<char, int> key;
        map<char, char> parent;
        map<char, bool> inMST;

        // Initialize all keys as a large number (infinity)
        for (auto &it : adj) {
            key[it.first] = INT_MAX;
            parent[it.first] = '-';
            inMST[it.first] = false;
        }

        // Min-heap priority queue: {weight, {node, parent}}
        priority_queue<pair<int, pair<char, char>>,
                       vector<pair<int, pair<char, char>>>,
                       greater<pair<int, pair<char, char>>>> pq;

        // Start with the initial node
        key[start] = 0;
        pq.push({0, {start, '-'}});

        int totalWeight = 0;
        vector<pair<char, char>> mstEdges;

        while (!pq.empty()) {
            char node = pq.top().second.first;
            char parentNode = pq.top().second.second;
            int weight = pq.top().first;
            pq.pop();

            if (inMST[node]) continue;

            inMST[node] = true;
            totalWeight += weight;

            if (parentNode != '-')
                mstEdges.push_back({parentNode, node});

            for (auto &edge : adj[node]) {
                char neighbor = edge.first;
                int edgeWeight = edge.second;
                if (!inMST[neighbor] && edgeWeight < key[neighbor]) {
                    key[neighbor] = edgeWeight;
                    pq.push({edgeWeight, {neighbor, node}});
                    parent[neighbor] = node;
                }
            }
        }

        cout << "Edges in MST:\n";
        for (auto &e : mstEdges)
            cout << e.first << " - " << e.second << "\n";

        cout << "Total weight of MST = " << totalWeight << endl;
    }
};

int main() {
    Graph g;
    g.addEdge('A', 'B', 10);
    g.addEdge('A', 'C', 40);
    g.addEdge('B', 'C', 25);
    g.addEdge('B', 'D', 50);
    g.addEdge('C', 'D', 15);
    g.addEdge('C', 'E', 30);
    g.addEdge('D', 'E', 20);

    g.prims('A');

    return 0;
}
