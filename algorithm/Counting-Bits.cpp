class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        int t = 1;
        for(int i=1;i<=num;++i) {
            if(i>=t*2) t *= 2;
            ans[i] = ans[i-t]+1;
        }
        return ans;
    }
};
