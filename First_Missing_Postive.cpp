/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i=0;
        while(i<n)
        {
            if(A[i]!=(i+1) && A[i] <= i && A[i]>0 && A[A[i]-1] != A[i])
                swap(A[A[i]-1], A[i]);
            else i++;
        }
        
        for(int j=0;j<n;j++)
            if(A[j]!=(j+1)) return j+1;
        
        return n+1;
    }
};
