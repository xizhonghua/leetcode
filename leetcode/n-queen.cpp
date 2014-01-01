class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> cur;
        
        col.clear();
        d1.clear();
        d2.clear();
        
        for(int i=0;i<2*n+1;i++)
        {
            col.push_back(false);
            d1.push_back(false);
            d2.push_back(false);
        }
        
        
        for(int i=0;i<n;i++) {
        	cur.push_back(string(n, '.'));
        }
        
        dfs(0, n, ans, cur);
        
        return ans;
    }
    
    
private:
    void dfs(int r, int n, vector<vector<string> >& ans, vector<string>& cur)
    {
        if(r==n) {
            ans.push_back(cur);
            return;
        }
        
        for(int c=0;c<n;c++) {
            if(col[c] || d1[c-r+n] || d2[r+c]) continue;
            col[c] = d1[c-r+n] = d2[r+c] = true;
            cur[r][c] = 'Q';
            dfs(r+1, n, ans, cur);
            cur[r][c] = '.';
            col[c] = d1[c-r+n] = d2[r+c] = false;
        }
    }
    
    vector<bool> col;
    vector<bool> d1;
    vector<bool> d2;
};