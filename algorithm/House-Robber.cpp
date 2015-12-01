class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int f1 = nums[0];
        int f2 = 0;
        int opt = nums[0];
        for(int i=1;i<nums.size();++i) {
            opt = max(f2 + nums[i], f1);
            f2 = f1;
            f1 = opt;
        }
        
        return opt;
    }
};
