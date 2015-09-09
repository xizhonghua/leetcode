class Solution {
public:
    bool isAnagram(string s, string t) {
        // Solution 1: 76ms
        // std::sort(s.begin(), s.end());
        // std::sort(t.begin(), t.end());
        // return s == t;
        
        // Solution 2: 36ms
        // unordered_map<char, int> ms,mt;
        // for(auto c:s) ++ms[c];
        // for(auto c:t) ++mt[c];
        
        // return ms==mt;
        
        // Solution 3: 16ms
        array<unsigned int, 128> ms = {0};
        array<unsigned int, 128> mt = {0};
        for(auto c:s) ++ms[c];
        for(auto c:t) ++mt[c];
        return ms == mt;
        
    }
};
