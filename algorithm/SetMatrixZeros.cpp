class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if(m==0) return;
        int n = matrix[0].size();
        if(n==0) return;
        
        set<int> r,c;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(matrix[i][j]==0) {
                    r.insert(i);
                    c.insert(j);
                }
        for(set<int>::iterator it=r.begin(); it!=r.end(); ++it) 
            for(int j=0;j<n;j++) matrix[*it][j] = 0;
        for(set<int>::iterator it=c.begin(); it!=c.end(); ++it) 
            for(int i=0;i<m;i++) matrix[i][*it] = 0;
    }
};