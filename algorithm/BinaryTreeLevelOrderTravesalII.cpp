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
    map<int, vector<int> > ans;
    int maxD;
    
    void dfs(TreeNode *root, int d)
    {
        if(!root) return;
        if(d>maxD) maxD = d;
        dfs(root->left, d+1);
        vector<int>& l = ans[d];
        l.push_back(root->val);        
        dfs(root->right, d+1);
        
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        maxD = 0;
        ans.clear();
        dfs(root, 1);
        vector<vector<int> > t;
        for(int i=maxD;i>0;i--)
        {
            t.push_back(ans[i]);
        }
        
        return t;
    }
};