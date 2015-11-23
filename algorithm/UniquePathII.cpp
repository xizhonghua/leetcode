class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int> > ans;
        for(int i=0;i<m;i++)
        {
            vector<int> row;
            for(int j=0;j<n;j++)
                row.push_back(0);
            ans.push_back(row);
        }
        
        ans[0][0] = 1 - obstacleGrid[0][0];
        
        for(int i=1;i<m;i++)        
            ans[i][0] = (1 - obstacleGrid[i][0])*ans[i-1][0];        
        for(int j=1;j<n;j++)
            ans[0][j] = (1 - obstacleGrid[0][j])*ans[0][j-1];
            
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
            {
                ans[i][j] = (obstacleGrid[i-1][j] ? 0 : ans[i-1][j]) + 
                            (obstacleGrid[i][j-1] ? 0 : ans[i][j-1]);
                if(obstacleGrid[i][j]) ans[i][j] = 0;
            }
        return ans[m-1][n-1];
        
    }
};