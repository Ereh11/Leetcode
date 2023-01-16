class Solution {
public:
    int dp[1000];
    int solve(int indx, vector<int>& cost)
    {
        if(indx >= cost.size()) return 0;
        if(~dp[indx]) return dp[indx];
        return dp[indx] = cost[indx] + min(solve(indx + 2, cost), solve(indx + 1, cost));
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        memset(dp, -1, sizeof(dp)); int a = solve(0, cost);
        memset(dp, -1, sizeof(dp)); int b = solve(1, cost);
        return min(a, b);
    }
};