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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, postorder, 0, (int)inorder.size()-1, 0, (int)postorder.size()-1);
    }
private:
    TreeNode* buildTree(vector<int> &i, vector<int> &p, int is, int ie, int ps, int pe) {
        
        if(ps > pe) return NULL;
        
        int im = -1;
        for(int k=is;k<=ie;k++) {
            if(i[k] == p[pe]) { 
                im = k; 
                break;
            }
        }
        
        int lc = (im - is) - 1;
        
        auto root = new TreeNode(p[pe]);
        root->left  = buildTree(i, p, is,   im-1, ps,      ps+lc);
        root->right = buildTree(i, p, im+1, ie,   ps+lc+1, pe-1);
    }
};
