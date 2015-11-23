class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::sort(num.begin(), num.end());
        
        int s = num.size();
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        
        for(int i=0;i<s;i++)
        {            
            for(int j=i+1;j<s;j++)
            {                
                for(int k=j+1;k<s;k++)
                {
                    int t = num[i] + num[j] + num[k];
                    if(abs(target - t) < m1)
                    {
                        m1 = abs(target - t);
                        m2 = t;
                    }
                }
               // if(num[i]+num[j]>target) break;
            }
            
            if(num[i]>target) break;
        }
        
        return m2;
        
    }
};