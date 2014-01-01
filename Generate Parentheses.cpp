class Solution {
public:
    void dfs(string p, int l, int r, int n){
        if(r==n) m_ans.push_back(p);
        if(l<n){
            dfs(p+"(", l+1, r, n);
        }
        if(r<l){
            dfs(p+")", l, r+1, n);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        m_ans.clear();
        dfs("", 0, 0, n);
        return m_ans;
    }
private:
    vector<string> m_ans;
};