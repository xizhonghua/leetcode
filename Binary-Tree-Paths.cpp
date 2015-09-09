/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string cur;
        vector<string> ans;
        dfs(root, cur, ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, string cur, vector<string>& ans) {
        if(!root) return;
        
        if(!cur.empty()) cur+="->";
            cur += std::to_string(root->val);
            
        if(!root->left && !root->right) {
            ans.push_back(cur);
            return;
        }
        
        dfs(root->left, cur, ans);
        dfs(root->right, cur, ans);
    }
};
