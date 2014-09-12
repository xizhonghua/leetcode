class Solution {
public:
    bool isNumber(const char *s) {
        int dot = 0;
        int e = 0;
        int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
        int neg = 0;
        int space = 0;
        int sign = 0;
        
        while(*s != '\0')
        {
            const char c = *s;
            
            if(c >= '0' && c<= '9')
            {
                if(space && n1) return false;
                if(space && (dot || e || sign)) return false;
                if(e==0) n1++; else n2++;
                if(dot==0) n3++; else n4++;
            }
            else if(c == 'e') if (space) return false; else e++;
            else if(c == '.') if (space || e) return false; else dot++;
            else if(c == ' ') {
                if(n1 || dot || e || sign) space++;
            }
            else if(c == '-' || c == '+') {
                if (space) return false;
                if (dot && !e && (n4 || !n1)) return false;
                if (!e && n1 > 0) return false;
                if (e && n2 > 0) return false;
                sign++;
            }
            else
            {
                return false;
            }
            s++;
        }
        
        if(e && (n1 == 0 || n2 == 0)) return false;
        
        return dot <= 1 && e <=1 && n1>0 && sign <= 2;
    }
};
