// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

class Solution {
public:
    int search(int A[], int n, int target) {
        return s(A, 0, n-1, target);
    }
    
    int s(int A[], int l, int r, int target)
    {
        if(l>r) return -1;
        if(l==r) return target == A[l] ? l : -1;
        
        int mid = (l+r)>>1;
        
        if(A[l] < A[mid] && A[mid] < A[r])
            return (target <= A[mid]) ? s(A, l, mid, target) : s(A, mid+1, r, target);
        else
        {
            int i1 = s(A,l,mid,target);
            int i2 = s(A,mid+1,r,target);
            return i1==-1 ? i2 : i1;
        }
    }
};
