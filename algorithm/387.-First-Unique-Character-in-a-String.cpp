class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> c(26, 0);
        for(int i=0;i<s.length();++i) ++c[s[i]-'a'];
        for(int i=0;i<s.length();++i) 
            if(c[s[i]-'a']==1) return i;
        return -1;
    }
};
