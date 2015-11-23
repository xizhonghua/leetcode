class Solution {
public:
    bool test(string s)
    {
        int l = s.length();
        for(int i=0;i<l/2;i++)
        {
            if(s[i] != s[l-i-1]) return false;
        }
        
        return true;
    }
    
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string t;
        for(int i=0;i<s.length();i++)
        {
            if((s[i] >= 'a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            {
                t += s[i];
            }
            else if(s[i] >= 'A' && s[i]<='Z')
            {
                t += s[i] - 'A' + 'a';
            }
        }
        
        return test(t);
        
    }
};