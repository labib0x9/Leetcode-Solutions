// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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

    void dfs(TreeNode* parent, int* sum, int num) {
        if (parent == nullptr) {
            return;
        }
        num = num * 10 + parent->val;
        dfs(parent->left, sum, num);
        dfs(parent->right, sum, num);
        if (parent->left == nullptr && parent->right == nullptr) {
            *sum += num;
        }
        num /= 10;
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, &sum, 0);
        return sum;
    }
};