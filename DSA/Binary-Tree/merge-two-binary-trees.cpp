// https://leetcode.com/problems/merge-two-binary-trees/description/

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

    void merge(TreeNode* parent, TreeNode* root1, TreeNode* root2) {
        if (!parent) return;
        if (root1 && !root2) {
            parent->val = root1->val;
        } else if (!root1 && root2) {
            parent->val = root2->val;
        } else {
            parent->val = root1->val + root2->val;
        }

        if ((root1 && root1->left) || (root2 && root2->left)) {
            parent->left = new TreeNode();
        }
        if ((root1 && root1->right) || (root2 && root2->right)) {
            parent->right = new TreeNode();
        }

        merge(parent->left, root1 ? root1->left : nullptr, root2 ? root2->left: nullptr);
        merge(parent->right, root1 ? root1->right : nullptr, root2 ? root2->right: nullptr);
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        TreeNode* root = new TreeNode();
        merge(root, root1, root2);
        return root;
    }
};