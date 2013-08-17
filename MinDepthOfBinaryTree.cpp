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
    int maxD;
    bool found;
    void minD(TreeNode *root, int d)
    {
        if(d>maxD) return;
        if(!root->left && !root->right)
        {
            found = true;
            return;
        }
        if(root->left) minD(root->left, d+1);
        if(root->right) minD(root->right, d+1);
    }
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        if(!root) return 0;
        
        for(int i=1;i<2000;i++)
        {
            this->maxD = i;
            this->found = false;
            this->minD(root, 1);
            if(found) return i;
        }
        return 0;
    }
};