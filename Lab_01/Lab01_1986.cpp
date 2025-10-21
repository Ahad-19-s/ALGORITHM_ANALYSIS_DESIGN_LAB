#include<bits/stdc++.h>
using namespace std;
vector<int>dijktra(int vertex,int start, vector<vector<pair<int,int>>> &adj){
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     vector<int>dist(vertex,INT_MAX);
     dist[start]=0;
        pq.push({0,start});
    while(!pq.empty()){
        int node=pq.top().second;
        int distance=pq.top().first;
        pq.pop();   
        for(auto it: adj[node]){
            int adjnode=it.first;
            int adjwt=it.second;
            if(distance+adjwt<dist[adjnode]){
                dist[adjnode]=distance+adjwt;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }
    return dist;

}

int main() {
    int v=10;
    vector<vector<pair<int,int>>> adj(11);
     adj[1].push_back({2, 1});
    adj[1].push_back({6, 1});//node,wt
    adj[2].push_back({1, 1});
    adj[2].push_back({3, 1});
    adj[2].push_back({5, 1});
    adj[3].push_back({2, 1});
    adj[4].push_back({2, 1});
    adj[4].push_back({5, 1});
    adj[5].push_back({4, 1});
    adj[5].push_back({8, 1});
    adj[6].push_back({1, 1});
    adj[6].push_back({7, 1});
    adj[6].push_back({9, 1});
    adj[7].push_back({6, 1});
    adj[7].push_back({8, 1});
    adj[8].push_back({5, 1});
    adj[8].push_back({7, 1});
    adj[9].push_back({6, 1});
   
    vector<int>result=dijktra(v,9,adj);
    for(int i=1;i<result.size();i++){
        cout<<i<<" to distance "<<result[i]<<endl;
    }
}