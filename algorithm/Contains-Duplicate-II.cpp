class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> w;
        for(int i=0;i<nums.size();++i) {
            if(i>k)
                if (w[nums[i-k-1]] < i-k+1) w.erase(nums[i-k-1]);
            if (w.count(nums[i])) return true;
            w[nums[i]] = i;
        }
        return false;
    }
};
