#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> result;

        while (head != NULL) {
            result.push_back(head->val);
            head = head->next;
        }

        int left = 0, right = result.size() - 1;

        while (left < right) {
            if (result[left] != result[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

ListNode* createList(int n) {
    if (n == 0) return nullptr;

    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        temp->next = new ListNode(x);
        temp = temp->next;
    }
    return head;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    ListNode* head = createList(n);

    Solution obj;
    bool ans = obj.isPalindrome(head);

    if (ans)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}