class Solution {
public:
    int dp[100000][2];
    int solve(int indx, int val_prev, string &s)
    {
        if(indx == s.size()) return 0;
        if(~dp[indx][val_prev]) return dp[indx][val_prev];
        
        
        if(val_prev) 
        {
            if(s[indx] == '0') return dp[indx][val_prev] = 1 + solve(indx + 1, 1, s);
            return dp[indx][val_prev] = solve(indx + 1, 1, s);
        }
        else
        {
            if(s[indx] == '0') return dp[indx][val_prev] = solve(indx + 1, 0, s);
            return dp[indx][val_prev] = min(solve(indx + 1, 1, s), 1 + solve(indx + 1, 0, s));
        }
        
    }
    int minFlipsMonoIncr(string s) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s);
    }
    
    /*
    
    
    
    
    */
};