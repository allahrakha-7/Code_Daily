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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet (to_delete.begin(), to_delete.end());
        vector<TreeNode*> Forest;

        root = removeNodes(root, toDeleteSet, Forest);
        if (root) {
            Forest.push_back(root);
        }
        return Forest;
    }
private:
    TreeNode* removeNodes (TreeNode* Node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& Forest) {
        if (!Node) {
            return nullptr;
        }
        Node->left = removeNodes(Node->left, toDeleteSet, Forest);
        Node->right = removeNodes(Node->right, toDeleteSet, Forest);

        if (toDeleteSet.count(Node->val)) {
            if (Node->left) {
                Forest.push_back(Node->left);
            }
            if (Node->right) {
                Forest.push_back(Node->right);
            }
            delete Node;
            return nullptr;
        }
        return Node;
    }
};