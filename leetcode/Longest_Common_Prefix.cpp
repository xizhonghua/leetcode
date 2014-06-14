class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        if(strs[0].size() == 0) return "";
        string ans = "";
        ans += strs[0][0];
        
        int i = -1;

        while(true)
        {
            char c = ans[++i];
            bool flag = true;
            bool added = false;
            for(int j = 0; j<strs.size(); j++) {
                const string& s = strs[j];
                if(s.length() <= i) { flag = false; break; }
                if(s[i] != c) { flag = false; break; }
            }
            if(!flag) break;
            for(string s : strs)
                if(s.length() > i+1 ) { ans += s[i+1]; added = true; break; }
            if(!added) { ans+="$"; break; }
        }
        
        return ans.substr(0, ans.length()-1);
    }
};