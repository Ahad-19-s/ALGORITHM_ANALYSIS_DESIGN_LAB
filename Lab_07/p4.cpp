#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color, vector<vector<int>>& graph, vector<int>& colors) {
    for(int adj = 0; adj < graph.size(); adj++) {
        if(graph[node][adj] == 1 && colors[adj] == color)
            return false;
    }
    return true;
}

bool solve(int node, vector<vector<int>>& graph, int m, vector<int>& colors) {
    if(node == graph.size()) return true;

    for(int c = 1; c <= m; c++) {
        if(isSafe(node, c, graph, colors)) {
            colors[node] = c;

            if(solve(node + 1, graph, m, colors)) return true;

            colors[node] = 0;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> graph = {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };
    int m = 3;

    vector<int> colors(4, 0);

    if(solve(0, graph, m, colors)) {
        for(int c : colors) cout << c << " ";
    }
    else cout << "No solution";
}
