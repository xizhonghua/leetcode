class Solution {
public:
    bool canJump(int A[], int n) {
        
        int max_cover = A[0];
        
        for(int i=0;i<n;i++)
        {
            if (i>max_cover) break;
            max_cover = max(max_cover, i+A[i]);
        }
        
        return max_cover>=n-1;
    }
};
