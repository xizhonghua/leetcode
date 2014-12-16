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
    int maxPathSum(TreeNode *root) {
        long long ms = INT_MIN;
        mp(root, ms);
        return ms;
    }
private:
    int mp(TreeNode *root, long long& ms) {
        if(!root) return INT_MIN;
        long long l = mp(root->left, ms);
        long long r = mp(root->right, ms);
        long long v = root->val;
        
        // m has two choices
        // 1. root
        // 2. root + max(left, right)
        long long m = max(v, max(v+l, v+r));
        
        // max_path has 4 choices
        // 1. self
        // 2. m
        // 3. max(l,r)
        // 4. v+l+r
        ms = max(ms, m);
        ms = max(ms, max(l,r));
        ms = max(ms, v+l+r);
        
        return (int)m;
    }
};
