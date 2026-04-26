#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
            result[i] = result[i - 1] * nums[i - 1];

        int right = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            right *= nums[i + 1];
            result[i] *= right;
        }

        return result;
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
    vector<int> ans = obj.productExceptSelf(nums);

    cout << "Product array: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}