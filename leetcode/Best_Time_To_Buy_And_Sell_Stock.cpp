class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0) return 0;
        int d = prices.size();
        vector<int> profit;
        profit.resize(d);
        int sum = 0, ans = 0;
        for(int i=1;i<d;i++) 
            profit[i] = prices[i] - prices[i-1];
        for(int i=1;i<d;i++) {
            sum += profit[i];
            if(sum>ans) ans = sum;
            if(sum<0) sum = 0;
        }
        return ans;
    }
};