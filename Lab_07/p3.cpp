#include <bits/stdc++.h>
using namespace std;

string s = "catsanddog";
unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};

vector<string> words;

void solveWordBreak(int start) {
    // If we reached the end of the string → valid sentence
    if (start == s.length()) {
        for (string &w : words)
            cout << w << " ";
        cout << endl;
        return;
    }

    string temp = "";
    for (int end = start; end < s.length(); end++) {
        temp += s[end];

        if (dict.count(temp)) {
            words.push_back(temp);          // choose word
            solveWordBreak(end + 1);        // explore
            words.pop_back();               // backtrack
        }
    }
}

int main() {
    solveWordBreak(0);
    return 0;
}
