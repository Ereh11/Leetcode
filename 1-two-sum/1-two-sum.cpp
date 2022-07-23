class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> ump; vector<int> ans;
        for(auto& it: nums) ump[it]++;
        for(int i = 0; i< nums.size(); i++)
        {
            ump[nums[i]]--;
             if(ump[target-nums[i]])  {
                 ans.push_back(i);
                 for(int j = i + 1; j < nums.size(); j++)
                     if(target-nums[i] == nums[j])
                     {
                          ans.push_back(j);
                         return ans;
                     }
             }
            ump[nums[i]]++;
        }
        return ans;
    }
};