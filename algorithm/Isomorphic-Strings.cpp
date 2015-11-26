class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return boc(s) == boc(t);
    }
private:
    vector<vector<int>> boc(const string& s) {
        unordered_map<char, int> m;
        vector<vector<int>> b(128, vector<int>());
        int idx = 0;
        for(const auto ch : s) {
            if(!m.count(ch)) m[ch] = m.size()-1;
            b[m[ch]].push_back(idx);
            ++idx;
        }
        return b;
    }
};
