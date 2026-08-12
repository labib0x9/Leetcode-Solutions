// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

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
    int dfs(TreeNode* root, int& first, int& second) {
        if (!root) return 100000000;
        int l = dfs(root->left, first, second);
        first = second;
        second = root->val;
        int diff = abs(first - second);
        int r = dfs(root->right, first, second);
        return min({l, r, diff});
    }

    int getMinimumDifference(TreeNode* root) {
        int first = 1000000, second = 10000000;
        return dfs(root, first, second);
    }
};