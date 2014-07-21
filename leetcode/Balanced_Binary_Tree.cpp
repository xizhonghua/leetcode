// Accepted	72 ms	cpp
// Given a binary tree, determine if it is height-balanced.
// 
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


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
    bool isBalanced(TreeNode *root) {
        if(root==NULL) return true;
        int dl = depth(root->left);
        int dr = depth(root->right);
        return abs(dl-dr)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
    
    int depth(TreeNode *root)
    {
        return root==NULL ? 0 : max(depth(root->left), depth(root->right))+1;
    }
};
