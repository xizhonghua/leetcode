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
    vector<vector<int> > ans;
    void dfs(TreeNode *root, int sum, vector<int> path) {
        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            if(sum-root->val == 0) ans.push_back(path);
            return;
        }        
        if(root->left) dfs(root->left, sum-(root->val), path);
        if(root->right) dfs(root->right, sum-(root->val), path);        
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        vector<int> path;
        if(root) dfs(root, sum, path);
        return ans;
    }
};