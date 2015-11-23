class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        return findPeakElement(num, 0, num.size()-1);
    }
private:
    int findPeakElement(const vector<int>& num, int l, int r) {
        if(r<=l) return l;
        int mid = (l + r)/2;
        int left = mid-1;
        int right = mid+1;
        int lnum = left < 0 ? INT_MIN : num[left];
        int rnum = right >= num.size()  ? INT_MIN : num[right];
        int mnum = num[mid];
        
        if( mnum > lnum && mnum > rnum) return mid;
        if( rnum > mnum ) return findPeakElement(num, mid+1, r);
        return findPeakElement(num, l, mid-1);
    }
};
