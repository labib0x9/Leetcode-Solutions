// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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

    TreeNode* construct(TreeNode* root, vector<int>& nums, int l, int r) {
        if (r < l) return nullptr;
        if (l == r) {
            return new TreeNode(nums[l]);
        }
        int middle = l + (r - l) / 2;
        TreeNode* node = new TreeNode(nums[middle]);

        node->left = construct(node, nums, l, middle - 1);
        node->right = construct(node, nums, middle + 1, r);
        
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return construct(nullptr, nums, 0, nums.size() - 1);
    }
};