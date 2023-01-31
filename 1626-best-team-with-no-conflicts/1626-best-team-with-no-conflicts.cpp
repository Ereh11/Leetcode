class Solution {
public:
    int dp[1001][1001];
    int solve(int indx, int prev, vector<pair<int, int>> &v)
    {
        if(indx == v.size()) return 0;
        int op1 = 0, op2 = 0;
        if(~dp[indx][prev + 1]) return dp[indx][prev + 1];
        
        if(prev == -1 || v[prev].second <= v[indx].second) 
           op1 = v[indx].second + solve(indx + 1, indx, v);  
        
        op2 = solve(indx + 1, prev, v);
        
        return dp[indx][prev + 1] = max(op1, op2);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> v;
        memset(dp, -1, sizeof(dp));
        
        for(int i = 0 ; i < scores.size(); i++) v.push_back({ages[i], scores[i]});
        sort(v.begin(), v.end());
        
        return solve(0,  -1, v);
    }
};
