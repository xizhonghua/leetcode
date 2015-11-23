class Solution {
public:
    vector<vector<int> > ans;
    
    void dfs(vector<int>& n, int d, int t, int s, vector<int>& c) {
        if(d==t){
            ans.push_back(c);
            return;
        }
        
        for(int i=s;i<n.size();i++)
        {
            c.push_back(n[i]);
            dfs(n, d+1, t, i+1, c);
            c.pop_back();
        }
    }
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        vector<int> c;
        std::sort(S.begin(), S.end());
        for(int i=0;i<=S.size();i++)
            dfs(S, 0, i, 0, c);
        return ans;
    }
};