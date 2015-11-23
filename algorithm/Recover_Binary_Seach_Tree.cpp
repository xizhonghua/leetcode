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
    void recoverTree(TreeNode *root) {
        delete prev;
        prev = new TreeNode(INT_MIN);
        first = second = NULL;
        inorder(root);
        swap(first->val, second->val);
    }
    
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
            
        if(!first && prev->val > root->val)
            first = prev;
            
        if(first && prev->val > root->val)
            second = root;
        
        prev = root;
        
        inorder(root->right);
    }
private:
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev;
};
