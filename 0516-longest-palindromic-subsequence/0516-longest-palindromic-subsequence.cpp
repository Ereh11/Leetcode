class Solution {
public:
    
    int solve(int p1, int p2, string &s, vector<vector<int>> &dp)
    {
        if(dp[p1][p2] != 0)
            return dp[p1][p2];
        
        if(p1 > p2)
            return 0;
        
        if(p1 == p2)
            return 1;
        
        if(s[p1] == s[p2])
            return dp[p1][p2] = solve(p1 + 1, p2 - 1, s, dp) + 2;
        else
            return dp[p1][p2] = max(solve(p1 + 1, p2, s, dp), solve(p1, p2 - 1, s, dp));
        
        return dp[p1][p2];
    }
    
    int longestPalindromeSubseq(string s) {
        int sz = s.size();
        vector<vector<int>> dp(sz + 1, vector<int>(sz + 1));
        
        return solve(0, sz - 1, s, dp);
    }
};