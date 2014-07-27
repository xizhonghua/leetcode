class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int curMax = 0;
        int curMin = 1e9;
        int profit = 0;
        for(int i=0;i<prices.size();i++)
        {
            curMax = std::max(curMax, prices[i]);
            if(curMin > prices[i])
            {
                curMin = curMax = prices[i];
            }
            profit = std::max(profit, curMax - curMin);
        }
                
        return profit;
        
    }
};