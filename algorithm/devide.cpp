class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool s = (divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0);
        
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        
        if(b > a) return 0;
        
        int ans = exp(log(a) - log(b));
        
        return s ? -ans : ans;
        
    }
};