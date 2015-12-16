class Solution {
public:
    int maxProduct(vector<string>& words) {
        const int n = words.size();
        if(n<2) return 0;
        vector<int> v(n);
        for(int i=0;i<n;++i) {
            const auto& w = words[i];
            for(int j=0;j<w.length();++j) {
                int b = w[j]-'a';
                v[i] |= (1<<b);
            }
        }
        size_t ans = 0;
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j) {
                if(v[i]&v[j]) continue;
                ans = max(ans, words[i].length()*words[j].length());
            }
        return ans;
    }
};
