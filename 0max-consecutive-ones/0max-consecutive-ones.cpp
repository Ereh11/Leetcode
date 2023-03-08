class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0, cntones = 0;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i])
                cntones++;
            else
                cntones = 0;
            
            mx = max(mx, cntones);
        }
        
        return mx;
    }
};