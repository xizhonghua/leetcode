class Solution {
public:
    void comb(int n, int k, int d, int s, vector<vector<int> >& c, vector<int>& t)
    {
        if(d == k)
        {
            c.push_back(t);
            return;
        }
        
        for(int i=s+1;i<=n;i++)
        {
            t.push_back(i);
            comb(n, k, d+1, i, c, t);
            t.pop_back();
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > c;
        vector<int> t;
        comb(n, k, 0, 0, c, t);
        return c;
    }
};