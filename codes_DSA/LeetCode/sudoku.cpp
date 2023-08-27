class Solution {
public:

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board)
    {
        char dot = '.';
        int n=board[0].size();
        int m=board.size();
        for(int i=0; i<m ;i++)
        {
            for(int j=0; j<n ; j++)
            {
                if(board[i][j]==dot)
                {
                    for(char c='1' ; c<='9' ; c++)
                    {
                        if(isValid(board,i,j,c))
                        {
                            board[i][j]=c;
                            if(solve(board)==true) return true;
                            else board[i][j]=dot;
                        }
                    }return false;
                }
            }
        }return true;
    }

    bool isValid(vector<vector<char>>& board,int i,int j,char c)
    {
        for(int i2=0; i2<9; i2++)
        {
            if(board[i][i2]==c) return false;
            if(board[i2][j]==c) return false;
            if(board[3*(i/3)+i2/3][3*(j/3)+i2%3]== c)
            return false;
        }
        return true;        
    }

};