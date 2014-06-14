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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ans;
        levelOrderBottom(root, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    void levelOrderBottom(TreeNode *root, int depth, vector<vector<int> >& ans) {
        if(!root) return;
        while(ans.size() < depth+1) ans.push_back(vector<int>());
        ans[depth].push_back(root->val);
        levelOrderBottom(root->left, depth+1, ans);
        levelOrderBottom(root->right, depth+1, ans);
    }
};