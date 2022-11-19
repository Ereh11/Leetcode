class Solution {
public:
    vector<int> dp;
    Solution() { dp.resize(31 , -1);}
    
    int fib(int n) {
        if(n <= 1) return n;
        if(~dp[n]) return dp[n];
        
        return dp[n] = fib(n - 1) + fib(n - 2);
    }
    
};