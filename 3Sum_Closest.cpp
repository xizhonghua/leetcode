class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int n = num.size();
        int d = INT_MAX;
        int ans = target;
        for(int i=0;i<n-2;i++)
        {
            int s = i+1, t = n-1;
            
            while(s < t && d)
            {
                int sum = num[i] + num[s] + num[t];
                
                if(sum == target)
                {
                    ans = sum;
                    d = 0;
                    break;
                }
                
                int diff = abs(sum - target);
                
                if(sum > target) {
                    if (diff < d) {
                        d = diff;
                        ans = sum;
                    }
                    t--;
                }
                
                if(sum < target) {
                    if (diff < d) {
                        d = diff;
                        ans = sum;
                    }
                    s++;
                }
                
            } // end while
        } // end for
        
        return ans;
    }
};
