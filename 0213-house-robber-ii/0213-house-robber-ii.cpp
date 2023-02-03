class Solution {
public:
    int dp[101][1001];
   
    int solve(int indx, int lt,vector<int>& v)
    {
        if(indx >= v.size()) return 0;
        if(~dp[indx][lt]) return dp[indx][lt];
        int op1, op2;
        if(!indx) 
            op1 = max(v[indx] + solve(indx + 2, 0, v), solve(indx + 1, v.back(), v));
        else 
            op1 = ((indx == v.size() - 1) ? lt : v[indx]) + solve(indx + 2, lt, v);
        
        op2 = solve(indx + 1, lt, v);
        return dp[indx][lt] = max(op1, op2);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums.back(), nums);
    }
};