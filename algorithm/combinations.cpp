class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> cur;
        dfs(0,1,n,k,cur,ans);
        return ans;
    }
private:
    void dfs(int d, int s, int n, int k, vector<int>& cur, vector<vector<int> >& ans) {
        if(d==k) { ans.push_back(cur); return;}
        for(int i=s;i<=n;i++)
        {
            cur.push_back(i);
            dfs(d+1,i+1,n,k,cur,ans);
            cur.pop_back();
        }
    }
};