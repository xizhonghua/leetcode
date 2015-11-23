class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int r = matrix.size();
        if(r==0) return;
        int c = matrix[0].size();
        
        sum = vector<vector<int>>(r+1, vector<int>(c+1, 0));
        
        for(int i=0;i<r;++i)
        {
            int sum_c = 0;
            for(int j=0;j<c;++j) {
                sum_c += matrix[i][j];
                sum[i+1][j+1] = sum[i][j+1] + sum_c;
            }
        }
        
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1] + sum[row1][col1];
    }
private:
    vector<vector<int>> sum;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
