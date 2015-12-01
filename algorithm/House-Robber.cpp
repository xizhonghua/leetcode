class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        int f1 = max(nums[0],nums[1]);
        int f2 = nums[0];
        int current = -1;
        for(int i=2;i<nums.size();++i) {
            current = max(f2 + nums[i], f1);
            f2 = f1;
            f1 = current;
        }
        
        return current;
    }
};
