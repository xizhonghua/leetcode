class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = (int)s.length();
        int ll = 0;
        int start = 0;
        array<int, 256> idx;
        idx.fill(-1);
        
        for(int i=0;i<l;++i) {
            if(idx[s[i]] != -1) 
                start = max(start, idx[s[i]]+1);
            
            ll = max(ll, i-start+1);
            idx[s[i]] = i;
        }
        
        return ll;
    }
};
