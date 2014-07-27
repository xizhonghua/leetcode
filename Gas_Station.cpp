class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        size_t n = gas.size();
        int left = 0;
        int sum = 0;
        int start = 0;
        
        for (size_t i=0;i<n;i++)
        {
            int diff = gas[i] - cost[i];
            left += diff;
            sum += diff;
            if(sum < 0)
            {
                sum = 0;
                start = i+1;
            }
        }
        
        return left >= 0 ? start : -1;
    }
};
