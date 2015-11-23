class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        size_t n = S.size();
        vector<vector<int> > ans;
        set<vector<int> > h;
        vector<int> cur;
        
        ans.push_back(vector<int>());
        
        for(int i=1;i<=n;i++)
            dfs(0, i, 0, n, S, cur, ans, h);
        
        return ans;
    }
    
    void dfs(int depth, int t, int s, int n, vector<int>& S, vector<int>& cur, vector<vector<int> >& ans, set<vector<int> >& h)
    {
        if(depth == t) {
            if (!h.count(cur)) { ans.push_back(cur); h.insert(cur); }
            return;
        }
        
        for(int i=s;i<n;i++)
        {
            cur.push_back(S[i]);
            dfs(depth+1, t, i+1, n, S, cur, ans, h);
            cur.pop_back();
        }
    }
};
