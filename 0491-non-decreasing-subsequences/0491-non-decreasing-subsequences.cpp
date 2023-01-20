class Solution {
public:
    set<vector<int>> ans;
    vector<int> tp;
    void solve(int indx, vector<int>& nums)
    {
        if(indx >= nums.size()) 
        {
            if(tp.size() > 1) 
                ans.insert(tp);
            return;
        }
       
        if(tp.empty() || (tp.back() <= nums[indx])) 
        {
            tp.push_back(nums[indx]), solve(indx + 1, nums);
            tp.pop_back();
        }
        
        solve(indx + 1, nums);        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        solve(0, nums);
        return vector(ans.begin(), ans.end());
    }
};