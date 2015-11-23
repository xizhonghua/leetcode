class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int c[3];
        c[0] = c[1] = c[2] = 0;
        for(int i=0;i<n;i++)
            if(c[A[i]]++);
        int p=0;
        for(int i=0;i<3;i++)
            while(c[i]--)
                A[p++] = i;                
    }
};