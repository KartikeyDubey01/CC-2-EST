#include <iostream>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }

        return left != nullptr ? left : right;        
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

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;

    TreeNode* left = findNode(root->left, val);
    if (left) return left;

    return findNode(root->right, val);
}

int main() {
    int n;
    cout << "Enter number of nodes (use -1 for NULL): ";
    cin >> n;

    cout << "Enter tree in level order: ";
    TreeNode* root = buildTree(n);

    int pVal, qVal;
    cout << "Enter value of p and q: ";
    cin >> pVal >> qVal;

    TreeNode* p = findNode(root, pVal);
    TreeNode* q = findNode(root, qVal);

    Solution obj;
    TreeNode* lca = obj.lowestCommonAncestor(root, p, q);

    if (lca)
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}