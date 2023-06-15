class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, vector<int>> ump;
        vector<int> ans;

        for(int i = 0 ;i < nums.size(); i++) {
            ump[nums[i]].push_back(i);
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(!ump[target - nums[i]].empty() && nums[i] != target - nums[i])
            {
                ans.push_back(i);
                ans.push_back(ump[target - nums[i]][0]);
                break;
            }
            
            else if(ump[target - nums[i]].size() >= 2 && nums[i] == target - nums[i])
            {
                for(int j = 0 ; j < 2 ; j++) {
                    ans.push_back(ump[nums[i]][j]);
                }
                break;
            }
        }

        return ans;
    }
};