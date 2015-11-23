class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0') return *s == '\0';
        
        // normal case
        if(p[1] != '*' || p[1] == '\0')
        {
            // no char to match
            if(*s == '\0') return false;
            
            if(*s==*p || *p=='.')
                return isMatch(s+1, p+1);
            else
                return false;
        }
        else {
            int i=-1;
            while(i==-1 || s[i] == p[0] || p[0] == '.') {
                if(isMatch(s+i+1, p+2)) return true;
                if(s[++i] == '\0') break;
            }
            return false;
        }
        
        
        return false;
    }
};
