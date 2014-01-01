class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a = 0;
        bool n = x < 0;
        if(x<0) x = -x;
        
        vector<int> v;
        
        while(x>0)
        {
            v.push_back(x%10);
            x/=10;
        }
        
         
        for(int i=0;i<v.size();i++)
        {
            a += v[i];
            a*=10;
        }
        
        a/=10;
        
        return n ? -a : a;
        
    }
};