class Solution {
public:
    vector<vector<int>> dp;
    int solve(int indx1, int indx2, string &s1, string &s2)
    {
        if(indx1 == s1.size() || indx2 == s2.size()) return 0;
        else if(~dp[indx1][indx2]) return dp[indx1][indx2];
        
        if(s1[indx1] == s2[indx2]) return 1 + solve(indx1 + 1, indx2 + 1, s1, s2);
        else return dp[indx1][indx2] = max(solve(indx1 + 1, indx2, s1, s2), solve(indx1, indx2 + 1, s1, s2));
    }
    int longestCommonSubsequence(string s1, string s2) 
    {
        dp.resize(1001, vector<int>(1001, -1));
        return solve(0, 0, s1, s2);
    }
};