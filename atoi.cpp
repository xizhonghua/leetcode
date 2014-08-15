
class Solution {
public:
    int atoi(const char *str) {
        long long ans = 0;
        int neg = 0;
        int pos = 0;
        bool p = false;
        bool a = false;
        bool n = false;
        while(str)
        {
            if(*str == '\0') break;
            else if(*str == ' ') { if(n || neg || pos) break; }
            else if(*str == '-') neg++;
            else if(*str == '+') pos++;
            else if(*str == '.') p = true;
            else if(*str >= '0' && *str <= '9' && !p && !a)
            {
                ans = ans*10 + (*str-'0');
                n = true;
            }
            else
            {
                a = true;
            }
            
            str++;
        }
        
        if(neg) ans = -ans;
        
        if(ans > INT_MAX) ans = INT_MAX;
        if(ans < INT_MIN) ans = INT_MIN;
        
        if(pos + neg > 1) ans = 0;
        
        return ans;
    }
};
