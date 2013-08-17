class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<vector<int> >& t = triangle;        
        int size = t.size();
        
        for(int i=1;i<size;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0)
                {
                    t[i][j] += t[i-1][j];
                }
                else if(j==i)
                {
                    t[i][j] += t[i-1][j-1];
                }
                else
                {
                    t[i][j] += min(t[i-1][j], t[i-1][j-1]);
                }
            }
        }
        
        int sum = t[size-1][0];
        for(int j=0;j<size;j++)
        {
            sum = min(sum, t[size-1][j]);
        }
        
        return sum;
    }
};