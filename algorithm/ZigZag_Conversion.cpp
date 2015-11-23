class Solution {
public:
    string convert(string s, int nRows) {
        
        if(nRows == 1) return s;
        
        vector<string> ss(nRows);
        auto l = s.length();
        auto x = 0, y = 0, i = 0;
        auto down = true;
        while(i<l){
            ss[y] += s[i];
            
            if(down) {
                y++;
                if(y==nRows) {
                    down = false;
                    y-=2;
                }
            }
            else
            {
                y--;
                if(y<0) {
                    down = true;
                    y = 1;
                }
            }
            
            i++;
        }
        
        string ans;
        for(auto r : ss)
            ans += r;
        
        return ans;
    }

};
