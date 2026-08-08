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
    bool dfs(TreeNode* root, long long& l, long long& rt, long long& r,
             int& count) {
        if (!root)
            return true;
        bool lc = dfs(root->left, l, rt, r, count);
        if (count == 0) {
            rt = root->val;
        } else if (count == 1) {
            l = rt, rt = root->val;
        } else if (count == 2) {
            r = root->val;
        } else {
            l = rt, rt = r, r = root->val;
        }
        if (l >= rt || rt >= r)
            return false;
        count++;
        bool rc = dfs(root->right, l, rt, r, count);
        return lc && rc;
    }

    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        if (!root->left && !root->right)
            return true;
        long long l = numeric_limits<long long>::min(), rt = 0ll;
        long long r = numeric_limits<long long>::max();
        int count = 0;
        return dfs(root, l, rt, r, count);
    }
};