class NumArray {
public:
    NumArray(vector<int> &nums) : s(nums.size()+1, 0), n(nums) {
        std::partial_sum(nums.begin(), nums.end(), s.begin()+1);
    }

    void update(int i, int val) {
        u.push_back(std::make_pair(i, val - n[i]));
        n[i] = val;
        
        if(u.size()>1000) {
            std::partial_sum(n.begin(), n.end(), s.begin()+1);    
            u.clear();
        }
    }

    int sumRange(int i, int j) {
        auto r = s[j+1] - s[i];
        for(const auto& p : u)
            if(p.first>=i && p.first<=j)
                r += p.second;
        return r;
    }
private:
    vector<int> s,n;
    vector<pair<int,int>> u;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
