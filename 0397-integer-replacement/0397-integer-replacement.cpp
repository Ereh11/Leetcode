class Solution {
public:
    long long solve(unordered_map<long long, long long> &dp, long long n)
    {
        if(n == 1)  
            return 0;
        if(dp.find(n) != dp.end())
            return dp[n];
        
       
        if(n & 1)
            return dp[n] = min(solve(dp, n - 1), solve(dp, n + 1)) + 1;
        else
            return dp[n] = solve(dp, (n >> 1)) + 1;
    }
    
    int integerReplacement(int n) {
        unordered_map<long long, long long> dp;
        
        return solve(dp, n);
        
    }
};