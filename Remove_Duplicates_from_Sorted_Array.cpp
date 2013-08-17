class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return 0;
        
        int k = A[0], i = 0, a = 0;
        while(i<n)
        {
            while(A[i] == k && i<n) i++;
            A[a] = k;
            if(i<n) k=A[i];
            a++;
        }
        
        return a;
    }
};