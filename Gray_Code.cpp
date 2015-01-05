class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0) return vector<int>{0};
        if(n==1) return vector<int>{0,1};
        
        auto l = grayCode(n-1);
        auto r = l;
        for(auto& e : r) e |= (1<<(n-1));
        l.insert(l.end(), r.rbegin(), r.rend());
        
        return l;
    }
};
