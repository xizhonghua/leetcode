class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        auto t = matrix;
        int n = matrix.size();
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                matrix[i][j] = t[n-j-1][i];
        
    }
};