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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return 0;
        
        int l = 0, r = 0;
        
        if(!root->left && !root->right) return root->val;
        if(root->left) 
            l = root->val*10 + sumNumbers(root->left);        
        if(root->right) 
            r = root->val*10 + sumNumbers(root->right);       
        
        
        return l+r;        
    }
};