class Solution {
public:
    string extractWord(string& s)
    {
        int i=0, l = s.length();
        while(i<l && s[i] == ' ') i++;
        if(i==l) { s=""; return "";}
        int j=i;
        while((j+1)<l && s[j+1]!=' ') j++;
        string w = s.substr(i, j-i+1);
        int index=i+w.length()+1;
        if(index>=l) 
            s = "";
        else
            s = s.substr(index);
        return w;
    }
    
    void reverseWords(string &s) {
        stack<string> st;
        while(s.length()>0)
        {
            string w = extractWord(s);
            if(w.length()>0) st.push(w);
        }
        string r;
        while(!st.empty())
        {
            r += st.top();
            st.pop();
            if(st.size()>0) r+=" ";
        }
        s = r;
    }
};
