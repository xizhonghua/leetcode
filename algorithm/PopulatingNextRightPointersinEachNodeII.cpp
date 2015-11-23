/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<vector<TreeLinkNode*> > ans;
        dfs(0, root, ans);
        for(auto v : ans) {
            for(int i=0;i<v.size()-1;i++) {
                v[i]->next = v[i+1];
            }
        }
    }
    
private:
    void dfs(int d, TreeLinkNode *root, vector<vector<TreeLinkNode*> >& ans) {
        if(root==NULL) return;
        while(ans.size() < d+1) ans.push_back(vector<TreeLinkNode*>());
        ans[d].push_back(root);
        dfs(d+1, root->left, ans);
        dfs(d+1, root->right, ans);
    }
};