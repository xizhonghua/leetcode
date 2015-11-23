class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> a;
        a.reserve(n+1);
        a[0] = 1;
        a[1] = 1;
        
        for(int i=2;i<=n;i++)
        {
            a[i] = a[i-1]+a[i-2];
        }
        
        return a[n];
    }
};