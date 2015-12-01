class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        return max(rob_line(nums, 0, nums.size()-2), rob_line(nums, 1, nums.size()-1));
    }
    
    int rob_line(vector<int>& nums, int start, int end) {
        int f1 = nums[start];
        int f2 = 0;
        int opt = nums[start];
        for(int i=start+1;i<=end;++i) {
            opt = max(f2 + nums[i], f1);
            f2 = f1;
            f1 = opt;
        }
        return opt;
    }
};
