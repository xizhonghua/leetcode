class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> q;
        int start = 0;
        int ans = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
                q.push(i);
            else if(s[i] == ')')
            {
                if(q.empty()) start = i+1;
                else {
                    int index = q.top();
                    q.pop();
                    if(q.empty())
                        ans = max(ans, i - start+1);
                    else
                        ans = max(ans, i - q.top());
                }
            }
        }
        return ans;
    }
};
