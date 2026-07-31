// https://leetcode.com/problems/path-sum-ii

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
    vector<vector<int>> paths;
    vector<int> path;
    int sum;
public:

    void dfs(TreeNode* root, int targetSum) {
        if (!root) return;
        sum += root->val;
        path.push_back(root->val);

        dfs(root->left, targetSum);
        dfs(root->right, targetSum);

        if (sum == targetSum && !root->left && !root->right) {
            paths.push_back(path);
        }

        sum -= root->val;
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        sum = 0;
        dfs(root, targetSum);
        return paths;
    }
};