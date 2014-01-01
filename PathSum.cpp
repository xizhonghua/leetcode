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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return false;        
        if(root->left == NULL && root->right == NULL)
        {
            return sum == root->val;
        }
        
        bool l = false, r = false;
        if(root->left)
        {            
            l = hasPathSum(root->left, sum - root->val);
        }
        if(root->right)
        {
            r = hasPathSum(root->right, sum - root->val);
        }
        return l || r;
    }
};