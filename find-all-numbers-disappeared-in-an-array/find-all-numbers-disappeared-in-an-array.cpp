class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0 ;i < nums.size(); i++)
            nums[(nums[i] - 1) % n] += n;
        
        
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] <= n) {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};
/*
*/