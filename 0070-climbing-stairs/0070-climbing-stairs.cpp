class Solution {
public:
    int cnt = 0;
    int dp[46][46];
    int solve(int indx, int n)
    {
        if(indx >= n) {
            if(indx == n) return 1;
            return 0;
        }
        if(~dp[indx][n]) return dp[indx][n];
        return dp[indx][n] = (solve(indx + 1, n) + solve(indx + 2, n));
    }
    int climbStairs(int n) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, n);
    }
};