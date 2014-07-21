// Follow up for "Search in Rotated Sorted Array":
// What if duplicates are allowed?

// Would this affect the run-time complexity? How and why?

// Write a function to determine if a given target is in the array.

class Solution {
public:
    bool search(int A[], int n, int target) {
        return s(A, 0, n-1, target);
    }
    
    bool s(int A[], int l, int r, int target)
    {
        if(l>r) return 0;
        if(l==r) return target == A[l];
        
        int mid = (l+r)>>1;
        
        if(A[l] < A[mid] && A[mid] < A[r])
            return (target <= A[mid]) ? s(A, l, mid, target) : s(A, mid+1, r, target);
        else
            return s(A,l,mid,target) || s(A,mid+1,r,target);
    }
};
