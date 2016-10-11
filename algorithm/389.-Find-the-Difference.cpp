class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> c(26, 0);
        for(int i=0;i<s.length();++i) {
            --c[s[i]-'a'];
            ++c[t[i]-'a'];
        }
        ++c[t[t.length()-1]-'a'];
        for(int i=0;i<26;++i)
            if(c[i]) return i+'a';
        return '?';
    }
};
