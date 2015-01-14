class Solution {
public:
    string largestNumber(vector<int> &num) {
        map<int, string> m;
        for(auto n: num)
        {
            stringstream ss;
            ss<<n;
            
            m[n] = ss.str();
            string& s = m[n];
            
            char padding = s.back() < s.front() ? s.front() : s.back();
            
            while(s.length()<12)
                s+= padding;
        }
        
        sort(num.begin(), num.end(), [&m](const int &a, const int &b) { return m[a] > m[b]; });
        
        stringstream ss;
        for(auto n : num) ss<<n;
        
        string s = ss.str();
        
        while(s.length()>1 && s[0] == '0')
            s = s.substr(1);
        
        return s;
    }
};
