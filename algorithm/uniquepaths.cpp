class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        for(int i=0;i<m;i++)
        {
            vector<int> row;
            for(int j=0;j<n;j++)
                row.push_back(0);
            ans.push_back(row);
        }            
        
        for(int i=0;i<m;i++)
            ans[i][0] = 1;
        for(int j=0;j<n;j++)
            ans[0][j] = 1;
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                ans[i][j] = ans[i-1][j] + ans[i][j-1];
        return ans[m-1][n-1];
    }
};