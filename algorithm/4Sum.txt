class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        set<vector<int> > h;
        vector<int> l;
        
        sort(num.begin(), num.end());
        
        
        int n = num.size();
        
        for(int i=0;i<n;i++)
        {   
            for(int j=i+1;j<n;j++)            
            {                
                for(int k=j+1;k<n;k++)
                {
                    int t = target - num[i] - num[j] - num[k];
                    
                    if(t < num[k]) continue;
                    
                   
                    if(!std::binary_search(num.begin()+k+1, num.end(), t)) continue;                                       
                    
            
                    vector<int> a;
                    a.push_back(num[i]);
                    a.push_back(num[j]);
                    a.push_back(num[k]);
                    a.push_back(t);
                    
                    if(!h.count(a))                    
                    {
                        ans.push_back(a);
                        h.insert(a);
                    }
                    
                }           
            }            
        }
        
        return ans;
        
    }
};