class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int la = a.length();
        int lb = b.length();
        int lmin = std::min(la, lb);
        int lmax = std::max(la, lb);       
        
        string c;
        for(int i=0;i<=lmax;i++)
            c += "0";        
        
        for(int i=0;i<lmin;i++)
        {
            c[lmax-i] = c[lmax-i] - '0' + a[la-i-1] + b[lb-i-1] - '0';
            if(c[lmax-i] == '2')
            {
                c[lmax-i] = '0';
                c[lmax-i-1]++;
            }
            else if(c[lmax-i] == '3')
            {
                c[lmax-i] = '1';
                c[lmax-i-1]++;
            }
        }
        
        for(int i=lmin;i<lmax;i++)
        {
            c[lmax-i] = c[lmax-i] + (la > lb ? a[la-i-1] : b[lb-i-1]) - '0';
            if(c[lmax-i] == '2')
            {
                c[lmax-i] = '0';
                c[lmax-i-1]++;
            }
            else if(c[lmax-i] == '3')
            {
                c[lmax-i] = '1';
                c[lmax-i-1]++;
            }
        }
        
        int p = lmin;
        
        if(c[0] == '0')
        {
            c = c.substr(1, c.length());
        }
        
        return c;
    }
};