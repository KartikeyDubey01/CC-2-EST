#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); // initialize with "infinity"
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        return dp[amount] != amount + 1 ? dp[amount] : -1;
    }
};

int main() {
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << "Enter target amount: ";
    cin >> amount;

    Solution obj;
    int result = obj.coinChange(coins, amount);

    if (result == -1)
        cout << "Not possible to make amount" << endl;
    else
        cout << "Minimum coins needed: " << result << endl;

    return 0;
}