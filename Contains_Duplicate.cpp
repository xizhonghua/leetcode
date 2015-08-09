// 0 minutes ago	Contains Duplicate	Accepted	48 ms	cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s; // 1x faster than set<int>
        for(const auto n : nums) {
            if(s.count(n)) return true;
            s.insert(n);
        }
        return false;
    }
};
