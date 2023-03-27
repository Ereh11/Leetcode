class Solution {
public:
    
    bool isValid(int r, int c, int &n, int &m) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }
    
    int solve(int r, int c, int &n, int &m, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if(!isValid(r, c, n, m)) 
            return 100007;
        
        if(r == n - 1 && c == m - 1) 
            return grid[r][c];
        
        if(~dp[r][c]) 
            return dp[r][c];
    
        int op1 = grid[r][c] + solve(r,  c + 1, n, m, grid, dp);
        int op2 = grid[r][c] + solve(r + 1,  c, n, m, grid, dp);
        
        return dp[r][c] = min(op1, op2);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(201, vector<int>(201, -1));
        
        return solve(0, 0, n, m, grid, dp);
    }
};