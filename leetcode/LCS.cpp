class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> m;
        
        int l = 0;
        
        for(int i=0;i<num.size();i++)
        {
            int t = num[i];
            if(m[t]) continue;
            m[t] = 1;
            if(m[t-1] && !m[t+1])
            {
                m[t] = m[t-1]+1;
                m[t-m[t]+1] = m[t];
            }
            else if(m[t+1] && !m[t-1])
            {
                m[t] = m[t+1]+1;
                m[t+m[t]-1] = m[t];
            }
            else
            {                
                m[t] = m[t-1] + m[t+1] + 1;
                m[t-m[t-1]] = m[t+m[t+1]] = m[t];
            }
            if(m[t]>l) l = m[t];
        }
        return l;
    }
};