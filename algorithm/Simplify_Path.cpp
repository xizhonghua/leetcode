class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int start = 1;
        for(int i=1;i<=path.length();++i)
        {
            if(i == path.length() || path[i] == '/')
            {
                auto p = path.substr(start, i-start);
                if(p == "/") continue;
                if(p == "..") {
                    if(!s.empty()) s.pop();
                } else if(p.length()>0 && p != ".") {
                    s.push(p);
                }
                start = i+1;
            }
        }
        
        string ans;
        while(!s.empty()) {
            ans = (s.size()>1 ? "/" : "") + s.top() + ans;
            s.pop();
        }
        return "/" + ans;
    }
};
