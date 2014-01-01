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
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) return false;
        int t = sum - root->val;
        if(!root->left && !root->right && t == 0) return true;
        
        if(hasPathSum(root->left, t)) return true;
        if(hasPathSum(root->right, t)) return true;
        
        return false;
    }
};