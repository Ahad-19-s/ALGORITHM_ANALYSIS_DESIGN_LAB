
#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

void dijkstra(int source, vector<vector<pair<int,int>>> &adj, vector<int> &dist) {
    int n = adj.size();
    dist.assign(n, inf);
    dist[source] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});

    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto edge : adj[u]) {
            int node = edge.first;
            int w = edge.second;
            if(dist[u] + w < dist[node]) {
                dist[node] = dist[u] + w;
                pq.push({dist[node], node});
            }
        }
    }
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);

   
    adj[0].push_back({1,10});
    adj[0].push_back({2,40});

    adj[1].push_back({2,25});
    adj[1].push_back({3,50});

    
    adj[2].push_back({3,15});

    adj[2].push_back({6,50});
   

   

    adj[3].push_back({4,20});
   

    vector<int> dist;
    int source = 0;

    dijkstra(source, adj, dist);

    cout << "Shortest distance from node " << char('A' + source) << ":\n";
    for(int i = 0; i < n; i++) {
        cout << "To node " << char('A' + i) << " = " << dist[i] << endl;
    }

    cout<<"total minimum cost of the path " << dist[4]<<endl;

    return 0;
}












/*#include <bits/stdc++.h>
using namespace std;

int primst(map<char, vector<pair<char, int>>> &adj, char start) {
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    map<char, bool> visited;
    int sum = 0;

    pq.push({0, start}); // {weight, node}

    while (!pq.empty()) {
        auto it = pq.top();
        char node = it.second;
        int distance = it.first;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        sum += distance;

        for (auto &nextnode : adj[node]) {
            char adjnode = nextnode.first;
            int adjnodewt = nextnode.second;
            if (!visited[adjnode]) {
                pq.push({adjnodewt, adjnode});
            }
        }
    }
    return sum;
}

int main() {
    map<char, vector<pair<char, int>>> adj;

    // Adding undirected edges with char nodes
    adj['A'].push_back({'B', 2});
    adj['B'].push_back({'A', 2});

    adj['A'].push_back({'D', 6});
    adj['D'].push_back({'A', 6});

    adj['B'].push_back({'C', 3});
    adj['C'].push_back({'B', 3});

    adj['B'].push_back({'D', 8});
    adj['D'].push_back({'B', 8});

    adj['B'].push_back({'E', 5});
    adj['E'].push_back({'B', 5});

    adj['C'].push_back({'E', 7});
    adj['E'].push_back({'C', 7});

    char startNode = 'A';
    cout << "Total weight of MST = " << primst(adj, startNode) << endl;

    return 0;
}*/
