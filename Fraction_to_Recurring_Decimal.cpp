class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        stringstream ss,ss2;
        
        long long n = numerator;
        long long d = denominator;
        
        if(n>0 && d<0 || n<0 && d>0)
        {
            ss<<"-";
            n = abs(n);
            d = abs(d);
        }
        
        ss<<(n/d);
        
        long long r = n % d;
        
        bool loop = false;
        int count = 0;
        int loop_start;
        
        if(r != 0)
        {   
            n = r;
            ss<<".";
        
            map<int, int> rs;
            
            rs[r] = 0;
            
            while(r!=0) {
                n = n*10;
                r = n % d;
                
                ss2<<(n/d);
                n = r;
                
                if(r && rs.count(r)) {
                    loop = true;
                    loop_start = rs[r];
                    break;
                }
                
                rs[r] = ++count;
            }
            
            if(loop) {
                auto s2 = ss2.str();
                ss << s2.substr(0, loop_start) << "(" << s2.substr(loop_start) << ")";
            }
            else
                ss << ss2.str();
        }
        
        return ss.str();
    }
};
