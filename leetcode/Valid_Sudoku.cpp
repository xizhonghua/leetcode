class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        
        for(int i=0;i<9;i++)
        {
            set<char> r,c;
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    if(r.count(board[i][j])) return false;
                    r.insert(board[i][j]);
                }
                if(board[j][i] != '.')
                {
                    if(c.count(board[j][i])) return false;
                    c.insert(board[j][i]);
                }
            }
        }
        
        for(int p=0;p<3;p++)
            for(int q=0;q<3;q++)
            {
                set<char> b;
                for(int i=0;i<3;i++)
                    for(int j=0;j<3;j++)
                    {
                        int x = p*3+i;
                        int y = q*3+j;
                        
                        if(board[y][x] != '.')
                        {
                            if(b.count(board[y][x])) return false;
                            b.insert(board[y][x]);
                        }
                    }
            }
        return true;
    }
};