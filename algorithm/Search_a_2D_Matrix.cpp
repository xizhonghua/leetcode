// 0 minutes ago	Accepted	 56 ms	cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        size_t rows = matrix.size();
        if(rows == 0) return false;
        size_t cols = matrix[0].size();
        int t = 0, d = rows - 1;
        int l = 0, r = cols - 1;
        
        while(t<d)
        {
            size_t mid_row = (t+d)/2;
            if (target < matrix[mid_row][0])
            {
                d = mid_row-1;
            }
            else if (target > matrix[mid_row][cols-1])
            {
                t = mid_row+1;
            }
            else
            {
                t = d = mid_row;
            }
        }
        
        size_t row = t;
        
        while(l<=r)
        {
            size_t mid_col = (l+r)/2;
            if (target == matrix[row][mid_col])
            {
                return true;
            }
            else if (target > matrix[row][mid_col])
            {
                l = mid_col+1;
            }
            else
            {
                r = mid_col-1;
            }
        }
        
        return false;
    }
};
