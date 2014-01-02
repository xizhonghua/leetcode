class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag = false;
        if(dividend < 0) flag = !flag;
        if(divisor < 0) flag = !flag;
        
        long long t1 = abs((long long)dividend);
        long long t2 = abs((long long)divisor);
        
        int ans = 0;
        
        for(int i=30;i>=1;i--)
            if(t1 >= (t2<<i)) {
                t1 -= (t2<<i);
                ans += (1<<i);
            }
        
        while(t1 >= t2) {
            t1 -= t2;
            ans++;
        }
        
        return flag ? -ans : ans;
    }
};