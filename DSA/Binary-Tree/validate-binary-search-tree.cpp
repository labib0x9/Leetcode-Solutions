// https://leetcode.com/problems/validate-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, long long minn, long long maxx) {
        if (minn >= root->val || root->val >= maxx)
            return false;
        bool l = true, r = true;
        if (root->left)
            l = dfs(root->left, minn, min(maxx, (long long) root->val));
        if (root->right)
            r = dfs(root->right, max(minn, (long long) root->val), maxx);
        return l & r;
    }

    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        if (!root->left && !root->right)
            return true;
        return dfs(root, numeric_limits<long long>::min(),
                   numeric_limits<long long>::max());
    }
};