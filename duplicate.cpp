#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>   // for abs
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) {
                if (abs(i - mp[nums[i]]) <= k)
                    return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    bool result = obj.containsNearbyDuplicate(nums, k);

    if (result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}