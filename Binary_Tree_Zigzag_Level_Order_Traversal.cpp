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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        dfs(root, 1, ans);
        return ans;
    }
    
    void dfs(TreeNode *root, int depth, vector<vector<int> >& ans)
    {
        if(!root) return;
        
        while(ans.size() < depth) ans.push_back(vector<int>());
        
        auto& l = ans[depth-1];
        
        if(depth % 2 == 1)
            l.push_back(root->val);
        else
            l.insert(l.begin(), root->val);
        
        dfs(root->left, depth+1, ans);
        dfs(root->right, depth+1, ans);
    }
};
