// Accepted	92 ms	cpp
// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


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
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        
        bool s = true;
        
        if(s && root->left)
            s = s && (root->val > maxNode(root->left));
        if(s && root->right) 
            s = s && (root->val < minNode(root->right));
        
        return s && isValidBST(root->left) && isValidBST(root->right);
    }
    
    int maxNode(TreeNode *root)
    {
        if(!root) return INT_MIN;
        return max(root->val, max(maxNode(root->left), maxNode(root->right)));
    }
    
    int minNode(TreeNode *root)
    {
        if(!root) return INT_MAX;
        return min(root->val, min(minNode(root->left), minNode(root->right)));
    }
};
