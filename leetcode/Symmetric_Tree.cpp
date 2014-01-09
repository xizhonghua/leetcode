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
    bool isSymmetric(TreeNode *root) {
        vector<vector<int> > t;
        preorder(0, root, t);
        for(auto l : t) {
            int size = l.size();
            for(int i=0;i<size/2;i++)
                if(l[i] != l[size-i-1]) return false;
        }
        return true;
    }
private:
    void preorder(int d, TreeNode *root, vector<vector<int> >& t) {
        while(t.size() < d+1) t.push_back(vector<int>());
        if(!root) { t[d].push_back(INT_MAX); return; }
        t[d].push_back(root->val);
        preorder(d+1, root->left, t);
        preorder(d+1, root->right, t);
    }
};