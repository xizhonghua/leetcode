class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return 0;
        if(n==1) return 1;
        
        int c=2;
        for(int i=2;i<n;i++)
        {
            if(A[i] == A[c-1] && A[i] == A[c-2]) continue;
            A[c++] = A[i];
        }
        return c;
    }
};