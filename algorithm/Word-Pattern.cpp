class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        stringstream s(str);
        string word;
        
        while(s>>word) words.push_back(word);
        
        if(pattern.length()!=words.size()) return false;
        
        map<char, string> b;
        map<string, char> c;
        
        for(int i=0;i<pattern.length();++i) {
            const char p = pattern[i];
            const string& w = words[i];
            if(b.count(p) || c.count(w)){
                if(b[p] != w) return false;
                if(c[w] != p) return false;
            } else {
                b[p] = words[i];
                c[w] = p;
            }
        }
        
        return true;
    }
};
