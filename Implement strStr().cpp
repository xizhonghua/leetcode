class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!haystack || !needle) return NULL;
        int l1 = strlen(haystack);
        int l2 = strlen(needle);
        if(l2 > l1) return NULL;
        
        for(int i=0;i<l1-l2+1;i++)
        {
            bool found = true;
            for(int j=0;j<l2;j++) 
                if(haystack[i+j] != needle[j]) {
                    found = false;
                    break;
                }
            if(found) return haystack+i;
        }
        
        return NULL;
    }
};