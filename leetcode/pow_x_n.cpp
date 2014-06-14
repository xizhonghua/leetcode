class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double ans = 1.0;
        
        if(x == 1)
        {
            return 1;
        }
        else if(x==-1)
        {
            return n%2 == 0 ? 1 : -1;
        }
        
        for(int i=0;i<n;i++)
        {
            ans*=x;
            if(fabs(ans-0.0) < 1e-10) break;
        }
        
        for(int i=0;i>n;i--)
            ans/=x;
        return ans;
        
    }
};