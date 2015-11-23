// 1 minute ago	Accepted	16 ms	cpp
class Solution {
public:
    int maxProduct(int A[], int n) {
        
        if(n==0) return 0;
        if(n==1) return A[0];
        
        vector<int> pos(n+1);
        vector<int> neg(n+1);
        
        pos[0] = -1;
        neg[0] = 1;
        
        int ans = INT_MIN;
        
        for(int i=1;i<=n;i++)
        {
            int num = A[i-1];
            
            if(num>0)
            {
                pos[i] = max(num, pos[i-1]*num);
                neg[i] = min(num, neg[i-1]*num);
            }
            else if(num<0)
            {
                pos[i] = max(num, neg[i-1]*num);
                neg[i] = min(num, pos[i-1]*num);
            }
            
            ans = max(ans, pos[i]);
        }
        
        return ans;
    }
};
