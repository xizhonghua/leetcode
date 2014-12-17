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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        
        m_pos.clear();
        for(int i=0;i<inorder.size();i++)
            m_pos[inorder[i]] = i;
            
        return buildTree(inorder, preorder, 0, (int)inorder.size()-1, 0, (int)preorder.size()-1);
    }
private:
    TreeNode* buildTree(vector<int> &i, vector<int> &p, int is, int ie, int ps, int pe) {
        
        if(ps > pe) return NULL;
        
        int im = m_pos[p[ps]];
        
        int lc = (im - is);
        
        auto root = new TreeNode(p[ps]);
        root->left  = buildTree(i, p, is,   im-1, ps+1,      ps+lc);
        root->right = buildTree(i, p, im+1, ie,   ps+lc+1, pe);
    }
    unordered_map<int,int> m_pos;
};
