/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        this->m_root = root;
        this->m_stack.push(nullptr);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return m_root != nullptr;
    }

    /** @return the next smallest number */
    int next() {
        if(!m_set.count(m_root)) {
            while(m_root->left) {
                m_stack.push(m_root);
                m_set.insert(m_root);
                m_root=m_root->left;
            }
        }
        int val = m_root->val;
        if(m_root->right) {
            m_root = m_root->right;
        } else {
            m_set.erase(m_root);
            m_root = m_stack.top();
            m_stack.pop();
        }
        return val;
    }
private:
    TreeNode *m_root;
    stack<TreeNode*> m_stack;
    unordered_set<TreeNode*> m_set;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
