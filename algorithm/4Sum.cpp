class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        set<vector<int> > h;
        vector<int> l;
        
        sort(num.begin(), num.end());
        
        
        int n = num.size();
        
        if(target > 0 && target > 4*num[n-1]) return ans;
        if(target < 0 && target < 4*num[0]) return ans;
        
        for(int i=0;i<n;i++)
        {   
            for(int j=i+1;j<n;j++)            
            {                
                for(int k=j+1;k<n;k++)
                {
                    int t = target - num[i] - num[j] - num[k];
                    
                    if(t < num[k]) continue;
                   
                    if(!std::binary_search(num.begin()+k+1, num.end(), t)) continue;                                       
                    
            
                    auto a = vector<int>{num[i], num[j], num[k], t};
                    
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
