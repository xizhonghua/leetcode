class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> f(n+2, vector<int>(n+2));
        
        for(int l=2;l<=n;++l) {
            for(int i=1;i<=n-l+1;++i) {
                int j = i+l-1;
                f[i][j] = min(i + f[i+1][j], j + f[i][j-1]);
                for(int k=i+1;k<j;k++) 
                    f[i][j] = min(f[i][j], k + max(f[i][k-1], f[k+1][j]));
            }
        }
                    
        return f[1][n];
    }
};
