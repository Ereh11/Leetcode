class Solution {
public:
    void solve(int res, int indx, int &ans,int &MxOR, vector<int>& nums)
    {
        if(indx == nums.size())
        {
            ans += (res == MxOR);
            return;
        }

        
        solve(res | nums[indx], indx + 1, ans, MxOR, nums);
        
        solve(res, indx + 1, ans, MxOR, nums);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int MxOR = 0, ans = 0;
        
        for(auto& it: nums) {
            MxOR |= it;
        }
        
        solve(0, 0, ans, MxOR, nums);
        
        return ans;
    }
};