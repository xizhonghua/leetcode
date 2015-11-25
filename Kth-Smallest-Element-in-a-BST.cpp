/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int ls = size(root->left);
        int rs = size(root->right);
        if(k==ls+1) return root->val;
        if(k<=ls) return kthSmallest(root->left, k);
        return kthSmallest(root->right, k-ls-1);
    }
private:
    int size(TreeNode* root) {
        if(!root) return 0;
        return 1 + size(root->left) + size(root->right);
    }
};
