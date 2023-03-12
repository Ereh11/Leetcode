class Solution {
public:
    
    bool vis[7];
    vector<vector<int>> res;
    void solve(vector<int>& nums, vector<int> &ans)
    {
        for(int i = 0; i < nums.size() ; i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                ans.push_back(nums[i]);
                
                if(ans.size() == nums.size())
                    res.push_back(ans);
                
                solve(nums, ans);
                
                vis[i] = 0;
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans;
        solve(nums, ans);
        return res;
    }
};