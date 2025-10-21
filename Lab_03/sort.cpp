#include<bits/stdc++.h>
using namespace std;
struct Talk {
    int start;
    int finish;
};

bool compareFinishTime(const Talk &a, const Talk &b) {
    return a.finish < b.finish;
}

int main() {
    vector<Talk> talks = {{4, 8}, {55, 5}, {4, 6}};
    sort(talks.begin(), talks.end(), compareFinishTime);

    for(auto &t : talks)
        cout << t.start << " " << t.finish << endl;
}
