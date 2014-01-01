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
    void s(TreeNode *root, string n, int& sum) {
        char buf[2];
        sprintf(buf, "%d", root->val);
        n += string(buf);

        if(!root->left && !root->right) {
            int v = atoi(n.c_str());
            sum += v;
        }
        if(root->left) s(root->left, n, sum);
        if(root->right) s(root->right, n, sum);
    }
    
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        if(root) s(root, "", sum);
        
        return sum;
    }
};