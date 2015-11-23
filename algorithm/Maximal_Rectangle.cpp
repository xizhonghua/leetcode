class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int r = matrix.size();
        if(r == 0) return 0;
        int c = matrix[0].size();
        
        vector<vector<int> > f;
        
        for(int i=0;i<r;i++)
        {
            f.push_back(vector<int>(c+1));
            for(int j=0;j<c;j++)
            {
                if(j==0) f[i][j] = matrix[i][j] == '1' ? 1 : 0;
                else f[i][j] = matrix[i][j] == '1' ? f[i][j-1]+1 : 0;
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++) {
                int len = INT_MAX;
                for(int k=i;k<r;k++) {
                    len = min(len, f[k][j]);
                    if(len == 0) break;
                    ans = max(len*(k-i+1), ans);
                }
            }
            
        return ans;
    }
};