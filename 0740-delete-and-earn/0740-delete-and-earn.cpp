class Solution {
public:
    vector<int> dp;
    
    int solve(int num, vector<int>& frq)
    {
        if(num == 0) return 0;
        if(~dp[num]) return dp[num];
        
        int skip = solve(num - 1, frq);
        int take = num * frq[num] + ((num >= 2) ? solve(num - 2, frq) : 0);
        return dp[num] = max(skip, take);
    }
    
    int deleteAndEarn(vector<int>& nums) 
    {
        int mx = *max_element(nums.begin(), nums.end());
        
        vector<int> frq(mx + 1);
        dp.resize(mx + 1, -1);
        for(auto& it: nums) frq[it]++;
    
        return solve(mx, frq);
    }
};

/*
*/