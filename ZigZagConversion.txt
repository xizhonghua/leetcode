class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(nRows==1) return s;
        vector<string> ss;
        for(int i=0;i<nRows;i++)
            ss.push_back("");
        
        int r = -1;
        int d = 0;
        for(int i=0;i<s.length();i++)
        {
            if(d==0){
                r++;            
                if(r==nRows-1) { d=1; };
            }else{
                r--;
                if(r==0) { d = 0; }
            }
            ss[r]+=s[i];           
        }
        
        string ans;
        for(int i=0;i<nRows;i++)
            ans+=ss[i];
        return ans;
    }
};