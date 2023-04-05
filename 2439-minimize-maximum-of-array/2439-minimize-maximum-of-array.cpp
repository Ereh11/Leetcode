class Solution {
public:
    bool isValid(vector<int>& nums, int mid)
    {
        if (nums[0] > mid) 
            return false;
        
        long long prev = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            
            long long decreaseValue = mid - prev;
            prev = nums[i] - decreaseValue;
            
            if (prev > mid) 
                return false;
        }
        
        return true;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        
        long long l = 0, r = *max_element(nums.begin(), nums.end()), mid, ans = 0;
        
        while(l <= r)
        {
            mid = ((l + r) >> 1);
            
            if(isValid(nums, mid))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        
        return ans;
    }
};

 