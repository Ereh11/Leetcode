class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> frq(mx + 1);
        vector<int> ans;
        int indx = 0;
        
        for(auto& it: nums)     frq[it]++;
        
        for(int i = 1; i <= mx; i++)
        {
            while(--frq[i] >= 0)
            {
                if(i == target) {
                    ans.push_back(indx);
                }
                indx++;
            }
        }
        
        return ans;
    }
};