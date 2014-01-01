class Solution {
public:
    vector<string> ans;
    map<char, string> m;
    
    void dfs(string& digits, int d, int start, string s)
    {
        if(d == digits.length())
        {
            ans.push_back(s);
            return;
        }
        
        string& ss = m[digits[d]];
        for(int i=0;i<ss.length();i++)
        {
            dfs(digits, d+1, 0, s+ss[i]);            
        }
    }
    
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear(); 
        m.clear();
        
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        dfs(digits, 0, 0, "");
        
        
        return ans;
    }
};