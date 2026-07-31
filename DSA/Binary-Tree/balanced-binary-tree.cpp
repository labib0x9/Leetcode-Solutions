// https://leetcode.com/problems/balanced-binary-tree

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
    bool balanced = true;
public:

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        if (balanced == false) return 0;
        int l = dfs(root->left) + 1;
        int r = dfs(root->right) + 1;
        balanced &= abs(r - l) <= 1;
        return max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        dfs(root);
        return balanced;
    }
};