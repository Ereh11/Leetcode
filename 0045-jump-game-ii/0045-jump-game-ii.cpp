class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, step = 0, end = 0;
        
        for(int i = 0 ; i < nums.size() - 1; i++)
        {
            step = max(step, i + nums[i]);
            if(i == end)
                ans++, end = step;
        }
        
        return ans;
    }
};