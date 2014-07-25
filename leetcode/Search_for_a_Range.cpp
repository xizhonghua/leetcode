class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int pos;
        if (!find(A,n,target,pos)) return {-1,-1};
        
        int lb, ub;
        
        find(A,n,target-1, lb);
        find(A,n,target+1, ub);
        
        while(lb<pos && A[lb]!=target) lb++;
        while(ub>pos && A[ub]!=target) ub--;
        
        return {lb, ub};
    }
    
    bool find(int A[], int n, int target, int& pos)
    {
        int l = 0, r = n-1;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            int mv = A[mid];
            
            if(mv < target) { l = mid+1; continue; }
            if(mv > target) { r = mid-1; continue; }
            
            pos = mid;
            return true;
        }
        
        pos = (l+r)/2;
        
        return false;
    }
};
