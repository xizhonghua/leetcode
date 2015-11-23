class Solution {
public:
    bool check(string s)
    {
        for(int i=0;i<s.length()/2;i++)
            if(s[i] != s[s.length()-i-1]) return false;
        return true;
    }
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ans;
        int m = 0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=s.length()-1;j>=i;j--)
            {
                if(s[i] != s[j]) continue;
                string t = s.substr(i, j-i+1);
                if(check(t))
                {
                    if(t.length() > m)
                    {
                        m = t.length();
                        ans = t;
                    }
                    break;
                }
            }
        }
        
        return ans; 
    }
};