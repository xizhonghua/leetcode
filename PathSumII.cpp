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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> path;
        vector<vector<int> > ans;
        dfs(root, sum, path, ans);
        return ans;
    }
private:
    void dfs(TreeNode *root, int sum, vector<int>& path, vector<vector<int> >&ans) {
        if(!root) return;
        
        path.push_back(root->val);
        
        int left = sum - root->val;
        
        if(root->left || root->right)
        {
            dfs(root->left, left, path, ans);
            dfs(root->right, left, path, ans);
        }
        else {
            if(left == 0) ans.push_back(path);
        }
        path.pop_back();
        
        
    }
};