class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = matrix.size()-1;
        
        int p;
        
        while(true)
        {
            p = (l+r)/2;
            
            int t = matrix[p][0];
             
            if(r-l<=1)
            {
                p = t > target ? r : l;
                break;
            }
                    
            
            if(t > target)
                r = p;
            else
                l = p;
        }
        
        for(int i=0;i<matrix[p].size();i++)
        {
            if(matrix[p][i] == target) return true;
        }
        
        if(p<matrix.size()-1)
        {
            for(int i=0;i<matrix[p+1].size();i++)
        {
            if(matrix[p+1][i] == target) return true;
        } 
        }
        
        return false;
    }
};