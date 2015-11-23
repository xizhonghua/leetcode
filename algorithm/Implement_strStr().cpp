class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int l = strlen(haystack);
        int m = strlen(needle);
        
        if(m==0) return 0;
        
        for(int i=0;i<=l-m;i++)
        {
            int j=0;
            for(j=0;j<m;j++)
            {
                if(needle[j] != haystack[i+j]) break;
            }
            if(j == m) return i;
        }
        
        return -1;
    }
};
