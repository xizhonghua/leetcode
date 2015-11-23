class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.size()==0) return false;
        found = false;
        h = board.size();
        w = board[0].size();
        for(int i=0;i<w;i++)
            for(int j=0;j<h;j++) {
                dfs(board, word, 0, i, j);
                if(found) return true;
            }
        return false;
    }
    
    void dfs(vector<vector<char> > &board, const string& word, int d, int x, int y) {
        if(word[d] != board[y][x] || found) return;
        
        if(d==word.length()-1) {
            found = true;
            return;
        }
        
        char temp = board[y][x];
        board[y][x] = 0;
        if(x < w-1) dfs(board, word, d+1, x+1, y);
        if(x > 0) dfs(board, word, d+1, x-1, y);
        if(y < h-1) dfs(board, word, d+1, x, y+1);
        if(y > 0) dfs(board, word, d+1, x, y-1);
        board[y][x] = temp;
    }
private:
    bool found;
    int w;
    int h;
};
