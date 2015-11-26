class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a(0),b(0),s(accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>()));
        for(const auto n : nums)
            n & s & -s ? a^=n : b^=n;
        return {a,b};
    }
};
