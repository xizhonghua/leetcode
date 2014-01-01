class Solution {
public:
    int s(int x, int l, int r)
    {
        
        if(r-l <= 1) 
        {
            if(r*r <=x ) return r;
            return l;
        }
        
        int mid = (l+r)/2;
        
        long long temp = mid*mid;
        
        if(temp == x)
        {
            return mid;
        }
        else if(temp < x)
        {
            return s(x, mid, r);
        }
        else
        {
            return s(x, l, mid);
        }
    }
    
    int sqrt(int x) {
        return s(x, 0, 46340);
    }
};