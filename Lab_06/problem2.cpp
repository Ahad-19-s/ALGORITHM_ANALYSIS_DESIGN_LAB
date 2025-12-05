#include <bits/stdc++.h>
using namespace std;

int rodCutting(int n, vector<int> &prices) {
    vector<int> dp(n + 1, 0);

    for (int len = 1; len <= n; len++) {
        int best = 0;
        for (int cut = 1; cut <= len; cut++) {
            best = max(best, prices[cut] + dp[len - cut]);
        }
        dp[len] = best;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n + 1);
    for (int i = 1; i <= n; i++) cin >> prices[i];

    cout << rodCutting(n, prices) << endl;

    return 0;
}
