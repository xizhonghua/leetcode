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
    void flatten(TreeNode *root) {
        if(root==NULL) return;
        f(root);
    }
    
private:
    TreeNode* f(TreeNode *root) {
        if(!root->left && !root->right) return root;
        TreeNode* r = NULL;
        TreeNode* l = NULL;
        if(root->right) r = f(root->right);
        if(root->left) {
            l = f(root->left);
            root->left = NULL;
            root->right = l;
            while(l->right) l=l->right;
            l->right = r;
        }
        
        return root;
    }
};
