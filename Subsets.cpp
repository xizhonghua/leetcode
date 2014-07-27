class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;
        int s = S.size();
        std::sort(S.begin(), S.end());
        vector<int> cur;
        for(int i=1;i<=s;i++)
            dfs(0,0,i,S,cur,ans);
        ans.push_back(cur);
        return ans;
    }
    
    void dfs(int s, int d, int n, const vector<int>& S, vector<int>& cur, vector<vector<int> >& ans)
    {
        if(d==n)
        {
            ans.push_back(cur);
            return;
        }
        for(int i=s;i<S.size();i++)
        {
            cur.push_back(S[i]);
            dfs(i+1, d+1, n, S, cur, ans);
            cur.pop_back();
        }
    }
};
