class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        unordered_map<string, vector<int>> map;
        
        int idx = 0;
        for(const auto& s : strs)
        {
            auto t = s;
            sort(t.begin(), t.end());
            map[t].push_back(idx);
            idx++;
        }
        
        for(const auto& kv : map){
            if(kv.second.size() > 1) {
                for(const auto idx : kv.second)
                    ans.push_back(strs[idx]);
            }
        }
        
        return ans;
    }
};
