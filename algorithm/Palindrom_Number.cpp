class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x<0) return false;
        
        while(x>=10)
        {
            double t = x;
            if(t<0) t*=-1;
            double b = pow(10, int(log(t)/log(10)));
            if(b>x) b/=10;
            int f = t/b;
            int l = x % 10;
            if(f!=l) return false;
            x -= f*b;
            x /= 10;
            
            b/=100;
            while(b>x)
            {
                if(x%10!=0) return false;
                x/=10;
                b/=100;
                
            }
        }
        
        return true;
        
    }
};