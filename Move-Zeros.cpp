class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c = 0;
        for(int i=0;i<nums.size();++i) {
            if(nums[i] == 0) {
                ++c;
            } else {
                std::swap(nums[i-c], nums[i]);
            }
        }
    }
};
