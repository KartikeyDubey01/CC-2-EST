#include <iostream>
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        int length = 1;
        ListNode* tail = head;

        while (tail->next) {
            tail = tail->next;
            length++;
        }

        int position = k % length;
        if (position == 0) return head;

        tail->next = head;

        ListNode* current = head;
        for (int i = 0; i < length - position - 1; ++i) {
            current = current->next;
        }

        ListNode* newHead = current->next;
        current->next = nullptr;

        return newHead;
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

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, k;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    ListNode* head = createList(n);

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    head = obj.rotateRight(head, k);

    cout << "Rotated list: ";
    printList(head);

    return 0;
}