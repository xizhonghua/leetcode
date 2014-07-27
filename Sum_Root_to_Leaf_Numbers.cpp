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
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        dfs(root, "", sum);
        return sum;
    }
    
    void dfs(TreeNode *root, string s, int& sum) {
        if(!root) return;
        stringstream ss;
        ss << root->val;
        s += ss.str();
        if(!root->left && !root->right)
        {
            ss.str(s);
            int path_sum;
            ss >> path_sum;
            sum += path_sum;
        }
        else{
            dfs(root->left, s, sum);
            dfs(root->right, s, sum);
        }
    }
};