#include<bits/stdc++.h>
using namespace std;

struct talk{
    char ID;
    int start,finis;
};
bool comparetime(const talk &a,const talk &b){
    return a.finis< b.finis;
}

int main(){
    vector<talk> given={
        {'A', 1, 4},
        {'B', 3, 5},
        {'C', 0, 6},
        {'D', 5, 7},
        {'E', 3, 8},
        {'F', 5, 9},
        {'G', 8, 11}
    };
    sort(given.begin(),given.end(),comparetime);

   cout << "Selected talks: ";

   int lastFinish = given[0].finis;
    cout << given[0].ID << " ";

    for(int i=1;i<given.size();i++){
        if(given[i].start>lastFinish){
            cout<<given[i].ID<<" ";
            lastFinish=given[i].finis;
        }

    }



}