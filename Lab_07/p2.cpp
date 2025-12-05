#include <bits/stdc++.h>
using namespace std;

vector<int> candidates = {2, 3, 6, 7};
vector<int> combination;
int target = 7;

void combinationSum(int index, int currentTarget) {

    // If target reached
    if (currentTarget == 0) {
        cout << "{ ";
        for (int x : combination) cout << x << " ";
        cout << "}" << endl;
        return;
    }

    // If no more candidates or target becomes negative
    if (index == candidates.size() || currentTarget < 0)
        return;

    // Include current number (repetition allowed)
    combination.push_back(candidates[index]);
    combinationSum(index, currentTarget - candidates[index]);
    combination.pop_back();

    // Exclude current number
    combinationSum(index + 1, currentTarget);
}

int main() {
    combinationSum(0, target);
    return 0;
}
