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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // base case
        if (root == nullptr) return {};

        vector<vector<int>> result;

        queue<TreeNode*> que;

        que.push(root);

        while (!que.empty()) {

            int sizeLevel = que.size();

            vector<int> level;

            for (int i = 0; i < sizeLevel; i++) {

                TreeNode* current = que.front();
                
                que.pop();

                level.push_back(current -> val);

                if (current -> left) que.push(current -> left);

                if (current -> right) que.push(current -> right);
            }
            result.push_back(level);
        }
        return result;
    }
};