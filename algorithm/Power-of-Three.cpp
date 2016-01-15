class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        int m = pow(3, (int)(log(INT_MAX)/log(3)));
        return m%n==0;
    }
};
