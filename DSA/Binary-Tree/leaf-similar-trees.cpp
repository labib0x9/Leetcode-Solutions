// https://leetcode.com/problems/leaf-similar-trees/description/

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
    void dfs(TreeNode* root, vector<int>& leaves) {
        if (!root) return;
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
            return;
        }
        dfs(root->left, leaves);
        dfs(root->right, leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> root1_leaves, root2_leaves;
        dfs(root1, root1_leaves);
        dfs(root2, root2_leaves);
        return root1_leaves == root2_leaves;
    }
};