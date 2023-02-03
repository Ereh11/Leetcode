class Solution {
public:
    int dp[101];
    int solve(int indx, vector<int>& v)
    {
        if(indx >= v.size()) return 0;
        if(~dp[indx]) return dp[indx];
        int op1 = v[indx] + solve(indx + 2, v);
        int op2 = solve(indx + 1, v);
        return dp[indx] = max(op1, op2);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums);
    }
};