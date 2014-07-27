class Solution {
public:
    int singleNumber(int A[], int n) {
        int ans = 0;
        for(int s=0;s<32;s++)
        {
            int mask = (1<<s);
            int sum = 0;
            for(int i=0;i<n;i++)
                if(A[i] & mask) sum++;
            if(sum % 3) ans |= mask;
        }
        return ans;
    }
};