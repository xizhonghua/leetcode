class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        auto l = s.length();
        if(l<=10) return {};
        
        array<int, 256> km;
        km['A'] = 0;
        km['C'] = 1;
        km['G'] = 2;
        km['T'] = 3; 

        const auto mask = (1<<20)-1;
        auto key = 0;

        vector<string> ans;
        
        for(auto i=0;i<l;++i)
        {
            key = ((key << 2) & mask) | km[s[i]];
            
            if(i<9) continue;
            
            ++m[key];
            
            if(m[key]==2) ans.push_back(s.substr(i-9,10));
        }
        
        return ans;
    }
};
