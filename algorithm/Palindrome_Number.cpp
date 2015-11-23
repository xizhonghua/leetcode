class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        
        if(x>=10 && x%10 == 0) return false;
        
        int y = 0, t=x;
        while(t>0)
        {
            int r = t%10;
            y=y*10 + r;
            t/=10;
        }
        
        return x==y;
    }
};
