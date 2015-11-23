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
    void build(vector<int>& num, int l, int r, TreeNode *root) {
        if(r-l==0)
        {
            root->val = num[r];
            return;
        }
        int m = (l+r)>>1;        
        root->val = num[m];
        if(l<m) {            
            root->left = new TreeNode(0);
            build(num, l, m-1, root->left);
        }
        if(m<r) {
            root->right = new TreeNode(0);
            build(num, m+1, r, root->right);
        }
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size()==0) return NULL;
        TreeNode *root = new TreeNode(0);
        build(num, 0, num.size()-1, root);
        return root;
    }
};