class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int c = 0;
        bool flag = false;
        while(*s != '\0') {
            if(*s == ' ') { flag = true; }
            else {
                if (flag) { c = 1; flag = false; }
                else c++;
            }
            s++;
        }
        
        return c;
    }
};