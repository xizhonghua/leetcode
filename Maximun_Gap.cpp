class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.size() < 2) return 0;
        this->sort(num);
        const auto size = num.size();
        auto maxGap = INT_MIN;
        for(auto i=1u;i<size;i++) 
            maxGap = max(maxGap, num[i] - num[i-1]);
        return maxGap;
    }
private:
    void sort(vector<int> &num) {
        const auto base = 10;
        auto maxNum = INT_MIN;
        for(const auto n : num) maxNum = max(maxNum, n);
                    
        for(auto e=1;e<=maxNum;e*=base) {
            array<vector<int>, base> buckets;
            for(const auto n : num) buckets[ (n / e) % base ].push_back(n);
            auto iter = num.begin();
            for(auto &bucket : buckets)
                for(const auto b : bucket) *(iter++) = b;
        }
    }
};
