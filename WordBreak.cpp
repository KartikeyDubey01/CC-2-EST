#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (const string& w : wordDict) {
                int start = i - w.length();
                if (start >= 0 && dp[start] && s.substr(start, w.length()) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    string s;
    int n;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter number of words in dictionary: ";
    cin >> n;

    vector<string> wordDict(n);
    cout << "Enter dictionary words: ";
    for (int i = 0; i < n; i++) {
        cin >> wordDict[i];
    }

    Solution obj;
    bool result = obj.wordBreak(s, wordDict);

    if (result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}