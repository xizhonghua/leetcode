class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        const auto& m = dungeon;
        const auto h = m.size();
        const auto w = m[0].size();
        
        auto f = vector<vector<int>>(h+1, vector<int>(w+1, INT_MAX));
        
        f[h-1][w] = f[h][w] = 1;
        
        for(int y=h-1;y>=0;--y)
            for(int x=w-1;x>=0;--x)
                f[y][x] = max(1, min(f[y][x+1], f[y+1][x]) - m[y][x]);
                
        return f[0][0];
    }
};
