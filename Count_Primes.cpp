// 0 minutes ago	Accepted	60 ms	cpp
class Solution {
public:
    int countPrimes(int n) {
        auto f = vector<char>(n+1, 1);
        f[0] = f[1] = false;
        for(long i=2;i<=sqrt(n);++i)
        {
            if(!f[i]) continue;
            for(long j=i*i;j<=n;j+=i)
                f[j] = false;
        }
        int ans = 0;
        for(int i=0;i<n;++i)
            if(f[i]) ++ans;
        return ans;
    }
};
