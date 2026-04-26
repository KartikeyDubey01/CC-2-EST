#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int n : nums) {
            freq[n]++;
        }

        vector<int> res;
        for (auto& pair : freq) {
            if (pair.second == 1) {
                res.push_back(pair.first);
            }
        }

        return res;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> result = obj.singleNumber(nums);

    cout << "Single numbers are: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}