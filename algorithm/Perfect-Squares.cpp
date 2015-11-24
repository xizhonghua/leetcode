class Solution {
public:
    int numSquares(int n) {
        auto f = vector<int>(n+1, 0);
        for(int i=1;i<=n;++i) {
            f[i] = i;
            for(int j=1;j<=sqrt(i);++j)
                f[i] = min(f[i], 1 + f[i-j*j]);
        }
        return f[n];
    }
};
