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
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }
    
private:
    vector<int> dfs(TreeNode* node, int distance, int& count) {
        if (!node) return {};
        
        if (!node->left && !node->right) return {1};

        vector<int> leftDistances = dfs(node->left, distance, count);
        vector<int> rightDistances = dfs(node->right, distance, count);

        for (int lDist : leftDistances) {
            for (int rDist : rightDistances) {
                if (lDist + rDist <= distance) {
                    count++;
                }
            }
        }

        vector<int> currentDistances;
        for (int lDist : leftDistances) {
            if (lDist + 1 < distance) {
                currentDistances.push_back(lDist + 1);
            }
        }
        for (int rDist : rightDistances) {
            if (rDist + 1 < distance) {
                currentDistances.push_back(rDist + 1);
            }
        }
        
        return currentDistances;
    }
};