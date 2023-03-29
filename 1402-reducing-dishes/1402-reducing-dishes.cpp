class Solution {
public:
    int solve(int indx, int time, vector<int>& satisfaction, vector<vector<int>> &dp)
    {
        if(indx == satisfaction.size())
            return 0;
        
        if(~dp[indx][time])
            return dp[indx][time];
        
        int op1 = satisfaction[indx] * time + solve(indx + 1, time + 1, satisfaction, dp);
        int op2 = solve(indx + 1, time, satisfaction, dp);
        
        return dp[indx][time] = max(op1, op2);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int sz = satisfaction.size();
        vector<vector<int>> dp(sz + 1, vector<int>(sz + 1, -1));
        
        return solve(0 , 1 , satisfaction, dp);
    }
};


