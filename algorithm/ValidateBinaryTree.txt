/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool t(TreeNode *root, int l, int h) {     
        if(!root) return true;
        if(root->val > l && root->val < h)
            return t(root->left, l, root->val) && t(root->right, root->val, h);
        return false;
    }
    bool isValidBST(TreeNode *root) {
        return t(root, INT_MIN, INT_MAX);
    }
};