// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
    bool found = false;
public:
    int dfs(TreeNode* root, int& k) {
        if (!root || found) return -1;
        int l = dfs(root->left, k);

        k--;
        if (k == 0) {
            return root->val;
        }

        int r = dfs(root->right, k);
        return max(l, r);
    }

    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }
};