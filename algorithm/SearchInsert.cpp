class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(target <= A[0]) return 0;
        if(target > A[n-1]) return n;
        for(int i=0;i<n;i++)
        {
            if(target<=A[i]) return i;
        }
        
        return n;
        
    }
};