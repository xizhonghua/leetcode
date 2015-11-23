class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        set<vector<int> > s;
        
        sort(num.begin(), num.end());
        
        int size = num.size();
        for(vector<int>::iterator it1=num.begin(); it1!=num.end(); ++it1)
        {
            vector<int>::iterator it2 = it1;
            vector<int>::iterator it3;
            it2++;
            for(; it2!=num.end(); ++it2)
            {
                int l = 0 - *it1 - *it2;
                it3 = it2;                
                it3 = find (++it3, num.end(), l);
                if(it3 != num.end())
                {
                    vector<int> a;
                    a.push_back(*it1);
                    a.push_back(*it2);
                    a.push_back(*it3);
                        
                    if(!s.count(a))
                    {
                        ans.push_back(a);
                        s.insert(a);
                    }
                }
            }
        }
        
        return ans;
    }
};