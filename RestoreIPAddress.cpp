class Solution {
public:
    vector<string> ans;
    void dfs(string s, string ip, int d)
    {
        if(d==4)
        {
            if(s.length()==0) ans.push_back(ip);
            return;
        }
        
        int ml = std::min(3, (int)s.length());
        for(int i=1;i<=ml;i++)
        {
            string ss = s.substr(0, i);
            if(ss.length()>1 && ss[0] == '0') continue;
            if(ss.length()==3)
            {
                if(ss[0] > '2') continue;
                if(ss[0] == '2')
                {
                    if(ss[1] > '5') continue;
                    if(ss[1] == '5') if(ss[2]>'5') continue;
                }
            }
            if(ip.length()==0)
                dfs(s.substr(i, 100), ss, d+1);
            else
                dfs(s.substr(i, 100), ip+"."+ss, d+1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        dfs(s, "", 0);
        return ans;
    }
};