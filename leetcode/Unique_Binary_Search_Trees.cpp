class Solution {
public:
    int numTrees(int n) {
        vector<int> ans(n+1);
        ans[0] = 1;
        for(int i=1;i<=n;i++)
            for(int k=0;k<i;k++)
                ans[i] += ans[k]*ans[i-k-1];
        return ans[n];
    }
};