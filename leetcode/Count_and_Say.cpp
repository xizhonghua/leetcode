class Solution {
public:
    string countAndSay(int n) {
        string sn = "1";
        for(int i=1;i<n;i++)
            sn = say(sn);
        return sn;
    }
    
    string say(string n)
    {
        string s;
        int j = 0, l = n.length();
        for(int i=1;i<=l;i++)
        {
            if(i==l || n[i]!=n[j]) {
                int count  = (i-j);
                s += ('0' + count);
                s += n[j];
                j = i;
            }
        }
        
        return s;
        
    }
};
