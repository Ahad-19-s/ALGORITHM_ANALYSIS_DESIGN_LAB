#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int source,destination,weight;

};
bool compareweight(const Edge &a,const Edge &b){
    return a.weight< b.weight;
}

int parent[5];

// Find root of set
int find(int x){
    if(parent[x]!= x){
        parent[x]= find(parent[x]);
    }
    return parent[x];
}

// Union two sets

void unite(int x,int y){
    parent[find(x)]=find(y);
}

int main(){
    // City indices: A=0, B=1, C=2, D=3, E=4
    vector<Edge> edges={
        {0, 1, 10}, // A-B
        {0, 2, 40}, // A-C
        {1, 2, 25}, // B-C
        {1, 3, 50}, // B-D
        {2, 3, 15}, // C-D
        {2, 4, 30}, // C-E
        {3, 4, 20}  // D-E
    };
    // int size= edges.size();

    for(int i=0;i<5;i++)
        parent[i]=i;
     
    sort(edges.begin(),edges.end(),compareweight);

     cout << "Selected edges for MST:\n";
     int totalcost=0;

     for(auto e : edges){
    if(find(e.source) != find(e.destination)){
        unite(e.source,e.destination);
        totalcost+=e.weight;
        // Print edge in city letters
      cout<<char('A'+e.source) <<"-"<< char('A'+ e.destination) << " : "<<e.weight<<endl;  
    }
     }

     cout << "Total minimum cost: " << totalcost << endl;
    
   /*  for (auto &e : edges)
  cout << e.source << "-" << e.destination << ": " << e.weight << endl;
      */
     return 0;
 }