#include <iostream>
#include <vector>
using namespace std;

int main() {
    string X, Y;

    // -------- Input Section --------
    cout << "Enter first string: ";
    cin >> X;

    cout << "Enter second string: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    // Create DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // -------- DP Logic for LCS --------
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // -------- Output --------
    cout << "Length of the Longest Common Subsequence = "
         << dp[m][n] << endl;

   return 0;
}