class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        if(!l1 || !l2) return l1 | l2;
        
        vector<vector<int> > f;
        for(int i=0;i<=l1;i++) f.push_back(vector<int>(l2+1));
        
        f[0][0] = 0;
        for(int i=1;i<=l1;i++) f[i][0] = i;
        for(int j=1;j<=l2;j++) f[0][j] = j;
        
        for(int i=1;i<=l1;i++)
            for(int j=1;j<=l2;j++) 
            {
                f[i][j] = INT_MAX;
                if(word1[i-1] == word2[j-1])
                    f[i][j] = f[i-1][j-1];
                
                f[i][j] = min(f[i][j], f[i-1][j-1]+1);
                f[i][j] = min(f[i][j], f[i][j-1]+1);
                f[i][j] = min(f[i][j], f[i-1][j]+1);
            }
            
        return f[l1][l2];
    }
};