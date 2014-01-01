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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        this->dfs(root, 0, ans);
        return ans;
    }
private:    
    void dfs(TreeNode *root, int level, vector<vector<int> >& ans) {
        if(!root) return;
        if(ans.size() < level+1) ans.push_back(vector<int>());
        ans[level].push_back(root->val);
        dfs(root->left, level+1, ans);
        dfs(root->right, level+1, ans);
    }
};