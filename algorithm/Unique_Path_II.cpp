class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if(m==0) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int> > f;
        for(int i=0;i<m;i++) f.push_back(vector<int>(n+1));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j] == 1) { f[i][j] = 0; continue; }
                
                if(i==0 && j==0) f[i][j] = 1;
                else if(i==0) f[i][j] = f[i][j-1];
                else if(j==0) f[i][j] = f[i-1][j];
                else f[i][j] = f[i-1][j] + f[i][j-1];
            }
        return f[m-1][n-1];
    }
};