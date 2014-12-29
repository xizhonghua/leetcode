class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        int t=1;
        for(int i=s.length()-1;i>=0;i--) {
            ans += (s[i] - 'A' + 1)*t;
            t*=26;
        }
        return ans;
    }
};
