class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.count(s) || s.length() == 0) return true;
        for(unordered_set<string>::iterator it=dict.begin(); it!=dict.end(); ++it) {
            const string& w = *it;
            if(s.length() < w.length()) continue;
            int i=0;
            while(s.compare(i, w.length(), w) == 0) { i+= w.length();}
            if(i==0) continue;
            if(wordBreak(s.substr(i), dict)) return true;
            
        }
        return false;
    }
};