class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        this->rows = vector<vector<int>>(10, vector<int>(10));
        this->cols = vector<vector<int>>(10, vector<int>(10));
        this->boxes = vector<vector<int>>(10, vector<int>(10));
        
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                const char c = board[i][j];
                
                if(c!='.')
                {
                    int n = c-'0';
                    rows[i][n] = 1;
                    cols[j][n] = 1;
                    int bx = j / 3;
                    int by = i / 3;
                    boxes[by*3+bx][n] = 1;
                }
            }
        
        found = false;
        
        dfs(board, 0, 0);
    }
    
private:
    void dfs(vector<vector<char> > &board, int x, int y)
    {
        if(x==-1 && y==-1)
        {
            found = true;
            return;
        }
        
        if(found) return;
        
        int nx = -1, ny = -1;
        
        if(x==8)
        {
            if(y < 8)
            {
                nx = 0;
                ny = y+1;
            }
        }
        else
        {
            nx = x+1;
            ny = y;
        }
        
        
        
        if(board[y][x]=='.')
        {
            for(int i=1;i<=9;i++)
            {
                int bx = x/3;
                int by = y/3;
                int box_key = by*3+bx;
                
                if(rows[y][i] == 0 && cols[x][i] == 0 && boxes[box_key][i] == 0)
                {
                    rows[y][i] = 1;
                    cols[x][i] = 1;
                    boxes[box_key][i] = 1;
                    
                    board[y][x] = i+'0';
                    
                    dfs(board, nx, ny);
                    
                    if(found) return;
                    
                    board[y][x] = '.';
                    
                    rows[y][i] = 0;
                    cols[x][i] = 0;
                    boxes[box_key][i] = 0;
                }
            }
        } else {
            dfs(board, nx, ny);
        }
    }
    
    vector<vector<int>> rows, cols, boxes;
    bool found;
};
