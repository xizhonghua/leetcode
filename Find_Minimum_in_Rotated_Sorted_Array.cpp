class Solution {
public:
    int findMin(vector<int> &num) {
        return findMin(num, 0, num.size()-1);
    }
    
    int findMin(const vector<int>& num, int l, int r)
    {
        if(l+1 >= r) return min(num[l], num[r]);
        int m = (l+r)>>1;
        int vl = num[l];
        int vr = num[r];
        int vm = num[m];
        
        if(vl < vm && vm < vr) return vl;
        
        return min(findMin(num,l,m-1), findMin(num,m,r));
    }
};
