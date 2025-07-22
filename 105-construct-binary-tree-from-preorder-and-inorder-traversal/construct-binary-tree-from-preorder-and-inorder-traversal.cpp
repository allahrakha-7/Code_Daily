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
    unordered_map<int, int> inOrderMap;

    int preOrderIndex;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // base case
        for (int i = 0; i < inorder.size(); i++) {

            inOrderMap[inorder[i]] = i;
        }
        preOrderIndex = 0;

        return buildTreeHelper(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& preorder, int inOrderStart, int inOrderEnd) {

        if (inOrderStart > inOrderEnd) {

            return nullptr;
        }

        int rootVal = preorder[preOrderIndex++];

        TreeNode* root = new TreeNode(rootVal);

        int rootIndex = inOrderMap[rootVal];

        root -> left = buildTreeHelper(preorder, inOrderStart, rootIndex - 1);

        root -> right = buildTreeHelper(preorder, rootIndex + 1, inOrderEnd);

        return root;
    }
};