class Solution {
public:
    vector<vector<string>> res;
    vector<string> chessboard;
    bool check(int &r, int &c, int &n)
    {
        for(int i = r; i >= 0 ; i--)
            if(chessboard[i][c] == 'Q') return false;
        
        for(int i = r, j = c; i >= 0 && j >= 0; i--, j--)
            if(chessboard[i][j] == 'Q') return false;
        
        for(int i = r, j = c; i >= 0 && j < n; i--, j++)
            if(chessboard[i][j] == 'Q') return false;
        
        return true;
    }
    
    
    void solve(int row, int &n)
    {
        if(row == n) {
            res.push_back(chessboard);
            return;
        }
        
        for(int col = 0 ; col < n ; col++)
        {
            if(check(row, col, n))
            {
                chessboard[row][col] = 'Q';
                solve(row + 1, n);
                chessboard[row][col] = '.';
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) 
    {
        chessboard.resize(n);
        for(auto& it: chessboard)
            it = string(n, '.');
       
        solve(0, n);
        return res;
    }
};