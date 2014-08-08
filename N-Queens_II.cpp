class Solution {
public:
    int totalNQueens(int n) {
        this->m_n = n;
        this->m_ans = 0;
        
        auto cols = vector<int>(n);
        auto d1 = vector<int>(2*n-1);
        auto d2 = vector<int>(2*n-1);
        
        dfs(0, cols, d1, d2);
        
        return this->m_ans;
    }
    
    void dfs(int d, vector<int> cols, vector<int> d1, vector<int> d2)
    {
        if(d == this->m_n) { this->m_ans++; return; }
        
        for(int i=0;i<this->m_n;i++)
        {
            int i1 = i, i2 = d + i, i3 = d-i+this->m_n-1;
            if(cols[i1] || d1[i2] || d2[i3]) continue;
            auto cols_new = cols;
            auto d1_new = d1;
            auto d2_new = d2;
            
            cols_new[i1] = d1_new[i2] = d2_new[i3] = 1;
            
            dfs(d+1, cols_new, d1_new, d2_new);
        }
    }
private:
    int m_n;
    int m_ans;
};
