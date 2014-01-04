class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> cur;
        dfs(s, ans, cur);
        return ans;
    }
    
private:
    void dfs(string s, vector<vector<string> >& ans,  vector<string>& cur) {
        int l = s.length();
        if(l == 0) {
            ans.push_back(cur);
            return;
        }
        for(int i=1;i<=l;i++) {
            bool flag = true;
            for(int j=0;j<i/2 && flag;j++)
                if(s[j] != s[i-j-1]) flag = false;
            if(!flag) continue;
            string ss = s.substr(0, i);
            cur.push_back(ss);
            dfs(s.substr(i), ans, cur);
            cur.pop_back();
        }    
    }
};