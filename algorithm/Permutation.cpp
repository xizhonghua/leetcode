class Solution {
public:
    vector<vector<int> > p;
    set<int> s;
    
    void dfs(vector<int>& num, int d, vector<int>& c)
    {
        if(d == num.size())
        {
            p.push_back(c);
            return;
        }
        for(int i=0;i<num.size();i++)
        {
            if(!s.count(i))
            {
                c.push_back(num[i]);
                s.insert(i);
                dfs(num, d+1, c);
                c.pop_back();
                s.erase(i);
            }
        }
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        s.clear();
        p.clear();
        vector<int> s;
        dfs(num, 0, s);
        return p;
    }
};