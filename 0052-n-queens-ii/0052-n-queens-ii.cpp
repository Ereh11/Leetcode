class Solution {
public:
    vector<string> Queens;
    int ans = 0;
    
    bool isValid(int &r, int &c, int &n)
    {
        for(int i = r; ~i ; i--)
            if(Queens[i][c] == 'Q') return false;
        
        for(int i = r, j = c ; i >= 0 && j >=0 ; i--, j--)
            if(Queens[i][j] == 'Q') return false;
        
        for(int i = r, j = c ; i >= 0 && j < n  ; i--, j++)
            if(Queens[i][j] == 'Q') return false;
        
        return true;
    }
    
    void solve(int row, int &n)
    {
        if(row == n)
        {
            int cnt = 0;
            for(auto& it: Queens)
                for(auto& indx: it) {
                    cnt += (indx == 'Q');
                }
            
            ans += (cnt == n);
            return;
        }
        
        for(int col = 0 ; col < n ; col++)
        {
            if(isValid(row, col, n))
            {
                Queens[row][col] = 'Q';
                solve(row + 1, n);
                Queens[row][col] = '.';  
            }
        }
    }
    
    int totalNQueens(int n) 
    {
        Queens.resize(n, string(n, '.'));
        
        solve(0, n);
        
        return ans;
    }
};