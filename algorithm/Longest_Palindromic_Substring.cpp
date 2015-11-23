class Solution {
public:
    string longestPalindrome(string s) {
        auto l = s.length();
        int best_l = -1;
        string best;
        for(auto i=0u;i<l;i++) {
            // ***abcba*****
            //      ~
            // max_l = 2
            int max_l = min(i, l-i-1);
            if(max_l*2+1 < best_l) continue;
            for(int k=0;k<=max_l;k++)
            {
                int cur_l = 2*k+1;
                if(s[i-k] == s[i+k]) {
                    if(cur_l>=best_l) {
                        best_l = cur_l;
                        best = s.substr(i-k, cur_l);
                    }
                } else {
                    break;
                }
            }
            
            // ***abccba*****
            //      ~
            // max_l = 2
            max_l = min(i, l-i-2);
            if(max_l*2+2 < best_l) continue;
            for(int k=0;k<=max_l;k++)
            {
                int cur_l = 2*k+2;
                if(s[i-k] == s[i+k+1]) {
                    if(cur_l>=best_l) {
                        best_l = cur_l;
                        best = s.substr(i-k, cur_l);
                    }
                } else {
                    break;
                }
            }
            
        }
        return best;
    }
};
