#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }

    void inorder(TreeNode* node, vector<int>& res) {
        if (!node) return;

        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }
};

TreeNode* buildTree(int n) {
    if (n == 0) return nullptr;

    int x;
    cin >> x;
    TreeNode* root = new TreeNode(x);

    queue<TreeNode*> q;
    q.push(root);

    int count = 1;

    while (count < n) {
        TreeNode* temp = q.front();
        q.pop();

        int leftVal, rightVal;

        cin >> leftVal;
        count++;
        if (leftVal != -1) {
            temp->left = new TreeNode(leftVal);
            q.push(temp->left);
        }

        if (count >= n) break;

        cin >> rightVal;
        count++;
        if (rightVal != -1) {
            temp->right = new TreeNode(rightVal);
            q.push(temp->right);
        }
    }
    return root;
}

int main() {
    int n;
    cout << "Enter number of nodes (-1 for NULL): ";
    cin >> n;

    cout << "Enter tree in level order: ";
    TreeNode* root = buildTree(n);

    Solution obj;
    vector<int> result = obj.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
