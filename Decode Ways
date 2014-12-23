class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0) return 0;
        
        m_ways[""] = 1;
        
        return ways(s);
    }

private:    
    int ways(const string& s) {
        
        if(m_ways.count(s)) return m_ways[s];
        
        int w = 0;
        
        if(s[0] == '0') {
            w = 0;
        } 
        else if(s[0] == '1' || (s[0] == '2' && s.length()>1 && (s[1] >= '0' && s[1]<='6'))) {
            w = ways(s.substr(1));
            if(s.length() > 1)
            w += ways(s.substr(2));
        } else {
            w = ways(s.substr(1));
        }
        
        m_ways[s] = w;
        
        return w;
    }

    unordered_map<string, int> m_ways;
};
