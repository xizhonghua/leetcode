class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n == 0) return 0;
        int s = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            s += A[i];
            if(s < 0) s = 0;
            if(s > ans) ans = s;
        }
        
        if(ans == 0) {
            ans = -INT_MAX;
            for(int i=0;i<n;i++)
                ans = max(ans, A[i]);
        }
        
        return ans;
    }
};