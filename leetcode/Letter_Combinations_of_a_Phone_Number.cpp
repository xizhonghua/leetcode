class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char> > d(10);
        d[0] = {' '};
        d[1] = {};
        d[2] = {'a','b','c'};
        d[3] = {'d','e','f'};
        d[4] = {'g','h','i'};
        d[5] = {'j','k','l'};
        d[6] = {'m','n','o'};
        d[7] = {'p','q','r','s'};
        d[8] = {'t','u','v'};
        d[9] = {'w','x','y','z'};
        vector<string> ans;
        string cur = "";
        dfs(0, digits, d, cur, ans);
        
        return ans;
    }
private:
    void dfs(int s, const string& digits, vector<vector<char> >& d, string cur, vector<string>& ans)
    {
        if(s == digits.length()) {
            ans.push_back(cur);
            return;
        }
        for(auto c : d[digits[s]-'0'])
            dfs(s+1, digits, d, cur + c, ans);
    }
};