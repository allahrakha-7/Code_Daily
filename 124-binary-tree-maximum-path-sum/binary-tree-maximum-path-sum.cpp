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
private:
    int pathSum;

public:
    int maxPathSum(TreeNode* root) {
        pathSum = INT_MIN;
        dfs(root);
        return pathSum;
    
    }

private:
    int dfs(TreeNode* node) {
        // base case
        if (node == nullptr) return 0;

        int maxLeftSum = dfs(node -> left);
        int maxRightSum = dfs(node -> right);

        int leftGain = max(maxLeftSum, 0);
        int rightGain = max(maxRightSum, 0);

        int pathByNode = node -> val + leftGain + rightGain;

        pathSum = max(pathSum, pathByNode);

        return node -> val + max(leftGain, rightGain);
    }
};