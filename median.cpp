#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int len1 = nums1.size(), len2 = nums2.size();
        int left = 0, right = len1;

        while (left <= right) {
            int part1 = (left + right) / 2;
            int part2 = (len1 + len2 + 1) / 2 - part1;

            int maxLeft1 = (part1 == 0) ? INT_MIN : nums1[part1 - 1];
            int minRight1 = (part1 == len1) ? INT_MAX : nums1[part1];
            int maxLeft2 = (part2 == 0) ? INT_MIN : nums2[part2 - 1];
            int minRight2 = (part2 == len2) ? INT_MAX : nums2[part2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((len1 + len2) % 2 == 0)
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                else
                    return max(maxLeft1, maxLeft2);
            } 
            else if (maxLeft1 > minRight2)
                right = part1 - 1;
            else
                left = part1 + 1;
        }
        return 0.0;        
    }
};

int main() {
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;
    vector<int> nums1(n);

    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < n; i++) cin >> nums1[i];

    cout << "Enter size of second array: ";
    cin >> m;
    vector<int> nums2(m);

    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < m; i++) cin >> nums2[i];

    Solution obj;
    double median = obj.findMedianSortedArrays(nums1, nums2);

    cout << "Median is: " << median << endl;

    return 0;
}