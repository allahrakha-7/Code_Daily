/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // base case
        if (root == nullptr) return true;

        int leftHeight = getHeight(root -> left);
        int rightHeight = getHeight(root -> right);

        bool currentBalanced = abs(leftHeight - rightHeight) <= 1;

        bool leftSubtreeBalanced = isBalanced(root -> left);
        bool rightSubtreeBalanced = isBalanced(root -> right);

        return currentBalanced && leftSubtreeBalanced && rightSubtreeBalanced;
    }
private:
    int getHeight(TreeNode* node) {
        if (node == nullptr) return 0;

        int leftHeight = getHeight(node -> left);
        int rightHeight = getHeight(node -> right);

        return 1 + max(leftHeight, rightHeight);
    }
};