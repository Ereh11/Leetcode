class Solution {
public:
    int res = 0;
    void solve(vector<int>& nums, vector<int> ans, int indx)
    {
        if(indx == nums.size())
        {
            int Xor = 0;
            for(auto& it: ans)  Xor ^=  it;
            
            res += Xor;
            return;
        }
        
        ans.push_back(nums[indx]);
        solve(nums, ans, indx + 1);
        ans.pop_back();
        solve(nums, ans, indx + 1);    
    }
    
    int subsetXORSum(vector<int>& nums) {
        
        vector<int> ans;
        
        solve(nums, ans, 0);
        
        return res;
    }
};