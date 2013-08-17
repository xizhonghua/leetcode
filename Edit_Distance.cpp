class Solution {
public:
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();       
        vector<vector<int> > f;        
        for(int i=0;i<=l1;i++)
        {
            f.push_back(vector<int>());
            f[i].reserve(l2+1);
            for(int j=0;j<=l2;j++)
            {
                f[0][j] = j;
                f[i][0] = i;
            }
        }
        for(int i=1;i<=l1;i++)
            for(int j=1;j<=l2;j++)
            {
                int d = 1;
                if(word1[i-1] == word2[j-1]) 
                    d = 0;
                
                f[i][j] = min(min(f[i][j-1], f[i-1][j]) + 1, f[i-1][j-1]+d);
                
            }
        
        return f[l1][l2];       
    }
};
    
    vector<vector<string>> partition(string s) {        
        vector<vector<string> > ans;
        vector<string> cur;
        
        p(s, 0, ans, cur);            
        
        return ans;
        
    }
};