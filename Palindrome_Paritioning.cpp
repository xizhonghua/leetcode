class Solution {
public:
    bool t(string s)
    {
        int l = s.length();
        
        for(int i=0;i<l/2;i++)
        {
            if(s[i] != s[l-i-1]) return false;
        }
        
        return true;
    }
    
    void p(string& s, int a, vector<vector<string>>& ans, vector<string>& cur)
    {        
        int l = s.length();
        
        if(a == l)
        {
            ans.push_back(cur);
            return;
        }
        
        for(int i=a;i<l;i++)
        {
            string ss = s.substr(a, i-a+1);
            if(t(ss))
            {
                cur.push_back(ss);
                p(s, i+1, ans, cur);
                cur.pop_back();
            }
            
        }
    }
    
    vector<vector<string>> partition(string s) {        
        vector<vector<string> > ans;
        vector<string> cur;
        
        p(s, 0, ans, cur);            
        
        return ans;
        
    }
};