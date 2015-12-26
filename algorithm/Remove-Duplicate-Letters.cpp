class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> v(256, false);
        vector<int> f(256, 0);
        deque<char> q;
        
        for(auto c : s)
            ++f[c];
        for(auto c : s) {
            --f[c];
            if(v[c]) continue;
            while(!q.empty() && c < q.back() && f[q.back()]) {
                v[q.back()] = false;
                q.pop_back();
            }
            q.push_back(c);
            v[c] = true;
        }
        
        return string(q.begin(), q.end());
    }
};
