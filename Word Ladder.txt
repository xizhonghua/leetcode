class Solution {
public:
    bool adj(string s1, string s2)
    {
        int c = 0;
        for(int i=0;i<s1.length();i++)        
            if(s1[i] != s2[i]) { c++; if(c>1) return false;}
        return c==1;
    }
    
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<string> q;
        map<string, int> l;
        
        q.push(start);
        l[start] = 1;
        
        while(!q.empty())
        {
            string w = q.front();
            q.pop();
            if(adj(w,end)) return l[w]+1;
            for(int i=0;i<w.length();i++)
            {
                for(int j='a';j<='z';j++)
                {
                    string t = w;                    
                    if(w[i] == 'j') continue;
                    t[i] = j;
                    if(!dict.count(t)) continue;                                
                    if(l[t]) continue;
                    if(adj(w,t))
                    {
                        q.push(t);
                        l[t] = l[w]+1;
                    }
                }
            }
        }
        return 0;
    }
};