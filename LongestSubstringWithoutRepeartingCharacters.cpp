class Solution {
public:    
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0;
        set<char> c;
        for(int i=0;i<s.length();i++)
        {
            c.clear();
            for(int j=i;j<s.length();j++)
            {
                if(c.count(s[j])) break;
                c.insert(s[j]);
                if(j-i + 1> l) l = j-i+1;
            }
        }
        
        return l;
    }
};