class Solution {
public:
    bool vis[11];
    set<vector<int>> uset;
    
    void solve(vector<int> & nums, int indx, vector<int> &ans)
    {
        for(int i = indx ; i < nums.size() ; i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                ans.push_back(nums[i]);
                
                if(uset.find(ans) == uset.end())
                    uset.insert(ans);
                
                solve(nums, i + 1, ans);
                ans.pop_back();
                vis[i] = 0;
            }
        }
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        solve(nums, 0, ans);
        
        vector<vector<int>> res;
        
        for(auto& it: uset)
            res.push_back(it);
        
        ans.empty();
        res.push_back(ans);
        return res;
    }
};