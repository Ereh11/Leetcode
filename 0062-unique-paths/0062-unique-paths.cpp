class Solution {
public:
    int dp[100][100];
    
    int solve(int n, int m, int r, int c)
    {
        if(r == n - 1 && c == m - 1) return 1;
        if(r < 0 || r >= n || c < 0 || c >= m) return 0;
        if(~dp[r][c]) return dp[r][c];
        
        return dp[r][c] = solve(n, m, r, c + 1) + solve(n, m, r + 1, c);
    }
    int uniquePaths(int m, int n) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(n, m, 0, 0);
    }
};