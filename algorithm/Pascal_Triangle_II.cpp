class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       class Solution {
public:
    vector<int> getRow(int rowIndex) {        
        
        vector<int> last;
        
        for(int i=0;i<=rowIndex;i++)
        {
            vector<int> row;
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                {
                    row.push_back(1);
                }
                else
                {
                    row.push_back(last[j-1]+last[j]);
                }                
            }
            last = row;
        }
        
        return last;
        
    }
};
    }
};'