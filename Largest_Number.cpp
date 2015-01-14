class Solution {
public:
    string largestNumber(vector<int> &num) {
        map<int, long long> m;
        for(auto n: num)
        {
            if(n==0) {
                m[n] = 0;
                continue;
            }
            
            long long t = n;
            long long first = t;
            long long last = t % 10;
            while(first>=10) first/=10;
            int padding = last < first ? first : last;
            
            while(t<1e12)
                t = t*10 + padding;
            m[n] = t;
        }
        
        sort(num.begin(), num.end(), [&m](const int &a, const int &b){
           return m[a] > m[b];
        });
        
        stringstream ss;
        for(auto n : num) {
            ss<<n;
        }
        
        string s = ss.str();
        
        while(s.length()>1 && s[0] == '0')
            s = s.substr(1);
        
        return s;
    }
};
