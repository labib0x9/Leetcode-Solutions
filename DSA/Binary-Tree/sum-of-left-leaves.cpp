// https://leetcode.com/problems/sum-of-left-leaves/
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

    int dfs(TreeNode* root, bool left) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            return (left ? root->val : 0);
        }
        return dfs(root->left, 1) + dfs(root->right, 0);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, 0);
    }
};