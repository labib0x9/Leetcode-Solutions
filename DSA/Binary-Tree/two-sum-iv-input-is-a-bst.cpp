// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
 * };u
 */
class Solution {
public:
    void goLeft(TreeNode* root, stack<TreeNode*>& left) {
        while (root) {
            left.push(root);
            root = root->left;
        }
    }

    void goRight(TreeNode* root, stack<TreeNode*>& right) {
        while (root) {
            right.push(root);
            root = root->right;
        }
    }

    int getLeftValue(stack<TreeNode*>& st) {
        if (st.empty()) return 1000000;
        auto x = st.top(); st.pop();
        goLeft(x->right, st);
        return x->val;
    }

    int getRightValue(stack<TreeNode*>& st) {
         if (st.empty()) return -1000000;
         auto x = st.top(); st.pop();
         goRight(x->left, st);
         return x->val;
    }

    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> left, right;
        goLeft(root, left);
        goRight(root, right);

        auto lo = getLeftValue(left); 
        auto hi = getRightValue(right); 

        bool found = false;
        while (lo < hi) {
            cout << lo << " " << hi << endl;
            if (lo + hi > k) {
                hi = getRightValue(right); 
            } else if (lo + hi < k) {
                lo = getLeftValue(left); 
            } else {
                found = true;
                break;
            }
        }

        return found;
    }
};
