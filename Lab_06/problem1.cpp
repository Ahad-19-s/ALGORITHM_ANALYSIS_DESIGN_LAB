#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {

            if (weights[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w],
                    values[i - 1] + dp[i - 1][w - weights[i - 1]]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W, n;

    cout << "Enter the capacity of the drone: ";
    cin >> W;

    cout << "Enter number of rock samples: ";
    cin >> n;

    vector<int> weights(n), values(n);

    cout << "Enter weights of the rocks:\n";
    for (int i = 0; i < n; i++) {
        cout << "Weight of rock " << i + 1 << ": ";
        cin >> weights[i];
    }

    cout << "Enter scientific values of the rocks:\n";
    for (int i = 0; i < n; i++) {
        cout << "Value of rock " << i + 1 << ": ";
        cin >> values[i];
    }

    int maxValue = knapsack(W, weights, values);

    cout << "\nMaximum scientific value that can be collected: "
         << maxValue << endl;
           
         return 0;
}