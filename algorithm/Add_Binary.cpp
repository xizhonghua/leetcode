class Solution {
public:
    string addBinary(string a, string b) {
        string m;
        if(b.length() > a.length()) { m = a; a = b; b = m; }
        a = "0" + a;
        int l = a.length();
        while(b.length()<l) b = "0" + b;
        
        for(int i=1;i<l;i++)
        {
            a[l-i] += (b[l-i] - '0');
            if(a[l-i] >= '2') { a[l-i] -= 2; a[l-i-1]++; }
        }
        
        if(a[0] == '0') a = a.substr(1);
        
        return a;
    }
};