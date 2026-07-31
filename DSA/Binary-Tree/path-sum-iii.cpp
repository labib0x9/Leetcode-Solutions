// https://leetcode.com/problems/path-sum-iii


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

    void dfs(TreeNode* parent, long long pathSum, int targetSum, int* ans,
             map<long long, int> freq) {
        if (parent == nullptr) {
            return;
        }
        pathSum += parent->val;
        *ans += freq[pathSum - targetSum];
        freq[pathSum]++;

        dfs(parent->left, pathSum, targetSum, ans, freq);
        dfs(parent->right, pathSum, targetSum, ans, freq);

        freq[pathSum]--;
        pathSum -= parent->val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        map<long long, int> freq;
        freq[0] = 1;
        int ans = 0;
        dfs(root, 0, targetSum, &ans, freq);
        return ans;
    }
};